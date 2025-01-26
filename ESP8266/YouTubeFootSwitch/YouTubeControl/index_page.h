// main web page content. Generated from page_design.html at 2020-04-24 00:40:57 +0800
char index_page[] = "<!doctype html>\n\
<html lang=\"en\">\n\
  <head>\n\
    <meta charset=\"utf-8\">\n\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n\
    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">\n\
    <style>\n\
      body { background-color: #222; }\n\
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
                  <h5>LEAP#544 YouTube FootSwitch</h5>\n\
                  <p class=\"card-text\">Compiled on " __DATE__ " at " __TIME__ "</p>\n\
                </div>\n\
                <div class=\"col-4\">\n\
                  <div class=\"form-inline\">\n\
                    <div class=\"form-group\">\n\
                      <label for=\"video_id\" class=\"my-1 mr-2\">Video ID</label>\n\
                      <input type=\"input\" class=\"form-control\" id=\"video_id\" autocomplete=\"off\">\n\
                    </div>\n\
                    <button class=\"btn btn-primary my-1 ml-2\" id=\"reload\">Load</button>\n\
                  </div>\n\
                </div>\n\
                <div class=\"col-5\">\n\
                  <h1>\n\
                    <button class=\"btn btn-success\" id=\"connect\">Connect Foot Controller</button>\n\
                    <span id=\"player-state\" class=\"badge badge-danger\" style=\"display: none\">Stopped</span>\n\
                  </h1>\n\
                  <div class=\"debug-controls\" style=\"display: none;\">\n\
                    <button class=\"btn btn-warning\" id=\"skiprev\">Rev</button>\n\
                    <button class=\"btn btn-success\" id=\"play-toggle\">Play</button>\n\
                    <button class=\"btn btn-warning\" id=\"skipfwd\">Fwd</button>\n\
                    <button class=\"btn btn-primary\" id=\"mark-toggle\">Mark</button>\n\
                    <p>Uptime: <span id=\"uptime\" class=\"badge badge-success\">00:00:00</span></p>\n\
                  </div>\n\
                </div>\n\
              </div>\n\
            </div>\n\
          </div>\n\
        </div>\n\
      </div>\n\
      <div class=\"row\">\n\
        <div class=\"col-12\">\n\
          <div class=\"video_wrapper mt-3 text-center\">\n\
            <div id=\"player\"></div>\n\
          </div>\n\
        </div>\n\
      </div>\n\
    </div>\n\
    <script>\n\
      var player;\n\
      var flag_check_loop_condition = false;\n\
      var flag_looping = false;\n\
      var play_state = false;\n\
      var mark_one = false;\n\
      var mark_two = false;\n\
      var video_width = window.innerWidth * 0.85;\n\
      var video_height = video_width * 9/16;\n\
      var video_id = location.search.replace('?v=', '') || 'cPlrskC9pfY';\n\
      document.getElementById(\"video_id\").value = video_id;\n\
      var tag = document.createElement('script');\n\
      tag.src = \"https://www.youtube.com/iframe_api\";\n\
      var firstScriptTag = document.getElementsByTagName('script')[0];\n\
      firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);\n\
      function onYouTubeIframeAPIReady() {\n\
        player = new YT.Player('player', {\n\
          width: video_width,\n\
          height: video_height,\n\
          videoId: video_id,\n\
          playerVars: {\n\
            'controls': 0,\n\
            'enablejsapi': 1\n\
          },\n\
          events: {\n\
            'onReady': onPlayerReady,\n\
            'onStateChange': onPlayerStateChange\n\
          }\n\
        });\n\
      };\n\
      function loadNewVideo() {\n\
        var video_id = document.getElementById(\"video_id\").value;\n\
        video_id = video_id.replace(/.*?\\.be\\//, '').replace(/.*?v=/, '').replace(/&.*/, '');\n\
        var url = window.location.href.split('?')[0];\n\
        window.location.href = url + '?v=' + video_id;\n\
      };\n\
      function onPlayerReady(event) {\n\
        enableControls();\n\
      };\n\
      function onPlayerStateChange(event) {\n\
        if (event.data == YT.PlayerState.PAUSED) {\n\
          if (flag_check_loop_condition) {\n\
            if (flag_looping) {\n\
              startLoop();\n\
            }\n\
            flag_check_loop_condition = false;\n\
          }\n\
        }\n\
      };\n\
      function loopOrPause() {\n\
        flag_check_loop_condition = flag_looping;\n\
        player.pauseVideo();\n\
      };\n\
      function startLoop() {\n\
        var startSeconds = mark_one;\n\
        var endSeconds = mark_two;\n\
        if (startSeconds && endSeconds) {\n\
          player.seekTo(startSeconds, true);\n\
          player.playVideo();\n\
          setTimeout(loopOrPause, (endSeconds - startSeconds) * 1000);\n\
        }\n\
      };\n\
      function endLoop() {\n\
        mark_one = false;\n\
        mark_two = false;\n\
        flag_looping = false;\n\
        play_state = false;\n\
      };\n\
      function skip(duration) {\n\
        var current_time = player.getCurrentTime();\n\
        player.seekTo(current_time + duration, true);\n\
        player.playVideo();\n\
      };\n\
      function updateStateIndicator() {\n\
        var classes = \"badge badge-danger\";\n\
        var message = \"Stopped\";\n\
        if (flag_looping) {\n\
          message = \"Looping \" + mark_one.toFixed(1) + \"s - \" + mark_two.toFixed(1) + \"s\";\n\
          classes = \"badge badge-primary\";\n\
        } else if (mark_one) {\n\
          message = \"Loop \" + mark_one.toFixed(1) + \"s - ???\";\n\
          classes = \"badge badge-warning\";\n\
        } else if (play_state) {\n\
          classes = \"badge badge-success\";\n\
          message = \"Playing\";\n\
        }\n\
        document.getElementById(\"player-state\").className = classes;\n\
        document.getElementById(\"player-state\").innerHTML = message;\n\
      };\n\
      function update(data) {\n\
        document.getElementById(\"uptime\").innerHTML = new Date(data.uptime).toISOString().substr(11, 8);\n\
        if (data.changed) {\n\
          switch(data.event) {\n\
            case 1:\n\
              player.playVideo();\n\
              play_state = true;\n\
              updateStateIndicator();\n\
              break;\n\
            case 2:\n\
              player.pauseVideo();\n\
              endLoop();\n\
              updateStateIndicator();\n\
              break;\n\
            case 3:\n\
              skip(-10);\n\
              break;\n\
            case 4:\n\
              skip(10);\n\
              break;\n\
            case 5:\n\
              mark_one = player.getCurrentTime();\n\
              updateStateIndicator();\n\
              break;\n\
            case 6:\n\
              mark_two = player.getCurrentTime();\n\
              flag_looping = true;\n\
              updateStateIndicator();\n\
              startLoop();\n\
              break;\n\
            case 7:\n\
              endLoop();\n\
              updateStateIndicator();\n\
              break;\n\
          }\n\
        }\n\
      };\n\
      var sampler = function() {\n\
        var xhr = new XMLHttpRequest();\n\
        xhr.open('GET', 'http://yt-foot-controller.local/status.json');\n\
        xhr.onload = function() {\n\
          if (xhr.status === 200) {\n\
            var data = JSON.parse(xhr.responseText);\n\
            update(data);\n\
            setTimeout(sampler, 50);\n\
          }\n\
        };\n\
        xhr.send();\n\
      };\n\
      function enableControls() {\n\
        document.getElementById(\"connect\").addEventListener(\"click\", function() {\n\
          console.log(\"connect\");\n\
          this.style.cssText = 'display: none;';\n\
          document.getElementById('player-state').style.cssText = 'display:inline;';\n\
          sampler();\n\
        });\n\
        document.getElementById(\"reload\").addEventListener(\"click\", function() {\n\
          console.log(\"reload\");\n\
          loadNewVideo();\n\
        });\n\
        document.getElementById(\"skiprev\").addEventListener(\"click\", function() {\n\
          update({\"uptime\":3908,\"event\":3,\"play\":true,\"loop\":false,\"changed\":true});\n\
        });\n\
        document.getElementById(\"play-toggle\").addEventListener(\"click\", function() {\n\
          if (play_state) {\n\
            this.innerText = \"Play\";\n\
            this.className = \"btn btn-success\";\n\
            update({\"uptime\":2908,\"event\":2,\"play\":false,\"loop\":false,\"changed\":true});\n\
          } else {\n\
            this.innerText = \"Stop\";\n\
            this.className = \"btn btn-danger\";\n\
            update({\"uptime\":1908,\"event\":1,\"play\":true,\"loop\":false,\"changed\":true});\n\
          }\n\
        });\n\
        document.getElementById(\"skipfwd\").addEventListener(\"click\", function() {\n\
          update({\"uptime\":4908,\"event\":4,\"play\":true,\"loop\":false,\"changed\":true});\n\
        });\n\
        document.getElementById(\"mark-toggle\").addEventListener(\"click\", function() {\n\
          if (mark_two) {\n\
            this.innerText = \"Mark\";\n\
            this.className = \"btn btn-primary\";\n\
            document.getElementById(\"play-toggle\").innerText = \"Stop\";\n\
            document.getElementById(\"play-toggle\").className = \"btn btn-danger\";\n\
            update({\"uptime\":7908,\"event\":7,\"play\":true,\"loop\":false,\"changed\":true});\n\
          } else if (mark_one) {\n\
            this.innerText = \"Looping\";\n\
            this.className = \"btn btn-warning\";\n\
            update({\"uptime\":6908,\"event\":6,\"play\":true,\"loop\":true,\"changed\":true});\n\
          } else {\n\
            this.innerText = \"Mark End\";\n\
            this.className = \"btn btn-success\";\n\
            update({\"uptime\":5908,\"event\":5,\"play\":true,\"loop\":false,\"changed\":true});\n\
          }\n\
        });\n\
      };\n\
    </script>\n\
  </body>\n\
</html>\n\
";
