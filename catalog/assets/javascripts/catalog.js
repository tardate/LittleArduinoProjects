(function() {
  var root;

  root = typeof exports !== "undefined" && exports !== null ? exports : this;

  root.CatalogController = (function() {
    function CatalogController(catalog_table) {
      this.catalog_table = catalog_table;
      this.loadCatalog();
      this.github_base_url = 'https://github.com/tardate/LittleArduinoProjects/blob/master/';
      this.pages_base_url = 'http://tardate.github.io/LittleArduinoProjects/';
    }

    CatalogController.prototype.loadCatalog = function() {
      var instance;
      instance = this;
      return this.catalog_table.DataTable({
        autoWidth: false,
        ajax: {
          url: './catalog/catalog.json',
          dataSrc: ''
        },
        columns: [
          {
            data: 'id',
            width: '10%'
          }, {
            data: 'name'
          }, {
            data: 'categories',
            visible: false
          }, {
            data: 'description',
            visible: false
          }
        ],
        order: [[0, "desc"]],
        rowCallback: function(row, data, index) {
          var base_name;
          var id_link, id_cell;
          var description, hero_image_url, category_array, category_labels;

          base_name = data.relative_path.split('/').pop();
          hero_image_url = instance.pages_base_url + data.relative_path + '/assets/' + base_name + '_build.jpg';
          id_link = '<div class="xleap-link"> \
            <a href="' + instance.github_base_url + data.relative_path + '" class="btn btn-default btn-success btn-leap">' + data.id + '</a> \
          </div>';
          id_cell = $('td:eq(0)', row);
          id_cell.html(id_link);

          category_array = data.categories.split(',');
          category_labels = '';
          for (var cat = 0; cat < category_array.length; cat++) {
            category_labels += '<span class="label label-primary">' + category_array[cat] + '</span> ';
          }
          description = '<div class="media"> \
            <div class="media-body"> \
              <h4 class="media-heading">' + data.name + '</h4> \
              ' + data.description + ' \
              <div>' + category_labels + '</div>  \
            </div> \
            <div class="media-right"> \
              <a href="#"> \
                <img class="media-object leap-hero" src="' + hero_image_url + '" alt=""> \
              </a> \
            </div> \
          </div>';
          return $('td:eq(1)', row).html(description);
        }
      });
    };

    return CatalogController;

  })();

  jQuery(function() {
    return new root.CatalogController($('#catalog-table'));
  });

}).call(this);
