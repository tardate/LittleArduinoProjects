#!/bin/sh
# This is a real hack - see the README.md
#
# Given a .hex files as $1, this inserts a 0-offset Extended Linear Address record
# if not already present.
#

perl -i -pe '
if ($. == 1) {
  if (!(/^:02.{4}04/)) {
    print ":020000040000FA\n";
  }
}
if ( eof ) {
  print;
  close ARGV;
  exit;
}
' $1
