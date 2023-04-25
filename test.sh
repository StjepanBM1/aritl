#!/bin/sh

printf "\t ===| ARITL software test suite |===\n"

for i in test/*.al ; do

    printf "\t\t > %s" $i
    ./aritl $i > /dev/null 2>&1

    if [ $? -eq 0 ] ; then
        printf "\t > OK\n"
    else
        printf "\t > FAIL\n"
    fi

done
