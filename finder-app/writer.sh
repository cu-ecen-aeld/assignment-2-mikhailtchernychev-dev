#!/bin/bash

if [ $# -ne 2 ] ; then
  echo "Should have 2 paramaters writefile and  writestr like: " $0 " writefile and  writestr"
  exit 1
 fi

writefile=$1
writestr=$2

echo "$writestr" >  $writefile
