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
from datetime import datetime
from xml.etree import ElementTree
from xml.dom import minidom
from PIL import Image
from PIL import ImageOps


def pretty_write(doc, file):
    pretty_xml = minidom.parseString(
        ElementTree.tostring(doc, 'utf-8')
    ).toprettyxml(indent="  ")
    with open(file, 'w') as f:
        f.write(pretty_xml)


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
        path = os.path.dirname(os.path.abspath(__file__))
        self.collection_root = os.path.abspath(os.path.join(path, '..'))
        self.catalog_json = os.path.join(self.collection_root, 'catalog', 'catalog.json')
        self.catalog_atom = os.path.join(self.collection_root, 'catalog', 'atom.xml')
        self.data_project_json = os.path.join(self.collection_root, '_data', 'projects.json')
        self.data_catalog_json = os.path.join(self.collection_root, '_data', 'catalog.json')
        self.catalog_sitemap = os.path.join(self.collection_root, 'catalog', 'sitemap.xml')

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
            data['relative_path'] = data['relative_path'].lower()
            return data

        if getattr(self, '_metadata', None) is None:
            data = map(lambda filename: load_data(filename), self.metadata_files())
            self._metadata = sorted(data, key=lambda k: -int(k['id'].replace('#', '')))
        return self._metadata

    def get_project_file(self, relative_path, name='.catalog_metadata'):
        return os.path.join(self.collection_root, relative_path, name)

    def get_project_modified_datetime(self, relative_path, filename='README.md'):
        indicative_file = self.get_project_file(relative_path, filename)
        return datetime.utcfromtimestamp(os.path.getmtime(indicative_file))


    def generate_catalog(self):
        """ Command: re-writes the catalog file from catalog_metadata. """
        print("Writing {}..".format(self.catalog_json))
        with open(self.catalog_json, 'w') as f:
            json.dump(self.metadata(), f, indent=4)
        print("Writing {}..".format(self.data_catalog_json))
        with open(self.data_catalog_json, 'w') as f:
            json.dump(self.metadata(), f, indent=4)

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

        print("Writing {}..".format(self.data_project_json))
        with open(self.data_project_json, 'w') as f:
            json.dump(project_data(), f, indent=4)

    def generate_atom_feed(self):
        """ Command: re-writes the atom feed file from catalog_metadata. """

        print("Writing {}..".format(self.catalog_atom))
        root = ElementTree.Element('feed', xmlns='http://www.w3.org/2005/Atom')
        root.set('xmlns:g', 'http://base.google.com/ns/1.0')
        ElementTree.SubElement(root, "title").text = "LEAP: Little Electronic and Arduino Projects"
        ElementTree.SubElement(root, "subtitle").text = "my collection of electronics projects, many involving an Arduino in one way or another"
        ElementTree.SubElement(root, "link", href="https://leap.tardate.com/catalog/atom.xml", rel="self")
        ElementTree.SubElement(root, "link", href="https://leap.tardate.com/")
        ElementTree.SubElement(root, "id").text = "https://leap.tardate.com/"
        ElementTree.SubElement(root, "icon").text = "https://leap.tardate.com/catalog/assets/images/favicon-32x32.png"
        ElementTree.SubElement(root, "logo").text = "https://leap.tardate.com/catalog/assets/images/favicon-32x32.png"
        ElementTree.SubElement(root, "updated").text = datetime.utcnow().strftime("%Y-%m-%dT%H:%M:%SZ")

        author = ElementTree.SubElement(root, "author")
        ElementTree.SubElement(author, "name").text = "Paul Gallagher"
        ElementTree.SubElement(author, "email").text = "gallagher.paul@gmail.com"
        ElementTree.SubElement(author, "uri").text = "https://github.com/tardate"

        for entry in self.metadata():
            url = 'https://leap.tardate.com/{}/'.format(entry['relative_path'])
            hero_image_file = '{}_build.jpg'.format(entry['relative_path'].split('/')[-1])
            asset_path = '{}/assets'.format(entry['relative_path'])
            hero_image_url = 'https://leap.tardate.com/{}/{}'.format(
                asset_path,
                hero_image_file
            )
            update_thumbnail(self.get_project_file(asset_path, hero_image_file))
            updated_at = self.get_project_modified_datetime(asset_path, hero_image_file)
            doc = ElementTree.SubElement(root, "entry")
            ElementTree.SubElement(doc, "id").text = url
            ElementTree.SubElement(doc, "link", href=url)
            ElementTree.SubElement(doc, "g:image_link").text = hero_image_url
            ElementTree.SubElement(doc, "updated").text = updated_at.strftime("%Y-%m-%dT%H:%M:%SZ")
            ElementTree.SubElement(doc, "title").text = u'{} {}'.format(entry['id'], entry['name'])
            ElementTree.SubElement(doc, "summary").text = entry['description']

            content = ElementTree.Element('div')
            ElementTree.SubElement(content, 'p').text =  entry['description']
            ElementTree.SubElement(content, 'img', src=hero_image_url)
            ElementTree.SubElement(doc, "content", type='html').text = ElementTree.tostring(content, encoding='utf-8').decode()

            for category in entry['categories'].split(', '):
                ElementTree.SubElement(doc, 'category', term=category)

        pretty_write(root, self.catalog_atom)

    def generate_sitemap(self):
        """ Command: re-writes the atom feed file from catalog_metadata. """

        print("Writing {}..".format(self.catalog_sitemap))
        root = ElementTree.Element('urlset', xmlns='http://www.sitemaps.org/schemas/sitemap/0.9')

        for entry in self.metadata():
            url = 'https://leap.tardate.com/{}/'.format(entry['relative_path'])
            doc = ElementTree.SubElement(root, 'url')
            ElementTree.SubElement(doc, 'loc').text = url

        pretty_write(root, self.catalog_sitemap)

    def rebuild(self):
        """ Command: rebuild catalog assets from metadata. """
        self.generate_catalog()
        self.generate_project_data()
        self.generate_atom_feed()
        self.generate_sitemap()


if __name__ == '__main__':
    catalog = Catalog()
    operation = argv[1] if len(argv) > 1 else 'rebuild'
    getattr(catalog, operation)()
