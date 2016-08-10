#!/bin/bash
set -e
umask 077

gcc -std=c11 -Wall -Wextra -Werror -o test.out test.c
./test.out
