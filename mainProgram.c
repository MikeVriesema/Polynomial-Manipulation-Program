/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * mainProgram.c
 * 
 * Modular Program that uses ADT to carry out various functions on 
 * polynomial values
 * 
 * Authors: Mike Vriesema 17212359 
 * 			Luke O'Sullivan Griffin 17184614 
 * 			Ryan O'Connor 17209382 
 * 			Conall McAteer 18173586 
 * 			Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 20.11.2018
 *///////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

//FUNCTION DECLARATIONS:
double inputTerm();

/*
 * The main 
*/
int main(){
	unsigned int size;
	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%u",&size);
	poly polynomialList[size];
	poly *p;
	p=polynomialList;
	createPoly(size,*p);
}


/*
 * inputTerm
 * Reads user input expecting an double
 * Used for coefficients/exponents in polynomials
 * Return: double - value(user inputted value)
 * Parameter: void
*/
double inputTerm(){
   double value;
   scanf("%lf",&value);
   return value;
}
