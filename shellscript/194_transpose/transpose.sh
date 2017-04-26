#!/bin/sh

# Reference: http://wanggen.myweb.hinet.net/ach3/ach3.html
# NR: number of record, NF: number of field

cat file.txt | awk '{
	for (i=1; i<=NF; i++)
	{
		if (NR==1)
			str[i] = $i;
		else 
			str[i] = str[i] " " $i
	}
}END {
	for (i=1; str[i]!=""; i++)
		print str[i]
}'
