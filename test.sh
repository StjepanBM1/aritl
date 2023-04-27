#!/bin/sh

printf "\t ===| ARITL software test suite |===\n"

for i in test/errors/*.al ; do

    printf "\t\t > %s" $i
    ./aritl $i > /dev/null 2>&1

    if [ $? -eq 0 ] ; then
        printf "\t > \033[1;32mOK\033[0m\n"
    else
        printf "\t > \033[1;31mFAIL\033[0m\n"
    fi

done

for i in test/func/*.al ; do

    printf "\t\t > %s" $i
    ./aritl $i > /dev/null 2>&1

    if [ $? -eq 0 ] ; then
        printf "\t > \033[1;32mOK\033[0m\n"
    else
        printf "\t > \033[1;31mFAIL\033[0m\n"
    fi

done

for i in test/math/*.al ; do

    printf "\t\t > %s" $i
    ./aritl $i > /dev/null 2>&1

    if [ $? -eq 0 ] ; then
        printf "\t > \033[1;32mOK\033[0m\n"
    else
        printf "\t > \033[1;31mFAIL\033[0m\n"
    fi

done
