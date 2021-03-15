#!/bin/sh
while true;
do
  printf ">:"
read
var
  echo $var >> $1
done
exit
