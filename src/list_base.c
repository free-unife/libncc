/*
 * list_base.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "utils.h"
#include "list_base.h"

bool
_list_null (_listNode l)
{
  return (l == EMPTYLIST);
}

void
_list_init (_listNode * lRef)
{
  *lRef = EMPTYLIST;
}

element
_list_car (_listNode l)
{
  assert (!_list_null (l));
  return l->el;
}

_listNode
_list_cdr (_listNode l)
{
  assert (!_list_null (l));
  return l->next;
}

_listNode
_list_cons (element e, _listNode l)
{
  _listNode n = malloc_safe (sizeof (struct _listNodeObject));

  n->el = e;
  n->next = l;

  return n;
}
