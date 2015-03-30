#!/bin/bash

clear
error='0'

if ! [ -e processes ] ; then
touch processes
fi

NavStik=$(grep "NavStik" < PATH | cut -d'"' -f2)
if [ -e $NavStik ] ; then
	if ! cat $NavStik | grep -q "NAVSTIK" ; then
		echo "NavStik not initialised!"
		error='1'
	fi
else
	echo "NavStik not initialised!"
	error='1'
fi

if [ "$error" == '1' ] ; then
exit
fi

cat $NavStik | grep "NAVSTIK2" | cut -d',' -f4 > tmp&
NAV=$(($!-2))
echo "square-"$NAV >> processes
sleep 6

gcc square.c -o square
./square test.txt

kill $NAV
sed -i /$NAV/d processes
rm tmp
rm square
