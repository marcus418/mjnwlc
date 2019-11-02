#!/bin/bash

for i in bin/testbench/*.bin ; do
cp $i bin/input/input.bin; 

filename=$(basename $i .bin);
output=$(<bin/testanswer/$filename.txt);
echo $filename;
echo $output;

./prog
RETCODE=$?

if [[ "$RETCODE" == "$output" ]] ; then

	echo "Success";
else
	echo "Failure";

fi

rm bin/input/input.bin;

echo $filename;
done
