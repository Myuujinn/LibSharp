#!/bin/bash

cd ..
make re
cd -
gcc test.c -I ../include/ -L../ -lsharp -o testing
./testing
rm -rf testing
