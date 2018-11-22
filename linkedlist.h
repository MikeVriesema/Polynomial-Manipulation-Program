/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * linkedlist.h
 * 
 * Header file for linked list type and the function declarations
 * to order add and remove to the list
 * 
 * Authors: Mike Vriesema 17212359 
 * 			Luke O'Sullivan Griffin 17184614 
 * 			Ryan O'Connor 17209382 
 * 			Conall McAteer 18173586 
 * 			Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 22.11.2018
 *///////////////////////////////////////////////////////////////////////

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "polynomial.h"

// DEFINE ERROR CODES FOR LINKED LIST
typedef enum {ok, illegalNode, noMemory} llError;


// DEFINE STRUCTURE FOR A NODE OF LINKED LIST
typedef struct n {
  poly d; // store some data in node
  struct n *successor; // store successor of node
               // as typedef is not yet completed
               // name llnode cannot be used
} llnode;

// DEFINE TYPE FOR LINKED LIST
typedef struct {
  llnode *head;
  llnode *current;
} llist;

/**
 * FUNCTION DECLARATIONS:(IN DEPTH COMMENTS IN linkedlist.c FILE)
 * *listCreate
 * listDelete
 * *accessData
 * insertAfter
 * deleteNext
 * gotoHead
 * gotoNextNode
 */
llist *listCreate();
void listDelete(llist *list);
poly *accessData(llist *list);
llError insertAfter(poly *d, llist *list);
llError deleteNext(llist *list);
void gotoHead(llist *list);
llError gotoNextNode(llist *list);

#endif
