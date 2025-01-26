#!/bin/sh
#
# a script that installs FreeRADIUS on MacOSX
# * tests if talloc already installed with brew
# * installs talloc from source if required
# * installs freeradius-server from source if required
#

GNU_INSTALL_NAME=gcc-arm-none-eabi-5_3-2016q1
GNU_INSTALL_ROOT=$(pwd)/${GNU_INSTALL_NAME}


function install_sdk6() {
  # install nRF SDK from
  # * http://developer.nordicsemi.com/nRF5_SDK/nRF51_SDK_v6.x.x/nrf51_sdk_v6_0_0_43681.zip
  local folder=sdk.6
  local name=nrf51_sdk_v6_0_0_43681

  echo "Installing ${name} from source"

  if [ ! -d ${folder} ]
  then
    echo "Downloading ${name}"
    mkdir ${folder}
    cd ${folder}
    curl -LO http://developer.nordicsemi.com/nRF5_SDK/nRF51_SDK_v6.x.x/${name}.zip &&
    tar zxvf ${name}.zip &&
    rm ${name}.zip
    cd ..
  else
    echo "looks like ${name} already installed .. keep calm and carry on .."
  fi
}


function patch_sdk6_makefile(){
  local makefile_template=sdk.6/nrf51822/Source/templates/gcc/Makefile.posix

  echo "Patching ${makefile_template} to reference GCC ARM .."
  perl -i -pe '
  if (/$ARGV[0]/) {
    $_="$ARGV[0] := $ARGV[1]\n";
  }
  if ( eof ) {
    print;
    close ARGV;
    exit;
  }
  ' ${makefile_template} GNU_INSTALL_ROOT "${GNU_INSTALL_ROOT}"
}


function install_sdk11() {
  # install nRF SDK from
  # * http://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v11.x.x/nRF5_SDK_11.0.0_89a8197.zip
  local folder=sdk.11
  local name=nRF5_SDK_11.0.0_89a8197

  echo "Installing ${name} from source"

  if [ ! -d ${folder} ]
  then
    echo "Downloading ${name}"
    mkdir ${folder}
    cd ${folder}
    curl -LO http://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v11.x.x/${name}.zip &&
    tar zxvf ${name}.zip &&
    rm ${name}.zip
    cd ..
  else
    echo "looks like ${name} already installed .. keep calm and carry on .."
  fi
}


function patch_sdk11_makefile(){
  local makefile_template=sdk.11/components/toolchain/gcc/Makefile.posix

  echo "Patching ${makefile_template} to reference GCC ARM .."
  perl -i -pe '
  if (/$ARGV[0]/) {
    $_="$ARGV[0] := $ARGV[1]\n";
  }
  if ( eof ) {
    print;
    close ARGV;
    exit;
  }
  ' ${makefile_template} GNU_INSTALL_ROOT "${GNU_INSTALL_ROOT}"
}


function install_gcc_arm() {
  # install mac distribution of gcc arm kit
  # * https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q1-update/+download/gcc-arm-none-eabi-5_3-2016q1-20160330-mac.tar.bz2
  # For source, see
  # * https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q1-update/+download/gcc-arm-none-eabi-5_3-2016q1-20160330-src.tar.bz2
  local name=${GNU_INSTALL_NAME}
  local zip=${name}-20160330-mac.tar.bz2

  echo "Installing ${name} from source"

  if [ ! -d ${name} ]
  then
    echo "Downloading ${name}"
    curl -LO https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q1-update/+download/${zip}
    tar zxvf ${zip} && rm ${zip}
  else
    echo "looks like ${name} already installed .. keep calm and carry on .."
  fi

}


install_sdk6
patch_sdk6_makefile
install_sdk11
patch_sdk11_makefile
install_gcc_arm

