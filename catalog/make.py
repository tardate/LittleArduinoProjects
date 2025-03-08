#!/usr/bin/env python
""" A script to build the catalog.json file.

* Collates all project metadata into a simple JSON file used by the catalog index.
* Generates a data file used by jekyll page generation.
    * These are currently two separate files because of the different access pattern requirements for each
* Generates thumbnails for gallery view

This should be re-run after adding a project or updating any project metadata.

"""
from sys import argv
import os
import re
import json
import fnmatch
import shutil
import subprocess
from datetime import datetime
from xml.etree import ElementTree
from xml.dom import minidom
from PIL import Image
from PIL import ImageOps


def write_pretty_xml(doc, file):
    print("Writing {}..".format(file))
    pretty_xml = minidom.parseString(
        ElementTree.tostring(doc, 'utf-8')
    ).toprettyxml(indent="  ")
    with open(file, 'w') as f:
        f.write(pretty_xml)


def write_pretty_json(doc, file, verbose=True):
    if verbose:
        print("Writing {}..".format(file))
    with open(file, 'w') as f:
        json.dump(doc, f, indent=4)


def remove_orientation(image):
    exif = image.getexif()
    for tag in exif.keys():
        if tag != 0x0112:  # only keep orientation tag
            exif[tag] = None
            del exif[tag]
    image.info['exif'] = exif.tobytes()
    return ImageOps.exif_transpose(image)


def update_thumbnail(file_name):
    root, ext = os.path.splitext(file_name)
    new_file_name = f'{root}_thumbnail{ext}'
    if os.path.exists(new_file_name):
        return

    image = remove_orientation(Image.open(file_name))
    new_size = (60, 60)
    image.resize(new_size).save(new_file_name)


