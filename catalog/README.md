# The Catalog

This is a simple Javascript catalog for building the
[LittleArduinoProjects GitHub Pages site](http://tardate.github.io/LittleArduinoProjects/).

It is a simple bootstrap/datatables page.
Catalog data is loaded from [catalog.json](./catalog.json).

I use two utility scripts:

* [init_catalog_metadata.py](../bin/init_catalog_metadata.py) - used for the initial conversion from the table in the README.md
* [update_catalog.py](../bin/update_catalog.py) - rebuilds the catalog.json when I add a project or change project metadata.

## Credits and References
* [bootstrap](http://getbootstrap.com)
* [datatables](http://datatables.net/)

