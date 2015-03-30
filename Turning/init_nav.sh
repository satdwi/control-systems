#!/bin/bash

NavStik=$(grep "NavStik" < PATH | cut -d'"' -f2)
if ! [ -e $NavStik ]
then
	echo "NavStik not connected!"
	exit
fi
stty -F $NavStik 115200
echo "\r" > $NavStik
echo "\r" > $NavStik
echo "usb start" > $NavStik
if ! cat $NavStik | grep -q "NAVSTIK"
then
echo "NavStik not initialised!"
else
echo "NavStik succesfully initialised!"
fi

