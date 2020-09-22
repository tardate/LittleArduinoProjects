#!/bin/bash
#
# A simple script to initialise a new project
#


function usage() {
  cat <<EOF

Make a new project workspace..

Usage:
  $0 51 ProjectName  # new 8051 project
  $0 ar ProjectName  # new ARM/STM32 project
  $0 au ProjectName  # new Audio project
  $0 bp ProjectName  # new BoldportClub project
  $0 ee ProjectName  # new Electronics101 project
  $0 eq ProjectName  # new Equipment project
  $0 es ProjectName  # new ESP8266 project
  $0 e3 ProjectName  # new ESP32 project
  $0 fp ProjectName  # new FPGA project
  $0 ki ProjectName  # new Kinetics project
  $0 kr ProjectName  # new Kraft project
  $0 os ProjectName  # new OSHChip project
  $0 pi ProjectName  # new PIC project
  $0 pg ProjectName  # new Arduino playground project
  $0 ra ProjectName  # new Radio project

EOF
  exit
}

function make_project() {
  # full_project_name=Part1/Part2
  # full_path=Kinetics/Part1/Part2
  # parent_folder = Kinetics/Part1
  # project_name = Part2
  local full_project_name=$2
  local full_path="${1}/${full_project_name}"
  local parent_folder=$(dirname "$full_path")
  local project_name=$(basename "$full_path")

  mkdir -p ${full_path}
  mkdir ${full_path}/assets
  mkdir ${full_path}/assets/wip

  local readme_file="${full_path}/README.md"
  echo "making ${readme_file}"
  cat > "${readme_file}" <<EOS
# ${full_project_name}

__subtitle__

![Build](./assets/${project_name}_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/video_id/0.jpg)](https://www.youtube.com/watch?v=video_id)

## Notes

__notes__

## Construction

![Breadboard](./assets/${project_name}_bb.jpg?raw=true)

![Schematic](./assets/${project_name}_schematic.jpg?raw=true)

![Breadboard Build](./assets/${project_name}_bb_build.jpg?raw=true)

## Credits and References

* [name](url)
EOS

  local catalog_file="${full_path}/.catalog_metadata"
  echo "making ${catalog_file}"
  cat > "${catalog_file}" <<EOS
{
    "id": "#xxx",
    "name": "${project_name}",
    "description": "description",
    "categories": "",
    "relative_path": "${full_path}"
}
EOS

  local ino_file="${full_path}/${project_name}.ino"
  echo "making ${ino_file}"
  cat > "${ino_file}" <<EOS
/*

  ${full_project_name}
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/${full_path}

 */

const int LED_PIN = 13;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);
  delay(500);

  output = !output;
}

EOS

  cp catalog/templates/template.fzz "${full_path}/${project_name}.fzz"
  echo "project initialised: ${full_path}"
  open "${full_path}"
}


op=${1:-help}

case ${op} in

51|8051|mcs51)
  make_project "8051" "${2}"
  ;;

au)
  make_project "Audio" "${2}"
  ;;

ar | arm | st | stm)
  make_project "ARM" "${2}"
  ;;

bp)
  make_project "BoldportClub" "${2}"
  ;;

ee)
  make_project "Electronics101" "${2}"
  ;;

eq)
  make_project "Equipment" "${2}"
  ;;

es | esp)
  make_project "ESP8266" "${2}"
  ;;

e3 | esp32)
  make_project "ESP32" "${2}"
  ;;

fp | fpga)
  make_project "FPGA" "${2}"
  ;;

ki)
  make_project "Kinetics" "${2}"
  ;;

kr)
  make_project "Kraft" "${2}"
  ;;

os)
  make_project "OSHChip" "${2}"
  ;;

pg)
  make_project "playground" "${2}"
  ;;

pi | pic)
  make_project "PIC" "${2}"
  ;;

ra | radio)
  make_project "Radio" "${2}"
  ;;

*)
  usage
  ;;

esac
