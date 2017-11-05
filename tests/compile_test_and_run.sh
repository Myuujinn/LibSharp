#!/bin/bash

cd ..
make fclean
make debug
cd -
gcc test.c -I ../include/ -L../ -lsharp -o testing
valgrind ./testing
rm -rf testing
cd ..
make fclean
