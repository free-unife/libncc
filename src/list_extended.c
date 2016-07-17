#include "list_base.h"
#include "list_extended.h"
#include "utils.h"

static _listNode _list_gETpREVnODE (_listNode lHead, _listNode nextNode);
static _listNode _list_dESTROY (_listNode * lRef, _listNode l);

_listNode
_list_copy (_listNode l)
{
  return (_list_null (l) ? EMPTYLIST
	  : _list_cons (_list_car (l), _list_copy (_list_cdr (l))));
}

/* Return a new list with l1 followed by l2. */
_listNode
_list_append (_listNode l1, _listNode l2)
{
  return (_list_null (l1) ? _list_copy (l2)
	  : _list_cons (_list_car (l1), _list_append (_list_cdr (l1), l2)));
}

/* Return a new reversed list of the input one. */
_listNode
_list_reverse (_listNode l)
{
  return (_list_null (l) ? l
	  : _list_append (_list_reverse (_list_cdr (l)),
			  _list_cons (_list_car (l), EMPTYLIST)));
}

int
_list_length (_listNode l)
{
  return (_list_null (l) ? 0 : 1 + _list_length (_list_cdr (l)));
}

/* This function creates a whole new list equal to the original one, plus the
 * new element in the tail. To avoid memory leaks, please assign the new list
 * to a new variable, and then destroy the old list.
 */
#if !defined ITERATIVE_VERSION
_listNode
_list_tailCons (element e, _listNode l)
{
  return (_list_null (l) ? _list_cons (e, EMPTYLIST)
	  : _list_cons (_list_car (l), _list_tailCons (e, _list_cdr (l))));
}

#else
_listNode
_list_tailCons (element e, _listNode l)
{
  _listNode head = l, tmp;

  if (_list_null (l))
    head = _list_cons (e, EMPTYLIST);
  else
    {
      while (!_list_null (_list_cdr (l)))
	l = _list_cdr (l);

      tmp = _list_cons (e, EMPTYLIST);
      l->next = tmp;
    }

  return head;
}
#endif

/* Equivalence function for two elements. */
bool
_list_same (_listNode l1, _listNode l2)
{
  element e1 = _list_car (l1), e2 = _list_car (l2);

  return (memcmp (e1, e2, sizeof (elementObject)) == 0);
}

bool
_list_equal (_listNode l1, _listNode l2)
{
  return (_list_null (l1) && _list_null (l2) ?
	  true
	  : (_list_null (l1) && !_list_null (l2)) || (!_list_null (l1)
						      && _list_null (l2)) ?
	  false : _list_same (l1, l2) ? _list_equal (_list_cdr (l1),
						     _list_cdr (l2)) : false);
}

/* Given the head of a list and a generic node of that same list, this
 * function finds the previous node of nextNode.
 */
static _listNode
_list_gETpREVnODE (_listNode lHead, _listNode nextNode)
{
  _listNode prevNode = lHead;

  while (!_list_null (_list_cdr (lHead)))
    {
      if (_list_same (_list_cdr (lHead), nextNode))
	prevNode = lHead;

      lHead = _list_cdr (lHead);
    }

  return prevNode;
}

/* Given the head of the list and the node to remove, that node gets removed.
 * This is not a functional language procedure (i.e: it affects the state of
 * other lists if these have shared elements with the input one), so be careful
 * when using it.
 */
_listNode
_list_remove (_listNode * lHeadRef, _listNode toRemove)
{
  _listNode toBeDel;
  _listNode prevNode;

  assert (!element_null (*lHeadRef));
  prevNode = _list_gETpREVnODE (*lHeadRef, toRemove);

  /* If there is only one element in the list and needs to be deleted. */
  if (toRemove == *lHeadRef)
    {
      toBeDel = *lHeadRef;
      *lHeadRef = _list_cdr (*lHeadRef);
    }
  else
    {
      toBeDel = _list_cdr (prevNode);
      prevNode->next = _list_cdr (_list_cdr (prevNode));
    }

  free (toBeDel);
  toBeDel = NULL;

  return *lHeadRef;
}

/* Remove the whole list. This is a wrapper that avoids having two input
 * arguments.
 */
_listNode
_list_destroy (_listNode * lRef)
{
  return (_list_dESTROY (lRef, *lRef));
}

static _listNode
_list_dESTROY (_listNode * lRef, _listNode l)
{
  return (_list_null (l) ? EMPTYLIST
	  : _list_dESTROY (lRef, _list_remove (lRef, l)));
}
