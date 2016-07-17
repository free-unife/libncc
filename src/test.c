/*
 * test.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"
#include "libncc.h"
#include "queue.h"
#include "stack.h"
#include "test.h"
#include "utils.h"

#define n TEST_ITERATIONS

#if defined SIMPLE_TEST
static int *array_set (int length);

static int *
array_set (int length)
{
  int i;
  int *arr = malloc_safe (sizeof (int) * length);

  for (i = 0; i < length; i++)
    arr[i] = i;

  return arr;
}

#if defined LIST_BASE_C
int
main (void)
{
  int *aPointer, *bPointer, theSourceZero = 10, theSourceOne = 28;
  _listNode l = NULL;

  aPointer = &theSourceZero;
  l = _list_cons (aPointer, l);

  bPointer = &theSourceOne;
  l = _list_cons (bPointer, l);

  assert (_list_car (l) == bPointer);
  assert (_list_car (_list_cdr (l)) == aPointer);

  /* Dummy. */
  array_set (0);

  return 0;
}


#elif defined LIST_EXTENDED_C
static _listNode fakeList_new (int length, int *arr, char action);
static void fakeList_print (_listNode this);

static _listNode
fakeList_new (int length, int *arr, char action)
{
  int i;
  _listNode this, that;

  _list_init (&this);
  for (i = 0; i < length; i++)
    {
      if (action == 'h')
	this = _list_cons ((arr + i), this);
      else if (action == 't')
	{
	  that = _list_tailCons ((arr + i), this);
	  _list_destroy (&this);
	  this = that;
	}
    }

  return this;
}

static void
fakeList_print (_listNode this)
{
  while (!_list_null (this))
    {
      fprintf (stderr, "%d ", *(_list_car (this)));
      this = _list_cdr (this);
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  _listNode this, tmp, that;

  for (i = 0; i <= n; i++)
    {
      /* Allocation of an int array corresponding to _listNode -> el. */
      arr = array_set (i);

      /* Create a list and remove an element. */
      _list_init (&this);
      this = fakeList_new (i, arr, 'h');
      fakeList_print (this);
      assert (_list_length (this) == i);
      if (i >= 2)
	{
	  _list_remove (&this, this);
	  assert (_list_length (this) == i - 1);
	}
      _list_destroy (&this);

      /* State that given a same input, the two generated lists are equal. */
      _list_init (&this);
      _list_init (&tmp);
      this = fakeList_new (i, arr, 'h');
      tmp = fakeList_new (i, arr, 'h');
      assert (_list_equal (this, tmp));
      _list_destroy (&this);
      _list_destroy (&tmp);

      this = fakeList_new (i, arr, 't');
      tmp = fakeList_new (i, arr, 't');
      _list_init (&that);
      that = _list_append (this, tmp);
      assert (_list_length (that) ==
	      _list_length (this) + _list_length (tmp));
      _list_destroy (&this);
      _list_destroy (&tmp);
      _list_destroy (&that);

      _list_init (&this);
      _list_init (&that);
      _list_init (&tmp);
      that = _list_reverse (this);
      tmp = _list_reverse (that);
      assert (_list_equal (this, tmp));
      _list_destroy (&this);
      _list_destroy (&that);
      _list_destroy (&tmp);


      free (arr);
    }

  return 0;
}

#elif defined STACK_C
static void fakeStack_new (int length, int *arr, _listNode * sRef);
static void fakeStack_print (_listNode * this);

static void
fakeStack_new (int length, int *arr, _listNode * sRef)
{
  int i;

  for (i = 0; i < length; i++)
    _stack_push ((arr + i), sRef);
}

static void
fakeStack_print (_listNode * this)
{
  while (!_stack_null (*this))
    fprintf (stderr, "%d ", *(_stack_pop (this)));

  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  _listNode s;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      _stack_init (&s);
      fakeStack_new (i, arr, &s);
      fakeStack_print (&s);
      assert (_stack_null (s));

      free (arr);
    }

  return 0;
}

#elif defined QUEUE_C
static void fakeQueue_new (int length, int *arr, _listNode * qRef);
static void fakeQueue_print (_listNode * this);

static void
fakeQueue_new (int length, int *arr, _listNode * qRef)
{
  int i;

  for (i = 0; i < length; i++)
    _queue_enqueue ((arr + i), qRef);
}

static void
fakeQueue_print (_listNode * this)
{
  while (!_queue_null (*this))
    fprintf (stderr, "%d ", *(_queue_dequeue (this)));

  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  _listNode q;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      _queue_init (&q);
      fakeQueue_new (i, arr, &q);
      fakeQueue_print (&q);
      assert (_queue_null (q));

      free (arr);
    }

  return 0;
}

#elif defined API
int
main (void)
{
  int i, j;
  int *arr;
  list l, *lHead;
  stack s;
  queue q;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      list_init (&l);
      stack_init (&s);
      queue_init (&q);

      for (j = 0; j < i; j++)
	{
	  l = list_cons (arr + j, l);
	  stack_push (arr + j, &s);
	  queue_enqueue (arr + j, &q);
	}

      assert (list_length (l) == i);
      assert (list_length (s) == i);
      assert (list_length (q) == i);

      lHead = &l;
      for (j = 0; j < i; j++)
	{
	  *lHead = list_remove (lHead, *lHead);
	  stack_pop (&s);
	  queue_dequeue (&q);
	}

      assert (list_null (l) && stack_null (s) && queue_null (q));

      free (arr);
    }

  return 0;
}

#endif

#elif defined EXTENDED_TEST
static struct VertexObject **array_new (int length);
static void array_clean (struct VertexObject ***vArr, int length);

