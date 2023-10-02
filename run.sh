#!/bin/bash
rm -rf bin/*
PROG_NAME=$1
# echo $PROG_NAME
output=$(g++ -std=c++20 $PROG_NAME -o bin/a -Wall -fsanitize=undefined)  #redirect the error to a variable
# echo $output              #show the error on stdout
if test -f "bin/a"; then
    echo "[WAITING FOR INPUT]"
    ./bin/a
fi
