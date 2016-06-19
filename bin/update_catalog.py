#!/usr/bin/env python
""" A script to build the catalog.json file.

Collates all project metadata into a simple JSON file used by the catalog index.
This should be re-run after adding a project or updating any project metadata.
"""

import os
import fnmatch


class Catalog(object):
    """ Helper class for building the catalog from metadata files. """

    def __init__(self):
        path = os.path.dirname(os.path.abspath(__file__))
        self.collection_root = os.path.abspath(os.path.join(path, '..'))
        self.catalog_json = os.path.join(self.collection_root, 'catalog', 'catalog.json')

    def metadata_files(self):
        """ Returns the collection of catalog metadata files. """
        matches = []
        for root, dirnames, filenames in os.walk(self.collection_root):
            for filename in fnmatch.filter(filenames, '.catalog_metadata'):
                matches.append(os.path.join(root, filename))
        return matches

    def as_json(self):
        """ TODO: should probably read these files as JSON rather than just treating as strings. """
        return '[\n' + ',\n'.join(
            map(lambda file: open(file).read(), self.metadata_files())
        ) + '\n]'

    def generate(self):
        """ Command: re-writes the catalog file from catalog_metadata. """
        print "Writing {}..".format(self.catalog_json)
        output_file = open(self.catalog_json, 'w')
        output_file.write(self.as_json())
        output_file.close()


catalog = Catalog()
catalog.generate()
