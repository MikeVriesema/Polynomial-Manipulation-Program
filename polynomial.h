/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * polynomial.h
 * 
 * Header file for polynomial data type and the function declarations
 * to manipulate the polynomials
 * 
 * Authors: Mike Vriesema 17212359 
 * 			Luke O'Sullivan Griffin 17184614 
 * 			Ryan O'Connor 17209382 
 * 			Conall McAteer 18173586 
 * 			Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 20.11.2018
 *///////////////////////////////////////////////////////////////////////
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/* Declare structure for polynomial */
struct polynomial
{
    double coefficient;
    double exponent;
};
typedef struct polynomial poly;

/**
 * FUNCTION DECLARATIONS:(IN DEPTH COMMENTS IN polynomial.c FILE)
 * createPoly 
 * deletePoly
 * addPoly
 * subtractPoly
 * multiplyPoly
 * dividePoly
 * normalisePoly
 * orderPoly
 * displayPoly
 */
poly createPoly();
void deletePoly(poly p);
poly addPoly(poly p1, poly p2);
poly subtractPoly(poly p1, poly p2);
poly multiplyPoly(poly p, double value);
poly dividePoly(poly p, double value);
poly normalisePoly(poly p);
poly orderPoly(poly p);
void display(poly p);

#endif