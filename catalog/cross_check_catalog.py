#!/usr/bin/env python
#

import json
import sys

def load_catalog(filename):
  with open(filename, 'r') as file:
    return sorted(json.load(file), key=lambda x: x['id'])

def cross_check_catalogs(current_catalog, original_catalog):
  original_index = 0
  for current in current_catalog:
    print(f"Checking ID: {current['id']}, Name: {current['name']}")
    while original_index < len(original_catalog) and original_catalog[original_index]['name'] != current['name']:
      original_index += 1
    if original_index < len(original_catalog):
      if original_catalog[original_index]['id'] != current['id']:
        print(f"  valid sequence skipped. Original ID: {original_catalog[original_index]['id']}")
    else:
      print(f"   not found next in sequence")
      return

if __name__ == "__main__":
  if len(sys.argv) != 3:
    print("Usage: cross_check_catalog.py <current_catalog.json> <original_catalog.json>")
    sys.exit(1)

  current_catalog_filename = sys.argv[1]
  original_catalog_filename = sys.argv[2]

  current_catalog = load_catalog(current_catalog_filename)
  original_catalog = load_catalog(original_catalog_filename)

  cross_check_catalogs(current_catalog, original_catalog)
