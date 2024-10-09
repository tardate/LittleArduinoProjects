(function() {
  var root;

  root = typeof exports !== "undefined" && exports !== null ? exports : this;

  root.CatalogController = (function() {
    function CatalogController(catalog_table) {
      this.catalog_table = catalog_table;
      this.hookActions();
      this.loadCatalog();
      this.github_base_url = 'https://github.com/tardate/LittleArduinoProjects/blob/master/';
      this.pages_base_url = 'https://leap.tardate.com/';
    }

    CatalogController.prototype.hookActions = function() {
      $('body').on('click', '[data-url]', function(e) {
        var url, target;
        e.preventDefault();
        url = $(e.target).parents('[data-url]').data('url');
        if (url) location.href = url;
        return false;
      });
    };

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
          var cell, main_cell, description_cell;
          var description, project_rel_url, project_url, hero_image_rel_url, hero_image_url, category_array, category_labels;

          base_name = data.relative_path.split('/').pop();
          project_rel_url = data.relative_path + '/'
          project_url = instance.pages_base_url + project_rel_url

          hero_image_rel_url = project_rel_url + 'assets/' + base_name + '_build.jpg';
          hero_image_url = instance.pages_base_url + hero_image_rel_url;

          category_array = data.categories.split(',');
          category_labels = '';
          for (var cat = 0; cat < category_array.length; cat++) {
            category_labels += '<span class="label label-primary">' + category_array[cat] + '</span> ';
          }

          main_cell = '\
          <div class="hidden-xs"> \
            <a href="' + project_rel_url + '" class="btn btn-default btn-success btn-tardate">' + data.id + '</a> \
          </div> \
          <div class="visible-xs-block"> \
            <a href="' + project_rel_url + '" class="btn btn-default btn-success btn-tardate">' + data.id + ' ' + data.name + '</a> \
            <div class="text-muted small">' + data.description + '</div> \
            <div>' + category_labels + '</div> \
            <img class="tardate-hero" src="' + hero_image_rel_url + '" alt=""> \
          </div>\
          ';
          cell = $('td:eq(0)', row);
          cell.html(main_cell);

          description_cell = '\
          <div class="media"> \
            <div class="media-body"> \
              <h4 class="media-heading">' + data.name + '</h4> \
              <div class="text-muted">' + data.description + '</div> \
              <div>' + category_labels + '</div> \
            </div> \
            <div class="media-right"> \
              <img class="media-object tardate-hero" src="' + hero_image_rel_url + '" alt=""> \
            </div> \
          </div>\
          ';
          cell = $('td:eq(1)', row)
          cell.addClass('xtardate-link')
          cell.addClass('hidden-xs')
          cell.attr('data-url', project_url)
          cell.html(description_cell);
          return cell
        }
      });
    };

    return CatalogController;

  })();

  jQuery(function() {
    return new root.CatalogController($('#catalog-table'));
  });

}).call(this);
