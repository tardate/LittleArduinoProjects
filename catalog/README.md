# The Catalog

This is a simple Javascript catalog for building the
[LittleArduinoProjects GitHub Pages site](https://leap.tardate.com).

It is a simple bootstrap/datatables page with the main entry point in [index.html](../index.html).
Catalog data is loaded from [catalog.json](./catalog.json), which is consolidated from `.catalog_metadata` I've added to each project.

The [make.py](./make.py) utility script is used to maintain the catalog:

```sh
catalog/make.py rebuild  # builds the catalog from catalog metadata
```

## Jekyll Generation

The site now uses Jekyll for page generation.

## Atom Feed

The [make.py](./make.py) script also generates the [atom.xml](./atom.xml) feed file.
This is a best-effort conversion to an atom feed. Currently includes all projects in the feed.

* [feed validator](http://www.feedvalidator.org/check.cgi?url=https%3A%2F%2Fleap.tardate.com%2Fcatalog%2Fatom.xml)
* [published feed location](https://leap.tardate.com/catalog/atom.xml)

## Hosting

I'm using [Netlify](https://www.netlify.com/) to run the catalog site directly from the GitHub repository.

Note: I previously used GitHub Pages, but switched to Netlify as that allows me to use free SSL certificates from [LetsEncrypt](https://letsencrypt.org/).

## Running Locally

The site is generated with Jekyll. To run locally:

```sh
bundle exec jekyll serve
```

The generated site will be in the `_site` folder. This can be trashed after testing (it is not checked into the repo).

## Credits and References

* [Netlify](https://www.netlify.com/)
* [LetsEncrypt](https://letsencrypt.org/)
* [GitHub Pages](https://pages.github.com/)
* [bootstrap](http://getbootstrap.com)
* [datatables](http://datatables.net/)
* [..as mentioned on my blog](https://blog.tardate.com/2016/06/littlearduinoprojects-now-with-fancy.html)
