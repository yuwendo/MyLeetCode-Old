#!/bin/sh

:<<Comments
 Problem Description - 
 	1.	Given a text file file.txt, transpose its content.
	
	2.	You may assume that each row has the same number of columns and each field is separated by the ' ' character.

 	3.	For example, if file.txt has the following content:
			name age
			alice 21
			ryan 30

	4.	Output the following:
			name alice ryan
			age 21 30

 Reference - 
 	1.  http://wanggen.myweb.hinet.net/ach3/ach3.html

 Notification - 
 	1.  NR: number of record, NF: number of field
	2.	BEGIN {} 時常用來作初始設定
		END {} 用來跑結束時的運算結果
		每筆資料進來都要運算的部分就放在 {main}。

Comments

# Read from the file file.txt and print its transposed content to stdout.
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
