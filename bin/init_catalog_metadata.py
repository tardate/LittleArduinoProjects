#!/usr/bin/env python
""" Generate Initial catalog metadata.

This script builds project metadata from the master README.md file.
I'll probably only need this once - to do the initial migration from
the old README.md index to the new catalog app.

"""
import os
import re
import json


class CatalogData(object):
    """ Convert the README.md index into a data structure. """

    def __init__(self):
        path = os.path.dirname(os.path.abspath(__file__))
        self.collection_root = os.path.abspath(os.path.join(path, '..'))
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

    def generate_metadata_files(self):
        for project in catalog.get_projects_from_readme():
            metadata_file = os.path.join(self.collection_root, project['relative_path'], '.catalog_metadata')
            print "Generating {}".format(metadata_file)
            with open(metadata_file, 'w') as f:
                json.dump(project, f, indent=4)

catalog = CatalogData()
catalog.generate_metadata_files()
