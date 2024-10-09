#!/usr/bin/env python
#

import os
import json

def find_repo_root():
  return os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))

def find_catalog_metadata_files(repo_root):
  catalog_metadata_files = []
  for root, _, files in os.walk(repo_root):
    for file in files:
      if file.endswith('.catalog_metadata'):
        catalog_metadata_files.append(os.path.join(root, file))
  return catalog_metadata_files

def update_relative_path(catalog_metadata_file, repo_root):
  with open(catalog_metadata_file, 'r') as f:
    metadata = json.load(f)

  relative_path = os.path.relpath(os.path.dirname(catalog_metadata_file), repo_root)
  metadata['relative_path'] = relative_path

  with open(catalog_metadata_file, 'w') as f:
    json.dump(metadata, f, indent=4)

def main():
  repo_root = find_repo_root()
  catalog_metadata_files = find_catalog_metadata_files(repo_root)

  for catalog_metadata_file in catalog_metadata_files:
    update_relative_path(catalog_metadata_file, repo_root)

if __name__ == '__main__':
  main()
