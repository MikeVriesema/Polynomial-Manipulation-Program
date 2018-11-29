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
 * Date Last Modified: 29.11.2018
 *///////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

/*
 * createPoly(int exponent)
 * creates an empty polynomial, head points to tail
 * which is implemented as NULL
 *
 * parameter: none
 * return: pointer to polynomial if success
 *         pointer to NULL on failure
 */
polynomial* createPoly(int value){   
    int exponent = value;
    polynomial* poly;
    poly = (polynomial*)malloc(sizeof(polynomial));
    // check for allocation success
    if (poly != NULL) {
        // attempt to allocate memory for head
        poly->head = (polyNode*)malloc(sizeof(polyNode));
        if (poly->head != NULL) {
            // allocation successfull, satisfy condition
            // that head points to tail (NULL) and current is head
            poly->head->successor = NULL;
            poly->current = poly->head;
            for (int i = exponent; i >= 0; i--) {
                insertAfter(poly, i, (2.0+(i))); //JUST TO GET DIFFERENT COEFFICIENTS
            }
        }
        else {
            // need to de-allocate poly and set it to NULL
            free(poly);
            poly = NULL;
        }
    }
    return poly;
}
// returned value is as desired, failure of malloc()
// will return NULL which indicates also invalid


/* deletePoly(poly)
 * deletes the entire polynomial of which head is head-node
 *
 * parameter:	pointer to a polynomial
 * return:		void
 */
void deletePoly(polynomial* poly){
    polyNode* next;
    if (poly != NULL) {
        // delete all nodes until poly is empty
        // start at beginning of poly
        poly->current = poly->head;
        // iterate through all nodes in poly and delete them
        while (poly->head->successor != NULL) {
            next = poly->head->successor;
            poly->head->successor = poly->head->successor->successor;
            free(next);
        }
        // while loop can be achieved in a single line - any ideas?

        // now poly is empty, only need to delete head
        // and poly itself
        free(poly->head);
        free(poly);
        printf("Polynomial Deleted!\n");
    }
    else {
        printf("You must create a polynomial first ...\n");
    }
}

/*
* insertAfter(polynomial, exponent,coefficient)
* creates a new node newnode, associates data d with
* newnode and inserts newnode in linse as successor of
* current node
*
* parameter: d - data to be associated with newnode
*            poly - polynomial into which to insert d
* return: ok - insertion successful
*         noMemory - no memory available to create newnode
*/
polyError insertAfter(polynomial* poly, int exponent, double coefficient){
    polyError returnvalue = ok;
    polyNode* newnode;
    term newdata;
    newdata.coefficient =  coefficient; 
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

/*
* gotoHead(polynomial)
* sets current node of polynomial to head
*
* parameter: polynomial - polynomial to be reset
* return: void
*/
void gotoHead(polynomial* poly){
    poly->current = poly->head;
}

/*
* gotoNextNode(polynomial)
* sets current node of polynomial to its successor
*
* parameter: polynomial - polynomial to be traversed
* return: ok - current has been set to successor
*         illegalNode - successor of current it tail
*/
polyError gotoNextNode(polynomial* poly){
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

/*
* accessData
* returns data of current node
*
* parameter: polynomial - polynomial to be accessed
* return: if current is head or tail: NULL
*         otherwise, data of current node
*/
term* accessData(polynomial* poly){
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
*	Function that takes two polynomials, constructs and returns 
*	a new polynomial that is the result of adding polynomials p1 and p2
*
*   parameter: two polynomials - polynomials to be accessed
*   return: polynomial  -result of the addition
*/
polynomial* addPoly(polynomial* p1, polynomial* p2){
    if (p1 != NULL && p2 != NULL) {
        gotoHead(p1);
        gotoHead(p2);
        printf("Adding polynomial 1 and polynomial 2:");
        while (gotoNextNode(p1) == ok && gotoNextNode(p2) == ok) {
            term* a = accessData(p1);
            term* b = accessData(p2);
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
*	Function that takes two polynomials, constructs and returns 
*	a new polynomial that is the result of subtracting polynomial p2 from p
*
*   parameter: two polynomials -polynomials to be accessed 
*   return: polynomial -result of the subtraction
*/
polynomial* subtractPoly(polynomial* p1, polynomial* p2){
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
*	Function that takes a polynomial, constructs and returns 
*   a new polynomial that is the result of multiplying polynomial p and double value
*
*   parameter: polynomial - polynomial to be accessed
*               double - value to multiply by
*   return: polynomial -result of multiply
*/
polynomial* multiplyPoly(polynomial* p,double value){
    gotoHead(p);
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
*	Function that takes a polynomial, constructs and returns 
*	a new polynomial that is the result of dividing polynomial p and double value
*    
*   parameter: polynomial - to be accessed
*               double - to be divided 
*   return: polynomial -result of division
*/
polynomial* dividePoly(polynomial* p,double value){
    gotoHead(p);
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
*	Function that normalises the polynomial adjusting the coefficients so that
*   the coefficient of the highest order is 1
*
*   parameter: polynomial - polynomial to be accessed
*   return: polynomial - result of the normalisation
*/
polynomial* normalisePoly(polynomial* p){
    gotoHead(p);
    if(p != NULL){
        if(gotoNextNode(p) == ok){
            term* polyTerm = accessData(p);
            double coeff = polyTerm->coefficient;
            dividePoly(p,coeff);
        }
    }else {
        printf("Create a polynomial");
    }
    return p;
}

/*
*	Function that displays the highest order of the polynomial
*   returning the highest power and the coefficient
*
*   parameter: polynomial - polynomial to be accessed
*   return: void
*/
void orderPoly(polynomial* p){
    if (p != NULL) {
        gotoHead(p);
        if (gotoNextNode(p) == ok) {
            term* d = accessData(p);
            printf("Order of polynomial: %d\n", d->exponent);
        }
        else {
            printf("You must create a linked polynomial first ...\n");
        }
    }
}

/*
*	Function that displays the polynomial to the standard output
*	in the traditional mathematical form
*
*   parameter: polynomial - polynomial to be accessed
*   return: void
*/
void displayPoly(polynomial* myPoly){
    if (myPoly != NULL) {
        // start at head
        gotoHead(myPoly);
        if (myPoly->head->successor == NULL) {
            printf("No polynomial found!\n");
        }
        else {
            do {
                // print current node
                if (myPoly->current == myPoly->head) {
                    printf("\nPolynomial = ");
                }
                else {
                    term* d = accessData(myPoly);
                    if(d->coefficient != 0){
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
                }
                // goto next node in polynomial
            } while (gotoNextNode(myPoly) == ok);
            printf("\n\n");
        }
    }
    else {
        printf("You must create a polynomial first ...\n");
    }
}
