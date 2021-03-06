#!/bin/bash
set -e
umask 077

gcc -std=c11 -include "belse/std_c.h" -Wall -Wextra -Werror -o test.out test.c -fsanitize=address
./test.out

musl-gcc -std=c11 -include "belse/std_c.h" -Wall -Wextra -Werror -o test.musl.out test.c
./test.musl.out
