#!/bin/bash
#
# Refresh the sources for CustomDemo.X from the
# original sources published at https://github.com/boldport/stringy/tree/master/software
#
# This will:
# * put the original demo tune back in place
# * undo any modifications to the firmware
#

scriptPath=${0%/*}/
projectPath=${scriptPath}CustomDemo.X/

curl https://raw.githubusercontent.com/boldport/stringy/master/software/stringy.asm -o ${projectPath}stringy.asm
curl https://raw.githubusercontent.com/boldport/stringy/master/software/demo.tun -o ${projectPath}demo.tun
