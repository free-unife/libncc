/*
 * list_base.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined LIST_BASE_H
#define LIST_BASE_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* Include test struct header only if necessary. */
#if defined SIMPLE_TEST || defined EXTENDED_TEST
#include "test_struct.h"
#endif

#define EMPTYLIST NULL

typedef elementObject *element;

struct _listNodeObject
{
  element el;
  struct _listNodeObject *next;
};

typedef struct _listNodeObject *_listNode;

extern bool _list_null (_listNode l);
extern void _list_init (_listNode * lRef);
extern element _list_car (_listNode l);
extern _listNode _list_cdr (_listNode l);
extern _listNode _list_cons (element e, _listNode l);

#endif
