#!/bin/sh

# Reference: http://wanggen.myweb.hinet.net/ach3/ach3.html 
# -r: regular expressions, -n:不輸出 pattern space 到螢幕
cat file.txt | sed -n -r  '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p'