class Catalog(object):
    """ Helper class for building the catalog from metadata files. """

    def __init__(self):
        self.script_root = os.path.dirname(os.path.abspath(__file__))
        self.collection_root = os.path.abspath(os.path.join(self.script_root, '..'))
        self.catalog_json = os.path.join(self.collection_root, 'catalog', 'catalog.json')
        self.categories_json = os.path.join(self.collection_root, 'catalog', 'categories.json')
        self.catalog_atom = os.path.join(self.collection_root, 'catalog', 'atom.xml')
        self.data_project_json = os.path.join(self.collection_root, '_data', 'projects.json')
        self.data_catalog_json = os.path.join(self.collection_root, '_data', 'catalog.json')
        self.catalog_sitemap = os.path.join(self.collection_root, 'catalog', 'sitemap.xml')
        self.settings

    @property
    def settings(self):
        if not hasattr(self, '_settings'):
            config_path = os.path.join(self.script_root, 'make.conf')
            if not os.path.exists(config_path):
                template_path = os.path.join(self.script_root, 'make.conf.template')
                if os.path.exists(template_path):
                    print(f"Config file not found. Copying from template: {template_path}")

                    shutil.copy(template_path, config_path)
                else:
                    raise FileNotFoundError(f"Template config file not found: {template_path}")
            with open(config_path, 'r') as f:
                self._settings = json.load(f)
        return self._settings

    @property
    def site_base_url(self):
        return self.settings['site_base_url']

    def metadata_files(self):
        """ Returns the collection of catalog metadata files. """
        matches = []
        for root, dirnames, filenames in os.walk(self.collection_root):
            for filename in fnmatch.filter(filenames, '.catalog_metadata'):
                matches.append(os.path.join(root, filename))
        return matches

    def metadata(self):
        """ Returns the metadata based on .catalog_metadata files. """

        def load_data(filename):
            data = json.load(open(filename, 'r'))
            data['original_relative_path'] = data['relative_path']
            data['relative_path'] = data['relative_path'].lower()
            return data

        if getattr(self, '_metadata', None) is None:
            data = map(lambda filename: load_data(filename), self.metadata_files())
            self._metadata = sorted(data, key=lambda k: -int(k['id'].replace('#', '')))
        return self._metadata

    def _get_project_file(self, relative_path, name='.catalog_metadata'):
        return os.path.join(self.collection_root, relative_path, name)

    def _max_id(self):
        with open(self.catalog_json, 'r') as f:
            catalog_data = json.load(f)
        return max(int(data['id'].replace('#', '')) for data in catalog_data if 'id' in data)

    def _max_updated_at(self):
        with open(self.catalog_json, 'r') as f:
            catalog_data = json.load(f)
        latest_updated_at = max(
            datetime.strptime(data['updated_at'], "%Y-%m-%dT%H:%M:%SZ")
            for data in catalog_data if 'updated_at' in data
        )
        return latest_updated_at.strftime("%Y-%m-%dT%H:%M:%SZ")

    def _verify_catalog_metadata(self):
        """ Command: verifies all metadata files have an id, the correct relative path, and updated_at. """
        max_id = self._max_id()
        for filename in self.metadata_files():
            data = json.load(open(filename, 'r'))
            if 'updated_at' not in data:
                data['updated_at'] = datetime.utcnow().strftime("%Y-%m-%dT%H:%M:00Z")
            if 'created_at' not in data:
                data['created_at'] = data['updated_at']
            data['relative_path'] = os.path.relpath(os.path.dirname(filename), self.collection_root)
            if 'id' not in data:
                max_id += 1
                data['id'] = f'#{max_id}'
            write_pretty_json(data, filename, verbose=False)
            # verify the id referenced in the README is correct
            readme_file = self._get_project_file(data['relative_path'], 'README.md')
            if os.path.exists(readme_file):
                with open(readme_file, 'r') as file:
                    lines = file.readlines()

                if lines and lines[0].startswith('#'):
                    parts = lines[0].split(' ', 2)
                    if len(parts) > 1 and parts[1] != data['id']:
                        lines[0] = f"# {data['id']} {parts[2]}" if len(parts) > 2 else f"# {data['id']}\n"

                        with open(readme_file, 'w') as file:
                            file.writelines(lines)

    def _generate_catalog(self):
        """ Command: re-writes the catalog file from catalog_metadata. """
        write_pretty_json(self.metadata(), self.catalog_json)
        write_pretty_json(self.metadata(), self.data_catalog_json)

    def _generate_categories(self):
        """ Command: re-writes the categories file from catalog_metadata. """

        def category_data():
            result = []
            for item in self.metadata():
                for term in item['categories'].split(','):
                    category = term.strip()
                    if category not in result:
                        result.append(category)
            return sorted(result, key=lambda s: s.lower())

        write_pretty_json(category_data(), self.categories_json)

    def _generate_project_data(self):
        def project_data():
            result = {}
            for item in self.metadata():
                result['/{}/'.format(item['relative_path'])] = {
                    "id": int(item['id'].replace('#', '')),
                    "title": item['name'],
                    "summary": item['description'],
                    "tags": item['categories'].split(', ')
                }
            return result

        write_pretty_json(project_data(), self.data_project_json)

    def _generate_atom_feed(self):
        """ Command: re-writes the atom feed file from catalog_metadata. """

        root = ElementTree.Element('feed', xmlns='http://www.w3.org/2005/Atom')
        root.set('xmlns:g', 'http://base.google.com/ns/1.0')
        ElementTree.SubElement(root, "title").text = self.settings['site_title']
        ElementTree.SubElement(root, "subtitle").text = self.settings['site_subtitle']
        ElementTree.SubElement(root, "link", href=f"{self.site_base_url}catalog/atom.xml", rel="self")
        ElementTree.SubElement(root, "link", href=self.site_base_url)
        ElementTree.SubElement(root, "id").text = self.site_base_url
        ElementTree.SubElement(root, "icon").text = f"{self.site_base_url}catalog/assets/images/favicon-32x32.png"
        ElementTree.SubElement(root, "logo").text = f"{self.site_base_url}catalog/assets/images/favicon-32x32.png"
        ElementTree.SubElement(root, "updated").text = self._max_updated_at()

        author = ElementTree.SubElement(root, "author")
        ElementTree.SubElement(author, "name").text = "Paul Gallagher"
        ElementTree.SubElement(author, "email").text = "gallagher.paul@gmail.com"
        ElementTree.SubElement(author, "uri").text = "https://github.com/tardate"

        for entry in self.metadata():
            url = '{}{}/'.format(self.site_base_url, entry['relative_path'])
            asset_path = '{}/assets'.format(entry['relative_path'])
            hero_image_file = '{}_build.jpg'.format(entry['relative_path'].split('/')[-1])

            hero_image_path = self._get_project_file(asset_path, hero_image_file)
            if os.path.exists(hero_image_path):
                hero_image_url = '{}{}/{}'.format(
                    self.site_base_url,
                    asset_path,
                    hero_image_file
                )
                update_thumbnail(hero_image_path)
            else:
                hero_image_url = None

            doc = ElementTree.SubElement(root, "entry")
            ElementTree.SubElement(doc, "id").text = url
            ElementTree.SubElement(doc, "link", href=url)
            if hero_image_url:
                ElementTree.SubElement(doc, "g:image_link").text = hero_image_url
            ElementTree.SubElement(doc, "updated").text = entry['updated_at']
            ElementTree.SubElement(doc, "title").text = u'{} {}'.format(entry['id'], entry['name'])
            ElementTree.SubElement(doc, "summary").text = entry['description']

            content = ElementTree.Element('div')
            ElementTree.SubElement(content, 'p').text =  entry['description']
            if hero_image_url:
                ElementTree.SubElement(content, 'img', src=hero_image_url)
            ElementTree.SubElement(doc, "content", type='html').text = ElementTree.tostring(content, encoding='utf-8').decode()

            for category in entry['categories'].split(', '):
                ElementTree.SubElement(doc, 'category', term=category)

        write_pretty_xml(root, self.catalog_atom)

    def _generate_sitemap(self):
        """ Command: re-writes the atom feed file from catalog_metadata. """

        root = ElementTree.Element('urlset', xmlns='http://www.sitemaps.org/schemas/sitemap/0.9')

        for entry in self.metadata():
            url = '{}{}/'.format(self.site_base_url, entry['relative_path'])
            doc = ElementTree.SubElement(root, 'url')
            ElementTree.SubElement(doc, 'loc').text = url

        write_pretty_xml(root, self.catalog_sitemap)

    def _ensure_asset_backup_exists(self, relative_path):
        backup_root = self.settings['asset_backup_root']
        if not backup_root:
            print("asset_backup_root setting is not set. Skipping asset backup path creation.")
            return

        backup_path = os.path.join(backup_root, relative_path)
        if not os.path.exists(backup_path):
            print(f"Creating backup path: {backup_path}")
            asset_backup_template_path = os.path.join(self.script_root, 'templates', 'asset-backup')
            if os.path.exists(asset_backup_template_path):
                shutil.copytree(asset_backup_template_path, backup_path)
                print(f"Copied assets to backup folder")
            for subfolder in ['hires', 'trash']:
                subfolder_path = os.path.join(backup_path, subfolder)
                if not os.path.exists(subfolder_path):
                    os.makedirs(subfolder_path)
                    print(f"Created backup {subfolder} path: {subfolder_path}")

    def _ensure_asset_backup_paths_exist(self):
        backup_root = self.settings['asset_backup_root']
        if not backup_root:
            print("asset_backup_root setting is not set. Skipping asset backup path creation.")
            return

        for entry in self.metadata():
            self._ensure_asset_backup_exists(entry['original_relative_path'])

    def _update_readme(self):
        readme_path = os.path.join(self.collection_root, 'README.md')
        metadata = self.metadata()
        total_projects = len(metadata)
        latest_project = metadata[0]

        with open(readme_path, 'r') as f:
            lines = f.readlines()

        # Update the total number of projects in the first line
        if lines:
            lines[0] = re.sub(r'\d+', str(total_projects), lines[0], count=1)

        if len(lines) > 2:
            # Add the latest project details at the top of the README
            lines[2] = "> Latest addition:sparkles: [{}](./{}) - {}\n".format(
                latest_project['name'], latest_project['original_relative_path'], latest_project['description']
            )

        with open(readme_path, 'w') as f:
            f.writelines(lines)

    def _get_project_modified_datetime(self, relative_path, filename='.catalog_metadata'):
        relative_filename = os.path.join(relative_path, filename)
        git_data = subprocess.check_output(['git', 'log', '-n', '1', '--date=unix', relative_filename])
        ts_match = re.search(r'Date:\s+(?P<ts>\d+)', str(git_data), re.MULTILINE)
        if ts_match:
            return datetime.utcfromtimestamp(int(ts_match.group('ts')))
        else:
            indicative_file = self._get_project_file(relative_path, filename)
            return datetime.utcfromtimestamp(os.path.getmtime(indicative_file))

    def _create_from_text_template(self, template_name, destination_path, substitutions):
        template_path = os.path.join(self.script_root, 'templates', template_name)
        if os.path.exists(template_path):
            with open(template_path, 'r') as template:
                template_content = template.read()
                for key, value in substitutions.items():
                    template_content = template_content.replace(f'{{{key}}}', value)
                with open(destination_path, 'w') as destination:
                    destination.write(template_content)
                    print(f"Created: {destination_path}")

    def new(self):
        """ Command: create a new project directory. """
        if len(argv) < 3:
            print("Usage: make.py new <project_folder>")
            return

        project_folder = argv[2]
        project_name = os.path.basename(project_folder)
        subfolder = self.settings.get('project_subfolder', None)
        if subfolder:
            project_path = os.path.join(self.collection_root, subfolder, project_folder)
        else:
            project_path = os.path.join(self.collection_root, project_folder)

        relative_path = os.path.relpath(project_path, self.collection_root)

        if os.path.exists(project_path):
            print(f"Project folder already exists: {project_path}")
            return

        os.makedirs(project_path)
        print(f"Created project folder: {project_path}")

        metadata = {
            "name": project_name,
            "description": "",
            "categories": "",
            "relative_path": relative_path
        }

        metadata_file = os.path.join(project_path, '.catalog_metadata')
        write_pretty_json(metadata, metadata_file)
        print(f"Created metadata file: {metadata_file}")

        substitutions = {
            'project_name': project_name,
            'relative_path': relative_path
        }
        self._create_from_text_template('README.md', os.path.join(project_path, 'README.md'), substitutions)
        self._create_from_text_template('template.ino', os.path.join(project_path, f'{project_name}.ino'), substitutions)

        template_fzz = os.path.join(self.script_root, 'templates', 'template.fzz')
        if os.path.exists(template_fzz):
            fzz_file = os.path.join(project_path, f'{project_name}.fzz')
            shutil.copy(template_fzz, fzz_file)
            print(f"Created: {fzz_file}")

        assets_template_path = os.path.join(self.script_root, 'templates', 'assets')
        project_assets_path = os.path.join(project_path, 'assets')
        if os.path.exists(assets_template_path):
            shutil.copytree(assets_template_path, project_assets_path)
            print(f"Copied assets to project folder")
        else:
            os.makedirs(project_assets_path)
            print(f"Created: {project_assets_path}")

        self._ensure_asset_backup_exists(relative_path)

    def rebuild(self):
        """ Command: rebuild catalog assets from metadata. """
        self._verify_catalog_metadata()
        self._generate_catalog()
        self._generate_categories()
        self._generate_project_data()
        self._generate_atom_feed()
        self._generate_sitemap()
        self._update_readme()
        self._ensure_asset_backup_paths_exist()

if __name__ == '__main__':
    catalog = Catalog()
    operation = argv[1] if len(argv) > 1 else 'rebuild'
    getattr(catalog, operation)()
