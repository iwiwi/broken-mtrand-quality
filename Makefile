CC = gcc
CXXFLAGS = -g -std=c99 -O3 -Wall -Wextra -I.

all: bin bin/php_mt_broken bin/php_mt_fixed bin/stdlib

.PHONY: test clean

bin/php_mt_broken: main.c rand_php_mt_broken.c
	$(CC) $(CXXFLAGS) -o $@ $^ -ltestu01

bin/php_mt_fixed: main.c rand_php_mt_fixed.c
	$(CC) $(CXXFLAGS) -o $@ $^ -ltestu01

bin/stdlib: main.c rand_stdlib.c
	$(CC) $(CXXFLAGS) -o $@ $^ -ltestu01

bin:
	mkdir -p bin

clean:
	rm -rf bin
