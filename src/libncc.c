/*
 * libncc.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "libncc.h"

bool
list_null (list l)
{
  return (_list_null (l));
}

void
list_init (list * lRef)
{
  _list_init (lRef);
}

element
list_car (list l)
{
  return (_list_car (l));
}

list
list_cdr (list l)
{
  return (_list_cdr (l));
}

list
list_cons (element e, list l)
{
  return (_list_cons (e, l));
}

list
list_append (list l1, list l2)
{
  return (_list_append (l1, l2));
}

list
list_copy (list l)
{
  return (_list_copy (l));
}

list
list_reverse (list l)
{
  return (_list_reverse (l));
}

int
list_length (list l)
{
  return (_list_length (l));
}

list
list_tailCons (element e, list l)
{
  return (_list_tailCons (e, l));
}

bool
list_same (list l1, list l2)
{
  return (_list_same (l1, l2));
}

bool
list_equal (list l1, list l2)
{
  return (_list_equal (l1, l2));
}

list
list_remove (list * lHeadRef, list toRemove)
{
  return (_list_remove (lHeadRef, toRemove));
}

list
list_destroy (list * lRef)
{
  return (_list_destroy (lRef));
}

bool
stack_null (stack s)
{
  return (_stack_null (s));
}

void
stack_init (stack * sRef)
{
  _stack_init (sRef);
}

element
stack_pop (stack * sRef)
{
  return (_stack_pop (sRef));
}

void
stack_push (element e, stack * sRef)
{
  _stack_push (e, sRef);
}

bool
queue_null (queue q)
{
  return (_queue_null (q));
}

void
queue_init (queue * qRef)
{
  _queue_init (qRef);
}

element
queue_dequeue (queue * qRef)
{
  return (_queue_dequeue (qRef));
}

void
queue_enqueue (element e, queue * qRef)
{
  _queue_enqueue (e, qRef);
}
