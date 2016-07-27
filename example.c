/*
 * example.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libncc.h"

int main (void)
{
    int n = 5;
    int i;
    int *arr = malloc (sizeof (int) * n);
    list l;
    stack s;
    queue q;

    list_init (&l);
    stack_init (&s);
    queue_init (&q);

    fprintf (stderr, "l, s, q\n");

    for (i = 0; i < n; i++)
    {
        arr[i] = i;

        /* You can test both append and prepend functions here. */
        list_append (arr + i, &l);
        stack_push (arr + i, &s);
        queue_enqueue (arr + i, &q);
        fprintf (stderr, "Lengths = %d, %d, %d\n", list_length (l), 
list_length (s), list_length (q));
    }

    while (!list_null (l) || !stack_null (s) || !queue_null (q))
    {
        fprintf (stderr, "%d ", *(list_head (l)));
        list_remove (&l, l);
        fprintf (stderr, "%d ", *(stack_pop (&s)));
        fprintf (stderr, "%d ", *(queue_dequeue (&q)));
        fprintf (stderr, "\n");
    }

    fprintf (stderr, "\n");

    free (arr);

    return 0;
}
