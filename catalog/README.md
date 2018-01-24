# The Catalog

This is a simple Javascript catalog for building the
[LittleArduinoProjects GitHub Pages site](http://leap.tardate.com).

It is a simple bootstrap/datatables page with the main entry point in [index.html](../index.html).
Catalog data is loaded from [catalog.json](./catalog.json), which is consolidated from `.catalog_metadata` I've added to each project.

The [make.py](./make.py) utility script is used to maintain the catalog:

```
$ catalog/make.py rebuild  # regenerates catalog from the README.md
$ catalog/make.py generate  # builds the catalog from catalog metadata
```


## Hosting

I'm using GitHub Pages to run the catalog site directly from the GitHub repository.

How does that work? GitHub Pages basically serves whatever you commit to the repo.
For static HTML sites, that means simply adding an `index.html` to the root of the repo.

By default, GitHub will make a detached gh-pages branch (if you use the web tools to turn on pages).

GitHub now allows you to select the branch from which GitHub Pages are built.
I have configured GitHub to use the master branch, which means the pages site has direct access to all the images and data in the repo,
without needing to continually merge back to the gh-pages branch.

To host on a custom URL, just two steps:

* in DNS, configure a CNAME to point to <username>.github.io
* add a CNAME file to the repo root with the matching CNAME in DNS (GitHub does this for you automatically if you add the custom url in the web interface)


## Credits and References
* [GitHub Pages](https://pages.github.com/)
* [bootstrap](http://getbootstrap.com)
* [datatables](http://datatables.net/)
* [..as mentioned on my blog](https://blog.tardate.com/2016/06/littlearduinoprojects-now-with-fancy.html)
