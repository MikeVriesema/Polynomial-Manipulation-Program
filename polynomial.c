/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * polynomial.c
 * 
 * C file for polynomial data type and the functions
 * to manipulate the polynomials and to create structure for polynomial ADT
 * 
 * Authors: 
 *      Mike Vriesema 17212359 
 * 			Luke O'Sullivan Griffin 17184614 
 * 			Ryan O'Connor 17209382 
 * 			Conall McAteer 18173586 
 * 			Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 23.11.2018
 */
//////////////////////////////////////////////////////////////////////

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
polynomial* createPoly()
{
    int exponent;
    printf("\nPlease enter degree of polynomial:");
    scanf("%d", &exponent);
    polynomial* list;
    list = (polynomial*)malloc(sizeof(polynomial));
    // check for allocation success
    if (list != NULL) {
        // attempt to allocate memory for head
        list->head = (polyNode*)malloc(sizeof(polyNode));
        if (list->head != NULL) {
            // allocation successfull, satisfy condition
            // that head points to tail (NULL) and current is head
            list->head->successor = NULL;
            list->current = list->head;
            for (int i = exponent; i >= 0; i--) {
                insertAfter(list, i);
            }
        }
        else {
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
void deletePoly(polynomial* poly)
{
    polyNode* next;
    if (poly != NULL) {
        // delete all nodes until list is empty
        // start at beginning of list
        poly->current = poly->head;
        // iterate through all nodes in list and delete them
        while (poly->head->successor != NULL) {
            next = poly->head->successor;
            poly->head->successor = poly->head->successor->successor;
            free(next);
        }
        // while loop can be achieved in a single line - any ideas?

        // now list is empty, only need to delete head
        // and list itself
        free(poly->head);
        free(poly);
        printf("Polynomial Deleted!\n");
    }
    else {
        printf("You must create a linked list first ...\n");
    }
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
polyError insertAfter(polynomial* poly, int exponent)
{
    polyError returnvalue = ok;
    polyNode* newnode;
    term newdata;
    printf("Please enter Coefficient: ");
    scanf("%lf", &newdata.coefficient);
    newdata.exponent = exponent;

    // create new node
    newnode = (polyNode*)malloc(sizeof(polyNode));
    // allocation successful?
    if (newnode == NULL) {
        // allocation failure
        returnvalue = noMemory;
    }else {
        // allocation successful
        // associate data d with newnode
        newnode->d = newdata;
        newnode->successor=NULL;

    if(poly->head==NULL)
    {
      poly->head=newnode;
      poly->current=newnode;
    }
    else
    {
      polyNode* temp = poly->head;
        while(temp->successor!=NULL)
        {
        temp = temp->successor;
        }
      temp->successor = newnode;
    }
        }


    return returnvalue;
}

///////////////////////////////////////////////////////
// gotoHead(list)
// sets current node of list to head
//
// parameter: list - list to be reset
// return: void
///////////////////////////////////////////////////////
void gotoHead(polynomial* poly)
{
    // reset curren to head
    poly->current = poly->head;
}

///////////////////////////////////////////////////////
// gotoNextNode(list)
// sets current node of list to its successor
//
// parameter: list - list to be traversed
// return: ok - current has been set to successor
//         illegalNode - successor of current it tail
///////////////////////////////////////////////////////
polyError gotoNextNode(polynomial* poly)
{
    polyError result = ok;
    // is successor of current tail?
    if (poly->current->successor != NULL) {
        // no -> move forward
        poly->current = poly->current->successor;
    }
    else {
        // reached end of poly, cannot move any further
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
term* accessData(polynomial* poly)
{
    // is current head or tail?
    if (poly->current != poly->head && poly->current != NULL) {
        // no, return data
        return &(poly->current->d);
    }
    else {
        // yes, return NULL
        return NULL;
    }
}

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of adding polynomials p1 and p2
*/
polynomial* addPoly(polynomial* p1, polynomial* p2){
    if (p1 != NULL && p2 != NULL) {
        gotoHead(p1);
        gotoHead(p2);
        printf("Adding polynomial 1 and polynomial 2:");
        while (gotoNextNode(p1) == ok && gotoNextNode(p2) == ok) {
            term* a = accessData(p1);
            term* b = accessData(p2);
            int aExp = a->exponent;
            int bExp = b->exponent; //FOR CROSS ORDER POLY BUILDING
            double aCoeff = a->coefficient;
            double bCoeff = b->coefficient;
            double answer = aCoeff + bCoeff;
            a->coefficient = answer;
        }
        displayPoly(p1);
    }
    else {
        printf("No polynomial found.");
    }
    return p1;
}

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of subtracting polynomial p2 from p
*/
polynomial* subtractPoly(polynomial* p1, polynomial* p2)
{
    if (p1 != NULL && p2 != NULL) {
        gotoHead(p1);
        gotoHead(p2);
        printf("Subtracting polynomial 1 and polynomial 2");
        while (gotoNextNode(p1) == ok && gotoNextNode(p2) == ok) {
            term* a = accessData(p1);
            term* b = accessData(p2);
            double aCoeff = a->coefficient;
            double bCoeff = b->coefficient;
            double answer = aCoeff - bCoeff;
            a->coefficient = answer;
        }
        displayPoly(p1);
    }
    else {
        printf("No polynomial found.");
    }
    return p1;
}

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of multiplying polynomial p and double value
*/
polynomial* multiplyPoly(polynomial* p)
{
    gotoHead(p);
    double value = 4;

    if (p != NULL) {
      printf("Multiplying by %0.lf",value);
        while (gotoNextNode(p) == ok) {
            term* polyTerm = accessData(p);
            double multiplyResult = (polyTerm->coefficient);
            multiplyResult = multiplyResult * value;
            polyTerm->coefficient = multiplyResult;
        }
        printf("\nNew Polynomial: ");
        displayPoly(p);
    }
    else {
        printf("Create a polynomial");
    }
    return p;
}

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of dividing polynomial p and double value
*/
polynomial* dividePoly(polynomial* p)
{
    gotoHead(p);
    double value = 2;

    if (p != NULL) {
      printf("Dividing by %0.lf",value);
        while (gotoNextNode(p) == ok) {
            term* polyTerm = accessData(p);
            double divideResult = (polyTerm->coefficient);
            divideResult = divideResult / value;
            polyTerm->coefficient = divideResult;
        }
        printf("\nNew Polynomial: ");
        displayPoly(p);
    }
    else {
        printf("Create a polynomial");
    }
    return p;
}

/*
	Function that normalises the polynomial adjusting the coefficients so that
    the coefficient of the highest order is 1
*/
polynomial* normalisePoly(polynomial* p)
{
}

/*
	Function that displays the highest order of the polynomial
    returning the highest power and the coefficient
*/
void orderPoly(polynomial* p)
{
    if (p != NULL) {
        gotoHead(p);
        if (gotoNextNode(p) == ok) {
            term* d = accessData(p);
            printf("Order of polynomial: %d\n", d->exponent);
        }
        else {
            printf("You must create a linked list first ...\n");
        }
    }
}

/*
	Function that displays the polynomial to the standard output
	in the traditional mathematical form
*/
void displayPoly(polynomial* mylist)
{
    if (mylist != NULL) {
        // start at head
        gotoHead(mylist);
        if (mylist->head->successor == NULL) {
            printf("No polynomial found!\n");
        }
        else {
            do {
                // print current node
                if (mylist->current == mylist->head) {
                    printf("\nPolynomial = ");
                }
                else {
                    term* d = accessData(mylist);
                    if (d->coefficient > 0) {
                        if (d->exponent == 1) {
                            printf("+%.0lfX ", d->coefficient);
                        }
                        else if (d->exponent == 0) {
                            printf("+%.0lf ", d->coefficient);
                        }
                        else {
                            printf("+%.0lfX^%d ", d->coefficient, d->exponent);
                        }
                    }
                    else {
                        if (d->exponent == 1) {
                            printf("%.0lfX ", d->coefficient);
                        }
                        else if (d->exponent == 0) {
                            printf("%.0lf ", d->coefficient);
                        }
                        else {
                            printf("%.0lfX^%d ", d->coefficient, d->exponent);
                        }
                    }
                }
                // goto next node in list
            } while (gotoNextNode(mylist) == ok);
            printf("\n\n");
        }
    }
    else {
        printf("You must create a linked list first ...\n");
    }
}
