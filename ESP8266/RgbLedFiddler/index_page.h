// main web page content. Generated from page_design.html at 2021-03-15 23:56:19 +0800
char index_page[] = "<!doctype html>\n\
<html lang=\"en\">\n\
  <head>\n\
    <meta charset=\"utf-8\">\n\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n\
    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">\n\
    <style>\n\
      body { background-color: #ccc; }\n\
      .card { background-color: antiquewhite; }\n\
    </style>\n\
  </head>\n\
  <body>\n\
    <div class=\"container-fluid mt-3\">\n\
      <div class=\"row\">\n\
        <div class=\"col-12\">\n\
          <div class=\"card\">\n\
            <div class=\"card-body\">\n\
              <div class=\"row\">\n\
                <div class=\"col-3\">\n\
                  <h5>LEAP#585 RGB Fiddler</h5>\n\
                  <p class=\"card-text\">Compiled on " __DATE__ " at " __TIME__ "</p>\n\
                </div>\n\
                <div class=\"col-4\">\n\
\n\
                </div>\n\
                <div class=\"col-5\">\n\
                  <div>\n\
                    <input type=\"color\" id=\"color_picker\" name=\"color_picker\" value=\"#ffffff\">\n\
                    <label for=\"color_picker\">Choose a Color</label>\n\
                  </div>\n\
                </div>\n\
              </div>\n\
            </div>\n\
          </div>\n\
        </div>\n\
      </div>\n\
      <div class=\"row\">\n\
        <div class=\"col-6\">\n\
          <div>\n\
            <input type=\"text\" id=\"rgb_red\" name=\"rgb_red\">\n\
            <label for=\"rgb_red\">Red</label>\n\
          </div>\n\
\n\
          <div>\n\
            <input type=\"text\" id=\"rgb_green\" name=\"rgb_green\">\n\
            <label for=\"rgb_green\">Green</label>\n\
          </div>\n\
\n\
          <div>\n\
            <input type=\"text\" id=\"rgb_blue\" name=\"rgb_blue\">\n\
            <label for=\"rgb_blue\">Blue</label>\n\
          </div>\n\
\n\
          <div>\n\
            <input type=\"text\" id=\"rgb_hex\" name=\"rgb_hex\">\n\
            <label for=\"rgb_hex\">Hex</label>\n\
          </div>\n\
\n\
          <div>\n\
            <input type=\"text\" id=\"server_response\" name=\"server_response\">\n\
            <label for=\"server_response\">Server Response</label>\n\
          </div>\n\
        </div>\n\
        <div id=\"color_preview\" class=\"col-6\">\n\
          Color Preview\n\
        </div>\n\
      </div>\n\
    </div>\n\
\n\
<script type=\"text/javascript\">\n\
window.addEventListener(\"load\", startup, false);\n\
\n\
function hexToRgb(hex) {\n\
  var result = /^#?([a-f\\d]{2})([a-f\\d]{2})([a-f\\d]{2})$/i.exec(hex);\n\
  return result ? {\n\
    red: parseInt(result[1], 16),\n\
    green: parseInt(result[2], 16),\n\
    blue: parseInt(result[3], 16)\n\
  } : null;\n\
}\n\
\n\
function startup() {\n\
  var color_picker;\n\
  var default_color = \"#ffffff\";\n\
\n\
  color_picker = document.querySelector(\"#color_picker\");\n\
  color_picker.value = default_color;\n\
  color_picker.addEventListener(\"input\", handle_color_picker_selection, false);\n\
  color_picker.addEventListener(\"change\", handle_color_picker_selection, false);\n\
  color_picker.select();\n\
}\n\
\n\
function handle_color_picker_selection(event) {\n\
  var element = document.querySelector(\"#color_preview\");\n\
  var hex_color = event.target.value;\n\
  var rgb_color = hexToRgb(event.target.value);\n\
  if (rgb_color) {\n\
    element.style.backgroundColor = hex_color;\n\
    document.querySelector(\"#rgb_hex\").value = hex_color;\n\
    document.querySelector(\"#rgb_red\").value = rgb_color.red;\n\
    document.querySelector(\"#rgb_green\").value = rgb_color.green;\n\
    document.querySelector(\"#rgb_blue\").value = rgb_color.blue;\n\
    send_update(rgb_color);\n\
  }\n\
}\n\
\n\
var cts = true;\n\
\n\
function send_update(rgb_color) {\n\
  if (cts) {\n\
    var xhr = new XMLHttpRequest();\n\
    xhr.open('POST', 'http://rgb-fiddler.local/update?red=' + rgb_color.red + '&green=' + rgb_color.green + '&blue=' + rgb_color.blue);\n\
    xhr.onload = function() {\n\
      cts = true;\n\
      if (xhr.status === 200) {\n\
        document.querySelector(\"#server_response\").value = xhr.responseText;\n\
      }\n\
    };\n\
    cts = false;\n\
    xhr.send();\n\
  }\n\
}\n\
</script>\n\
  </body>\n\
</html>\n\
";
