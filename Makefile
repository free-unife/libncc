#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

# Recipe
# make libncc TYPE=<C type>

TYPE=int
CC = /usr/bin/gcc
INCLUDEDIR = -Iinclude
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lrt
CSTANDARD = -std=c99
DEFFLAG = -DelementObject=$(TYPE)

default: libncc

clean:
	@echo "Removing object files..."
	@rm -fv *.o *.out *.a *.pdf
	@echo "Object files removed."

libncc:
	@$(MAKE) -C src
	@mv src/$@.a .
	@$(MAKE) -C src clean

doc:
	@$(MAKE) -C $@
	@mv $@/libncc.pdf .

example: libncc
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out example.c libncc.a
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out example.c libncc.a"

.PHONY: default libncc doc example

