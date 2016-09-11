#!/usr/bin/env python
""" A script to build the catalog.json file.

Collates all project metadata into a simple JSON file used by the catalog index.
This should be re-run after adding a project or updating any project metadata.

This script can also build project metadata from the master README.md file.
Not sure how long I'll need this for.

"""
from sys import argv
import os
import re
import json
import fnmatch


class Catalog(object):
    """ Helper class for building the catalog from metadata files. """

    def __init__(self):
        path = os.path.dirname(os.path.abspath(__file__))
        self.collection_root = os.path.abspath(os.path.join(path, '..'))
        self.catalog_json = os.path.join(self.collection_root, 'catalog', 'catalog.json')
        self.readme = os.path.join(self.collection_root, 'README.md')

    def get_projects_from_readme(self):
        """ Parses the README and returns a list of projects.


        example README entry:
        | [#197 WienBridgeAudioToneGenerator](./Electronics101/WienBridgeAudioToneGenerator) | **OpAmp, Oscillators**          fixed-frequency tone generator based on a Wien Bridge Oscillator |

        corresponding generated metadata:
        {
            'name': 'WienBridgeAudioToneGenerator',
            'relative_path': 'Electronics101/WienBridgeAudioToneGenerator',
            'description': 'fixed-frequency tone generator based on a Wien Bridge Oscillator',
            'categories': 'OpAmp, Oscillators',
            'id': '#197'
        }
        """
        extractor = re.compile(r"\|\s+\[(?P<id>#\d+)\s(?P<name>.*)\]\(\.\/(?P<relative_path>.*)\)\s*\|\s+\*\*(?P<categories>.*)\*\*\s+(?P<description>.*)\s+\|")
        data = []
        for line in open(self.readme):
            matches = extractor.match(line)
            if matches:
                data.append(matches.groupdict())
        return data

    def metadata_files(self):
        """ Returns the collection of catalog metadata files. """
        matches = []
        for root, dirnames, filenames in os.walk(self.collection_root):
            for filename in fnmatch.filter(filenames, '.catalog_metadata'):
                matches.append(os.path.join(root, filename))
        return matches

    def metadata(self):
        """ Returns the metadata based on .catalog_metadata files. """
        return map(lambda file: json.load(open(file, 'r')), self.metadata_files())

    def generate(self):
        """ Command: re-writes the catalog file from catalog_metadata. """
        print "Writing {}..".format(self.catalog_json)
        with open(self.catalog_json, 'w') as f:
            json.dump(self.metadata(), f, indent=4)

    def generate_metadata_files(self):
        """ Command: generates catalog_metadata from README data. """
        for project in self.get_projects_from_readme():
            metadata_file = os.path.join(self.collection_root, project['relative_path'], '.catalog_metadata')
            print "Generating {}".format(metadata_file)
            with open(metadata_file, 'w') as f:
                json.dump(project, f, indent=4)

    def rebuild(self):
        """ Command: rebuild catalog_metadata and catalog.json from README.md. """
        self.generate_metadata_files()
        self.generate()


if __name__ == '__main__':
    catalog = Catalog()
    operation = argv[1] if len(argv) > 1 else 'rebuild'
    getattr(catalog, operation)()
