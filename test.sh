#! /bin/bash
INPUT=bin/input.csv
IFS=","

if [ -f bin/output.csv ] ; then
	rm bin/output.csv;
fi

[ ! -f $INPUT ] && { echo "$INPUT file not found!"; exit 99; }
while read field1 field2 field3 field4
do

	i=bin/testbench/$field1.bin
	j=bin/testanswer/$field1.txt
	if [ ! -f $i ] ; then
		echo " ";
		echo "ERROR!";
		echo "bin/testbench does not contain $field1.bin!";
		echo " ";
		exit 99;
	fi
	OUTPUT=$(<bin/testanswer/$field1.txt);
	if [ ! -f $j ] ; then
		echo " ";
		echo "ERROR!";
		echo "bin/testanswer does not contain $field1.txt!";
		echo " ";
		exit 99;
	fi

	cp $i bin/test/temp.bin;

	if [ -z "$1" ] ; then
		./prog;
	else
		if [ -f "$1" ] ; then
			./$1;
		else
			echo " ";
			echo "ERROR!";
			echo "The file $1 does not exist!";
			echo " ";
			exit 99;
		fi
	fi
	RETCODE=$?
	echo $RETCODE;
	if [[ "$RETCODE" == "$OUTPUT" ]] ; then
		STATUS="Success";
	else
		STATUS="Failure"
	fi
	rm bin/test/temp.bin;
	echo "$field1" "$field2" "$field3" "$field4"
	printf "%s, %s, %s, %s, %s" "$field1" "$field2" "$STATUS" "$field3"  "$field4" >> bin/output.csv
done < $INPUT

