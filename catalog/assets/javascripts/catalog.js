(function() {
  var root;

  root = typeof exports !== "undefined" && exports !== null ? exports : this;

  root.CatalogController = (function() {
    function CatalogController(catalog_table) {
      this.catalog_table = catalog_table;
      this.hookActions();
      this.loadCatalog();
      this.github_base_url = 'https://github.com/tardate/LittleCodingKata/blob/master/';
      this.pages_base_url = 'https://codingkata.tardate.com/';
      this.hero_images = false;
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
          var project_rel_url, project_url, category_array, category_labels;
          var hero_image_rel_url, hero_image_url, main_hero_frag, description_hero_frag;

          base_name = data.relative_path.split('/').pop();
          project_rel_url = data.relative_path + '/'
          project_url = instance.pages_base_url + project_rel_url

          if (instance.hero_images) {
            hero_image_rel_url = project_rel_url + 'assets/' + base_name + '_build.jpg';
            hero_image_url = instance.pages_base_url + hero_image_rel_url;

            main_hero_frag = '<img class="tardate-hero" src="' + hero_image_rel_url + '" alt="">';
            description_hero_frag = '<div class="media-right"> \
              <img class="media-object tardate-hero" src="' + hero_image_rel_url + '" alt=""> \
            </div>';
          } else {
            main_hero_frag = '';
            description_hero_frag = '';
          }

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
            <div>' + category_labels + '</div>' + main_hero_frag + ' \
          </div>  \
          ';
          cell = $('td:eq(0)', row);
          cell.html(main_cell);

          description_cell = '\
          <div class="media"> \
            <div class="media-body"> \
              <h4 class="media-heading">' + data.name + '</h4> \
              <div class="text-muted">' + data.description + '</div> \
              <div>' + category_labels + '</div> \
            </div> ' + description_hero_frag + ' \
          </div>\
          ';
          cell = $('td:eq(1)', row)
          cell.addClass('linked')
          cell.addClass('hidden-xs')
          cell.attr('data-url', project_rel_url)
          cell.html(description_cell);
          return cell
        }
      }).on( 'init.dt', function () {
        var categoryFilter = $('<select id="category-filter" class="form-control input-sm"><option value="">All Categories</option></select>')
          .appendTo($('#catalog-table_wrapper').find('.dataTables_filter'))
          .on('change', function() {
            var term = $.fn.dataTable.util.escapeRegex($(this).val());
            var query = term ? '([\\s]|^)' + term + '($|,)' : '';
            instance.catalog_table.DataTable().column(2).search(query, true, false).draw();
          });
        $.ajax({
          url: './catalog/categories.json',
          success: function(data) {
            data.forEach(function(item) {
              categoryFilter.append('<option value="' + item + '">' + item + '</option>');
            });
          }
        });
      });
    };

    return CatalogController;
  })();

  jQuery(function() {
    return new root.CatalogController($('#catalog-table'));
  });
}).call(this);
