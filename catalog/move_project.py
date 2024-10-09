#!/usr/bin/env python
#

import os
import shutil
import json
import sys

def move_project(current_path, new_path):
  # Determine the repo root directory
  script_dir = os.path.dirname(os.path.abspath(__file__))
  repo_root = os.path.abspath(os.path.join(script_dir, os.pardir))

  # Move the project directory to the new location
  shutil.move(current_path, new_path)

  # Load the .catalog_metadata json file from the project directory
  metadata_path = os.path.join(new_path, '.catalog_metadata')
  with open(metadata_path, 'r') as f:
    metadata = json.load(f)

  # Update the relative_path in the .catalog_metadata file
  metadata['relative_path'] = os.path.relpath(new_path, repo_root)

  # Write the updated .catalog_metadata file
  with open(metadata_path, 'w') as f:
    json.dump(metadata, f, indent=4)

if __name__ == "__main__":
  if len(sys.argv) != 3:
    print("Usage: move_project.py <current_project_path> <new_project_path>")
    sys.exit(1)

  current_project_path = sys.argv[1]
  new_project_path = sys.argv[2]

  move_project(current_project_path, new_project_path)
