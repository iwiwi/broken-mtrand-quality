CC = gcc
CXXFLAGS = -g -std=c99 -O3 -Wall -Wextra -pthread -I. -ltestu01

all: bin bin/php_mt_broken bin/php_mt_fixed bin/stdlib

.PHONY: test clean

bin/php_mt_broken: main.c rand_php_mt_broken.c
	$(CC) $(CXXFLAGS) -o $@ $^

bin/php_mt_fixed: main.c rand_php_mt_fixed.c
	$(CC) $(CXXFLAGS) -o $@ $^

bin/stdlib: main.c rand_stdlib.c
	$(CC) $(CXXFLAGS) -o $@ $^

bin:
	mkdir -p bin

clean:
	rm -rf bin
