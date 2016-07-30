#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

TYPE=struct\ example
CC = /usr/bin/gcc
INCLUDEDIR = -I../include
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lrt
CSTANDARD = -std=c99
DEFFLAG = -DelementObject=$(TYPE)

default: example

clean:
	@echo "Removing object files..."
	@rm -fv *.o *.out *.a
	@echo "Object files removed."

libncc:
	@$(MAKE) -C ../
	@mv ../$@.a .

example: libncc
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out example.c libncc.a
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out example.c libncc.a"

.PHONY: default libncc example

