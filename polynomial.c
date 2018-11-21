/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * polynomial.c
 * 
 * C file for polynomial data type and the functions
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
#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"



/*
	Function that obtains required data for a polynomial from
	the user, constructs a polynomial (linked list of terms)
	and returns a pointer to the first (head) term.
*/
poly create(){
/*
	unsigned int size;
	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%u",&size);
	poly p;
	for(int i=0;i<size;i++)
	{
		printf("Enter the Coefficient(%lf):");
		scanf("%lf",p.coeff);
		printf("Enter the exponent(%lf):");
		scanf("%lf",p.exp);        
	}*/
}

/*
	Function that takes in a polynomial and deletes it
*/
void deletePoly(poly p){}

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of adding polynomials p1 and p2
*/
poly addPoly(poly p1, poly p2){

}

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of subtracting polynomial p2 from p
*/
poly subtractPoly(poly p1, poly p2){

}

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of multiplying polynomial p and double value
*/
poly multiplyPoly(poly p, double value){

}

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of dividing polynomial p and double value
*/
poly dividePoly(poly p, double value){

}

/*
	Function that normalises the polynomial adjusting the coefficients so that
    the coefficient of the highest order is 1
*/
poly normalisePoly(poly p){

}

/*
	Function that displays the highest order of the polynomial
    returning the highest power and the coefficient
*/
poly orderPoly(poly p){

}

/*
	Function that displays the polynomial to the standard output
	in the traditional mathematical form
*/
void display(poly p){

}
