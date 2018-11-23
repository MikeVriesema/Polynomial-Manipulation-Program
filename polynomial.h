/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * polynomial.h
 * 
 * Header file for polynomial data type and the function declarations
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
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

// DEFINE ERROR CODES FOR LINKED LIST
typedef enum {ok, illegalNode, noMemory} polyError;

// DEFINE STRUCTURE FOR TERM (ELEMENT OF POLYNOMIAL)
typedef struct {
  double coefficient;
  double exponent;
} term;
// DEFINE STRUCTURE FOR A NODE OF POLYNOMIAL
typedef struct n {
  term d; // STORE A TERM IN THE NODE
  struct n *successor; // store successor of node
               // as typedef is not yet completed
               // name polyNode cannot be used
} polyNode;

// DEFINE TYPE FOR LINKED LIST
typedef struct {
  polyNode *head;
  polyNode *current;
} polynomial;

/**
 * FUNCTION DECLARATIONS:(IN DEPTH COMMENTS IN polynomial.c FILE)
 * createPoly 
 * deletePoly
 * 
 * addPoly
 * subtractPoly
 * multiplyPoly
 * dividePoly
 * normalisePoly
 * orderPoly
 * displayPoly
 * 
 * accessData
 * insertAfter
 * deleteNext
 * gotoHead
 * gotoNextNode
 */


polynomial *createPoly();
void deletePoly(polynomial *poly);

poly addPoly(poly p1, poly p2);
poly subtractPoly(poly p1, poly p2);
poly multiplyPoly(poly p, double value);
poly dividePoly(poly p, double value);
poly normalisePoly(poly p);
poly orderPoly(poly p);
void display(poly p);

poly *accessData(polynomial *poly);
polyError insertAfter(poly *d, polynomial *poly);
polyError deleteNext(polynomial *poly);
void gotoHead(polynomial *poly);
polyError gotoNextNode(polynomial *poly);

#endif

