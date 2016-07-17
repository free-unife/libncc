/*
 * libncc.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined NCCLIB_H
#define NCCLIB_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_base.h"
#include "list_extended.h"
#include "stack.h"
#include "queue.h"

typedef _listNode list;
typedef _listNode stack;
typedef _listNode queue;

extern bool list_null (list l);
extern void list_init (list * lRef);
extern element list_car (list l);
extern list list_cdr (list l);
extern list list_cons (element e, list l);
extern list list_append (list l1, list l2);
extern list list_copy (list l);
extern list list_reverse (list l);
extern int list_length (list l);
extern list list_tailCons (element e, list l);
extern bool list_same (list l1, list l2);
extern bool list_equal (list l1, list l2);
extern list list_remove (list * lHeadRef, list toRemove);
extern list list_destroy (list * lRef);
extern bool stack_null (stack s);
extern void stack_init (stack * sRef);
extern element stack_pop (stack * sRef);
extern void stack_push (element e, stack * sRef);
extern bool queue_null (queue q);
extern void queue_init (queue * qRef);
extern element queue_dequeue (queue * qRef);
extern void queue_enqueue (element e, queue * qRef);

#endif
