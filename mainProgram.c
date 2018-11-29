/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * mainProgram.c
 * 
 * Modular Program that uses ADT to carry out various functions on 
 * polynomial values
 * 
 * Authors: 
 *      Mike Vriesema 17212359 
 * 		Luke O'Sullivan Griffin 17184614 
 * 		Ryan O'Connor 17209382 
 * 		Conall McAteer 18173586 
 * 		Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 29.11.2018
 *///////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

/*
 * The main 
 * 
 * Runs through all methods in polynomial.c as a driver main with 
 * preset hardcoded values for the polynomials
 * 
 * Parameters - void
 * Returns - exit success if program completes
*/
int main(){
    polynomial* poly1 = NULL;
    polynomial* poly2 = NULL;

    //hard coded order/exponent value for createPoly
    int value = 5;

    // Provide tests for all operations
    printf("\nCreate new 1st polynomial:");
    poly1 = createPoly(value);
    displayPoly(poly1);
    printf("\nCreate new 2nd polynomial:");
    poly2 = createPoly(value);
    displayPoly(poly2);
    printf("\nAdd polynomial:\n");
    addPoly(poly2, poly1);
    printf("\nSubtract polynomial:\n");
    subtractPoly(poly1, poly2);
    printf("\nMultiply polynomial:\n");
    multiplyPoly(poly1,4);
    printf("\nDivide polynomial:\n");
    dividePoly(poly2,2);
    printf("\nNormalise polynomial:\n");
    normalisePoly(poly1);
    printf("\nReturn order of polynomial:\n");
    orderPoly(poly1);
    printf("\nDelete polynomial:\n");
    deletePoly(poly1);
    printf("\nExit Program\n");

    return EXIT_SUCCESS;
}


