(function() {
  var root;

  root = typeof exports !== "undefined" && exports !== null ? exports : this;

  root.CatalogController = (function() {
    function CatalogController(catalog_table) {
      this.catalog_table = catalog_table;
      this.loadCatalog();
      this.github_base_url = 'https://github.com/tardate/LittleArduinoProjects/blob/master/';
    }

    CatalogController.prototype.loadCatalog = function() {
      var instance;
      instance = this;
      return this.catalog_table.DataTable({
        ajax: {
          url: './catalog/catalog.json',
          dataSrc: ''
        },
        columns: [
          {
            data: 'id'
          }, {
            data: 'description'
          }, {
            data: 'categories'
          }
        ],
        order: [[0, "desc"]],
        rowCallback: function(row, data, index) {
          var full_description, id_link;
          id_link = '<a href="' + instance.github_base_url + data.relative_path + '">' + data.id + '</a>';
          $('td:eq(0)', row).html(id_link);
          full_description = "<strong>" + data.name + "</strong>&nbsp;";
          full_description += "<span>" + data.description + "</span>";
          return $('td:eq(1)', row).html(full_description);
        }
      });
    };

    return CatalogController;

  })();

  jQuery(function() {
    return new root.CatalogController($('#catalog-table'));
  });

}).call(this);
