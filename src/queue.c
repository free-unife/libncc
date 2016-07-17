/*
 * queue.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"

static _listNode _queue_gETlASTnODE (_listNode q);

bool
_queue_null (_listNode q)
{
  return (_list_null (q));
}

void
_queue_init (_listNode * qRef)
{
  _list_init (qRef);
}

static _listNode
_queue_gETlASTnODE (_listNode q)
{
  while (!_queue_null (_list_cdr (q)))
    q = _list_cdr (q);

  return q;
}

element
_queue_dequeue (_listNode * qRef)
{
  _listNode this;
  element e;

  this = _queue_gETlASTnODE (*qRef);
  e = _list_car (this);
  *qRef = _list_remove (qRef, this);

  return e;
}

void
_queue_enqueue (element e, _listNode * qRef)
{
  *qRef = _list_cons (e, *qRef);
}
