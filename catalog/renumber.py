#!/usr/bin/env python
#

import json
import os

# Get the parent directory of this script
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def load_catalog():
  catalog_path = os.path.join(BASE_DIR, 'catalog', 'catalog.json')
  with open(catalog_path, 'r') as file:
    return json.load(file)

def save_catalog(catalog):
  catalog_path = os.path.join(BASE_DIR, 'catalog', 'catalog.json')
  with open(catalog_path, 'w') as file:
    json.dump(catalog, file, indent=4)

def update_metadata_file(project, new_id):
  metadata_path = os.path.join(BASE_DIR, project['relative_path'], '.catalog_metadata')
  with open(metadata_path, 'r') as file:
    metadata = json.load(file)

  metadata['id'] = new_id

  with open(metadata_path, 'w') as file:
    json.dump(metadata, file, indent=4)

def renumber_projects():
  catalog = load_catalog()
  catalog.sort(key=lambda x: x['id'])

  for new_id, project in enumerate(catalog, start=1):
    new_id = f"#{new_id:03}"
    if project['id'] != new_id:
      project['id'] = new_id
    update_metadata_file(project, new_id)
    readme_path = os.path.join(BASE_DIR, project['relative_path'], 'README.md')
    if os.path.exists(readme_path):
      with open(readme_path, 'r') as file:
        lines = file.readlines()

      if lines and lines[0].startswith('#'):
        parts = lines[0].split(' ', 2)
        if len(parts) > 1 and parts[1] != new_id:
          lines[0] = f"# {new_id} {parts[2]}" if len(parts) > 2 else f"# {new_id}\n"

          with open(readme_path, 'w') as file:
            file.writelines(lines)

  # save_catalog(catalog)

if __name__ == "__main__":
  renumber_projects()
