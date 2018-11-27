/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * polynomial.h
 * 
 * Header file for polynomial data type and the function declarations
 * to manipulate the polynomials and to create structure for polynomial ADT
 * 
 * Authors: 
 *          Mike Vriesema 17212359 
 * 			    Luke O'Sullivan Griffin 17184614 
 * 			    Ryan O'Connor 17209382 
 * 			    Conall McAteer 18173586 
 * 			    Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 24.11.2018
 *///////////////////////////////////////////////////////////////////////
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

// DEFINE ERROR CODES FOR LINKED LIST
typedef enum {
    ok,
    illegalNode,
    noMemory
} polyError;


// DEFINE STRUCTURE FOR TERM (ELEMENT OF POLYNOMIAL)
typedef struct
    {
    double coefficient;
    int exponent;
} term;

// DEFINE STRUCTURE FOR A NODE OF POLYNOMIAL
typedef struct n {
    term d; // STORE A TERM IN THE NODE
    struct n* successor;
} polyNode;

// DEFINE TYPE FOR LINKED LIST
typedef struct
    {
    polyNode* head;
    polyNode* current;
} polynomial;

/**
 * FUNCTION DECLARATIONS:(IN DEPTH COMMENTS IN polynomial.c FILE)
 * createPoly 
 * deletePoly
 * accessData
 * insertAfter
 * gotoHead
 * gotoNextNode
 * 
 * addPoly
 * subtractPoly
 * multiplyPoly
 * dividePoly
 * normalisePoly
 * orderPoly
 * displayPoly
 * 
 */
polynomial* createPoly();
void deletePoly(polynomial* poly);

polynomial* addPoly(polynomial* p1, polynomial* p2);
polynomial* subtractPoly(polynomial* p1, polynomial* p2);
polynomial* multiplyPoly(polynomial* p,double value);
polynomial* dividePoly(polynomial* p,double value);
polynomial* normalisePoly(polynomial* p);
void orderPoly(polynomial* p);
void displayPoly(polynomial* mylist);

term* accessData(polynomial* poly);
polyError insertAfter(polynomial* poly, int exponent);
void gotoHead(polynomial* poly);
polyError gotoNextNode(polynomial* poly);

#endif
