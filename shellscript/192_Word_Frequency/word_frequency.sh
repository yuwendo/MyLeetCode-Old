#!/bin/sh

:<<Comments
 Problem Description - 192. Word Frequency 
	1.	Write a bash script to calculate the frequency of each word in a text file 'words.txt'.

	2.	For simplicity sake, you may assume:
		    words.txt contains only lowercase characters and space ' ' characters.
   			Each word must consist of lowercase characters only.
    		Words are separated by one or more whitespace characters.

	3.	For example, assume that words.txt has the following content:
			the day is sunny the the
			the sunny is is

	4.	Your script should output the following, sorted by descending frequency:
			the 4
			is 3
			sunny 2
			day 1

	Note:
		Don't worry about handling ties, it is guaranteed that each word's frequency count is unique. 
		
 Reference - 
	1.	ftp://ftp.gnu.org/old-gnu/Manuals/gawk-3.0.3/html_chapter/gawk_12.html 
	2.	https://blog.longwin.com.tw/2009/10/linux-bash-shell-use-sort-by-col-2009/

 Notification - 	
    -n : 依數字大小排序
    -r : 降冪排序(反向排序, 大 -> 小)
    -t,: 欄位以 , 當分隔符號
    -k : 以第幾個欄位來排序
	
Comments

# Read from the file words.txt and output the word frequency list to stdout.
#cat words.txt | sed -e 's/ /\n/g' | sort 

cat words.txt | awk '{	
		for(i=1;i<=NF;i++)
		{
			counts[$i]++
		}
	} END {
		for (words in counts)
		{
			print words,counts[words]
		}
	}' | sort -n -r -k 2 

