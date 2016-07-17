/*
 * list_extended.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined LIST_EXTENDED_H
#define LIST_EXTENDED_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

extern _listNode _list_append (_listNode l1, _listNode l2);
extern _listNode _list_copy (_listNode l);
extern _listNode _list_reverse (_listNode l);
extern int _list_length (_listNode l);
extern _listNode _list_tailCons (element e, _listNode l);
extern bool _list_same (_listNode l1, _listNode l2);
extern bool _list_equal (_listNode l1, _listNode l2);
extern _listNode _list_remove (_listNode * lHeadRef, _listNode toRemove);
extern _listNode _list_destroy (_listNode * lRef);
#endif
