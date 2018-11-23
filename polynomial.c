/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * polynomial.c
 * 
 * C file for polynomial data type and the functions
 * to manipulate the polynomials and to create structure for polynomial ADT
 * 
 * Authors: Mike Vriesema 17212359 
 * 			Luke O'Sullivan Griffin 17184614 
 * 			Ryan O'Connor 17209382 
 * 			Conall McAteer 18173586 
 * 			Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 23.11.2018
 *///////////////////////////////////////////////////////////////////////


#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"


// listCreate()
// creates an empty linked list, head points to tail
// which is implemented as NULL
// 
// parameter: none
// return: pointer to list if success
//         pointer to NULL on failure
polynomial *listCreate() 
{
  polynomial *list;
  list = (polynomial *) malloc(sizeof(polynomial));
  // check for allocation success
  if (list != NULL) {
    // attempt to allocate memory for head
    list->head = (polyNode *) malloc(sizeof(polyNode));
    if (list->head != NULL) {
      // allocation successfull, satisfy condition
      // that head points to tail (NULL) and current is head
      list->head->successor = NULL;
      list->current = list->head;
    } else {
      // need to de-allocate list and set it to NULL
      free(list);
      list = NULL;
    }
  }
  // returned value is as desired, failure of malloc()
  // will return NULL which indicates also invalid
  // linked list
  return list;
  }

///////////////////////////////////////////////////////
// listDelete(list)
// deletes the entire list of which head is head-node
// 
// parameter:	head - head of a valid list
// return:		void
///////////////////////////////////////////////////////
void listDelete(polynomial *list) 
{
  polyNode *next;
  
  // delete all nodes until list is empty
  // start at beginning of list
  list->current = list->head;
  // iterate through all nodes in list and delete them
  while (list->head->successor != NULL) {
    next = list->head->successor;
    list->head->successor = list->head->successor->successor;
    free(next);
  }
  // while loop can be achieved in a single line - any ideas?  
    
  // now list is empty, only need to delete head 
  // and list itself
  free(list->head);
  free(list);
}

///////////////////////////////////////////////////////
// insertAfter(d, list)
// creates a new node newnode, associates data d with
// newnode and inserts newnode in linse as successor of 
// current node
//
// parameter: d - data to be associated with newnode
//            list - list into which to insert d
// return: ok - insertion successful
//         noMemory - no memory available to create newnode
///////////////////////////////////////////////////////
polyError insertAfter(term *d, polynomial *list) 
{
  polyError returnvalue = ok;
  polyNode *newnode;
  
  // create new node
  newnode = (polyNode *) malloc(sizeof(polyNode));
  // allocation successful?
  if (newnode == NULL) {
    // allocation failure
    returnvalue = noMemory;
  } else {
    // allocation successful
    // associate data d with newnode
    newnode->d = *d;
    // link newnode into linked list
    // 1. set succcessor of newnode to current nodes's successor
    newnode->successor = list->current->successor;
    // 2. set successor of current node to newnode
    list->current->successor = newnode;
  }
  return returnvalue;
}

///////////////////////////////////////////////////////
// deleteNext(list)
// removes successor of node from linked list
//
// parameter: list - pointer to list from which node is
//                   to be removed
// return: ok - node has been removed
//         illegalNode - cannot remove as successor
//                       of current is tail
///////////////////////////////////////////////////////
polyError deleteNext(polynomial *list)
{
  polyError result = ok;
  polyNode *todelete;
  if (list->current->successor == NULL) {
    // successor of current is tail => cannot remove node
    result = illegalNode;
  } else {
    // 1. keep pointer to node to be deleted
    todelete = list->current->successor;
    // 2. set successor of current to successor of node to be deleted
    list->current->successor = todelete->successor;
    // 3. delete node from memory
    free(todelete);
  }
  return result;
}

///////////////////////////////////////////////////////
// gotoHead(list)
// sets current node of list to head
//
// parameter: list - list to be reset
// return: void
///////////////////////////////////////////////////////
void gotoHead(polynomial *list) 
{
  // reset curren to head
  list->current = list->head;
}

///////////////////////////////////////////////////////
// gotoNextNode(list)
// sets current node of list to its successor
//
// parameter: list - list to be traversed
// return: ok - current has been set to successor
//         illegalNode - successor of current it tail
///////////////////////////////////////////////////////
polyError gotoNextNode(polynomial *list)
{
  polyError result = ok;
  // is successor of current tail?
  if (list->current->successor != NULL) {
    // no -> move forward
    list->current = list->current->successor;
  } else {
    // reached end of list, cannot move any further
    result = illegalNode;
  }
  return result;
}

///////////////////////////////////////////////////////
// accessData
// returns data of current node
//
// parameter: list - list to be accessed
// return: if current is head or tail: NULL
//         otherwise, data of current node
///////////////////////////////////////////////////////
term *accessData(polynomial *list) 
{
  // is current head or tail?
  if (list->current != list->head && list->current != NULL) {
    // no, return data
    return &(list->current->d);
  } else {
    // yes, return NULL
    return NULL;
  }
} 

/*
	Function that obtains required data for a polynomial from
	the user, constructs a polynomial (linked list of terms)
	and returns a pointer to the first (head) term.
*/
polynomial create(){
	polynomial p;
	return p;
}

/*
	Function that takes in a polynomial and deletes it
*/
void deletePoly(polynomial p){
	printf("Poly deleted");
}

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of adding polynomials p1 and p2
*/
polynomial addPoly(polynomial p1, polynomial p2){
	polynomial p;
	return p;
}

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of subtracting polynomial p2 from p
*/
polynomial subtractPoly(polynomial p1, polynomial p2){
	polynomial p;
	return p;
}

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of multiplying polynomial p and double value
*/
polynomial multiplyPoly(polynomial p, double value){
	polynomial p;
	return p;
}

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of dividing polynomial p and double value
*/
polynomial dividePoly(polynomial p, double value){
	polynomial p;
	return p;
}

/*
	Function that normalises the polynomial adjusting the coefficients so that
    the coefficient of the highest order is 1
*/
polynomial normalisePoly(polynomial p){
	polynomial p;
	return p;
}

/*
	Function that displays the highest order of the polynomial
    returning the highest power and the coefficient
*/
polynomial orderPoly(polynomial p){
	polynomial p;
	return p;
}

/*
	Function that displays the polynomial to the standard output
	in the traditional mathematical form
*/
void display(polynomial p){
	polynomial p;
	return p;
}