static struct VertexObject **
array_new (int length)
{

  struct VertexObject **vArr =
    malloc_safe (sizeof (struct VertexObject *) * length);
  char *color;
  int i;

  for (i = 0; i < length; i++)
    {
      vArr[i] = malloc_safe (sizeof (struct VertexObject));
      color = malloc_safe (sizeof (char) * 16);
      vArr[i]->id = i;
      vArr[i]->d = i - 32;
      vArr[i]->f = i * 2;
      ((i % 2) == 0 ? strcpy (color, "WHITE") : strcpy (color, "BLACK"));
      vArr[i]->color = color;
    }

  return vArr;
}

static void
array_clean (struct VertexObject ***vArr, int length)
{
  int i;

  for (i = 0; i < length; i++)
    {
      free ((*vArr)[i]->color);
      free ((*vArr)[i]);
    }

  free (*vArr);
}

#if defined LIST_EXTENDED_C
static _listNode fakeList_new (int length, struct VertexObject **vArr);
static _listNode fakeList_search (_listNode l, char *color);
static void fakeList_print (_listNode this);

static _listNode
fakeList_new (int length, struct VertexObject **vArr)
{
  int i;
  _listNode this;

  _list_init (&this);
  for (i = 0; i < length; i++)
    this = _list_cons (vArr[i], this);

  return this;
}

/* Return a list of all the _listNodes with the input colour. */
static _listNode
fakeList_search (_listNode l, char *color)
{
  _listNode head;

  _list_init (&head);
  while (!_list_null (l))
    {
      if (strcmp (l->el->color, color) == 0)
	head = _list_cons (_list_car (l), head);
      l = _list_cdr (l);
    }

  return head;
}

static void
fakeList_print (_listNode this)
{
  while (!_list_null (this))
    {
      fprintf (stderr, "%d ", (_list_car (this))->id);
      this = _list_cdr (this);
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  struct VertexObject **vArr;
  _listNode this, that;

  for (i = 0; i <= n; i++)
    {
      vArr = array_new (i);

      _list_init (&this);
      fakeList_print (this);
      _list_init (&that);
      this = fakeList_new (i, vArr);
      that = fakeList_search (this, "WHITE");
      assert ((_list_length (this) == _list_length (that) * 2)
	      || (_list_length (this) == (_list_length (that) * 2) - 1));

      _list_destroy (&that);
      _list_destroy (&this);
      array_clean (&vArr, i);
    }

  return 0;
}
#elif defined STACK_C
static void fakeStack_new (int length, struct VertexObject **vArr,
			   _listNode * sRef);
static void fakeStack_search (_listNode * sRef, _listNode * nRef,
			      char *color);
static void fakeStack_print (_listNode * sRef);

static void
fakeStack_new (int length, struct VertexObject **vArr, _listNode * sRef)
{
  int i;

  for (i = 0; i < length; i++)
    _stack_push (vArr[i], sRef);
}

/* Return a list of all the _listNodes with the input colour. */
static void
fakeStack_search (_listNode * sRef, _listNode * nRef, char *color)
{
  element el;

  while (!_stack_null (*sRef))
    {
      el = _stack_pop (sRef);
      if (strcmp (el->color, color) == 0)
	_stack_push (el, nRef);
    }
}

static void
fakeStack_print (_listNode * sRef)
{
  element el;

  /* Print all the fields. */
  while (!_stack_null (*sRef))
    {
      el = _stack_pop (sRef);

      fprintf (stderr, "%d ", el->id);
      fprintf (stderr, "%s ", el->color);
      fprintf (stderr, "%d ", el->d);
      fprintf (stderr, "%d ", el->f);
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  struct VertexObject **vArr;
  _listNode s, newStack;

  for (i = 0; i <= n; i++)
    {
      vArr = array_new (i);
      _stack_init (&s);
      _stack_init (&newStack);
      fakeStack_new (i, vArr, &s);
      fakeStack_search (&s, &newStack, "WHITE");
      assert (_stack_null (s));
      assert (_list_length (newStack) <= i);
      fakeStack_print (&newStack);

      array_clean (&vArr, i);
    }

  return 0;
}
#elif defined QUEUE_C
static void fakeQueue_new (int length, struct VertexObject **vArr,
			   _listNode * qRef);
static void fakeQueue_search (_listNode * qRef, _listNode * nRef,
			      char *color);
static void fakeQueue_print (_listNode * qRef);

static void
fakeQueue_new (int length, struct VertexObject **vArr, _listNode * qRef)
{
  int i;

  for (i = 0; i < length; i++)
    _queue_enqueue (vArr[i], qRef);
}

/* Return a list of all the _listNodes with the input colour. */
static void
fakeQueue_search (_listNode * qRef, _listNode * nRef, char *color)
{
  element el;

  while (!_queue_null (*qRef))
    {
      el = _queue_dequeue (qRef);
      if (strcmp (el->color, color) == 0)
	_queue_enqueue (el, nRef);
    }
}

static void
fakeQueue_print (_listNode * qRef)
{
  element el;

  /* Print all the fields. */
  while (!_queue_null (*qRef))
    {
      el = _queue_dequeue (qRef);

      fprintf (stderr, "%d ", el->id);
      fprintf (stderr, "%s ", el->color);
      fprintf (stderr, "%d ", el->d);
      fprintf (stderr, "%d ", el->f);
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  struct VertexObject **vArr;
  _listNode q, newQueue;

  for (i = 0; i <= n; i++)
    {
      vArr = array_new (i);
      _queue_init (&q);
      _queue_init (&newQueue);
      fakeQueue_new (i, vArr, &q);
      fakeQueue_search (&q, &newQueue, "WHITE");
      assert (_queue_null (q));
      assert (_list_length (newQueue) <= i);
      fakeQueue_print (&newQueue);

      array_clean (&vArr, i);
    }

  return 0;
}
#endif

#endif
