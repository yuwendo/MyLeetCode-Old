#!/bin/sh

:<<Comments
 Problem Description - 193. Valid Phone Numbers 
 	1.  Given a text file file.txt that contains list of phone numbers (one per line), 
 		write a one liner bash script to print all valid phone numbers.

	2.  You may assume that a valid phone number must appear in one of the following two formats: 
		(xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

	3.  You may also assume each line in the text file must not contain leading or trailing white spaces.

	4.  For example, assume that file.txt has the following content:
			987-123-4567
			123 456 7890
			(123) 456-7890

	5.  Your script should output the following valid phone numbers:
			987-123-4567
			(123) 456-7890

 Reference - 
	1. http://wanggen.myweb.hinet.net/ach3/ach3.html

 Notification - 
	1. -r: regular expressions, -n:不輸出 pattern space 到螢幕

Comments

# Read from the file file.txt and output all valid phone numbers to stdout.
cat file.txt | sed -n -r  '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p'

