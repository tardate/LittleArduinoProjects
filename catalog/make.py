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


def write_pretty_json(doc, file):
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
            if 'updated_at' not in data:
                data['updated_at'] = datetime.utcnow().strftime("%Y-%m-%dT%H:%M:00Z")
                write_pretty_json(data, filename)
            data['original_relative_path'] = data['relative_path']
            data['relative_path'] = data['relative_path'].lower()
            return data

        if getattr(self, '_metadata', None) is None:
            data = map(lambda filename: load_data(filename), self.metadata_files())
            self._metadata = sorted(data, key=lambda k: -int(k['id'].replace('#', '')))
        return self._metadata

    def get_project_file(self, relative_path, name='.catalog_metadata'):
        return os.path.join(self.collection_root, relative_path, name)

    def generate_catalog(self):
        """ Command: re-writes the catalog file from catalog_metadata. """
        write_pretty_json(self.metadata(), self.catalog_json)
        write_pretty_json(self.metadata(), self.data_catalog_json)

    def generate_project_data(self):
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

    def generate_atom_feed(self):
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
        ElementTree.SubElement(root, "updated").text = datetime.utcnow().strftime("%Y-%m-%dT%H:%M:%SZ")

        author = ElementTree.SubElement(root, "author")
        ElementTree.SubElement(author, "name").text = "Paul Gallagher"
        ElementTree.SubElement(author, "email").text = "gallagher.paul@gmail.com"
        ElementTree.SubElement(author, "uri").text = "https://github.com/tardate"

        for entry in self.metadata():
            url = '{}{}/'.format(self.site_base_url, entry['relative_path'])
            asset_path = '{}/assets'.format(entry['relative_path'])
            hero_image_file = '{}_build.jpg'.format(entry['relative_path'].split('/')[-1])

            hero_image_path = self.get_project_file(asset_path, hero_image_file)
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

    def generate_sitemap(self):
        """ Command: re-writes the atom feed file from catalog_metadata. """

        root = ElementTree.Element('urlset', xmlns='http://www.sitemaps.org/schemas/sitemap/0.9')

        for entry in self.metadata():
            url = '{}{}/'.format(self.site_base_url, entry['relative_path'])
            doc = ElementTree.SubElement(root, 'url')
            ElementTree.SubElement(doc, 'loc').text = url

        write_pretty_xml(root, self.catalog_sitemap)

    def ensure_asset_backup_paths_exist(self):
        backup_root = self.settings['asset_backup_root']
        if not backup_root:
            print("asset_backup_root setting is not set. Skipping asset backup path creation.")
            return

        for entry in self.metadata():
            backup_path = os.path.join(backup_root, entry['original_relative_path'])
            if not os.path.exists(backup_path):
                print(f"Creating backup path: {backup_path}")
                os.makedirs(backup_path)

    def rebuild(self):
        """ Command: rebuild catalog assets from metadata. """
        self.generate_catalog()
        self.generate_project_data()
        self.generate_atom_feed()
        self.generate_sitemap()
        self.update_readme()
        self.ensure_asset_backup_paths_exist()

    def update_readme(self):
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

    def fix_publication_dates(self):
        for filename in self.metadata_files():
            data = json.load(open(filename, 'r'))
            if 'updated_at' not in data:
                data['updated_at'] = self.get_project_modified_datetime(data['relative_path']).strftime("%Y-%m-%dT%H:%M:%SZ")
                write_pretty_json(data, filename)

    def get_project_modified_datetime(self, relative_path, filename='.catalog_metadata'):
        relative_filename = os.path.join(relative_path, filename)
        git_data = subprocess.check_output(['git', 'log', '-n', '1', '--date=unix', relative_filename])
        ts_match = re.search(r'Date:\s+(?P<ts>\d+)', str(git_data), re.MULTILINE)
        if ts_match:
            return datetime.utcfromtimestamp(int(ts_match.group('ts')))
        else:
            indicative_file = self.get_project_file(relative_path, filename)
            return datetime.utcfromtimestamp(os.path.getmtime(indicative_file))


if __name__ == '__main__':
    catalog = Catalog()
    operation = argv[1] if len(argv) > 1 else 'rebuild'
    getattr(catalog, operation)()
