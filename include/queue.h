/*
 * queue.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined QUEUE_H
#define QUEUE_H

extern bool _queue_null (_listNode q);
extern void _queue_init (_listNode * qRef);
extern element _queue_dequeue (_listNode * qRef);
extern void _queue_enqueue (element e, _listNode * qRef);

#endif
