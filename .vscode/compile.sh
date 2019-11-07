#! /bin/sh
FILES=$(find $1 -type f -name *.c -print)
gcc -g $FILES -o $1/a.out
