/*
 * stack.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined STACK_H
#define STACK_H

extern bool _stack_null (_listNode s);
extern void _stack_init (_listNode * sRef);
extern element _stack_pop (_listNode * sRef);
extern void _stack_push (element e, _listNode * sRef);

#endif
