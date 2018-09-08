#!/bin/bash
gcc -Wall -g -std=c11 -c -o Vector.o Vector.c
gcc -Wall -g -std=c11 -c -o ex5.o ex5.c
gcc -Wall -g -std=c11 -o ex5 ex5.o Vector.o
echo "done"
