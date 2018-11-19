/*///////////////////////////////////////////////////////////////////////
 * Assignment 2 CE4703
 * 
 * Modular Program that runs shape related size calculations for
 * 3D and 2D shapes with a menu loop in the main allowing for user input.
 * 
 * Author: Mike Vriesema 17212359
 * Date Last Modified: 19.11.2018
 *///////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

//FUNCTION DECLARATIONS:
int readChoice();
double readInput();

/*
 * The main 
*/
int main()
 {
	int t1,t2,t3;
	struct poly p1[10],p2[10],p3[10];
	/* read and display first polynomial */
	t1=readPoly(p1);
	printf(" \n First polynomial : ");
	displayPoly(p1,t1);
	/* read and display second polynomial */
	t2=readPoly(p2);
	printf(" \n Second polynomial : ");
	displayPoly(p2,t2);

	/* add two polynomials and display resultant polynomial */
	t3=addPoly(p1,p2,t1,t2,p3);
	printf(" \n\n Resultant polynomial after addition : ");
	displayPoly(p3,t3);
	printf("\n");

	return 0;
 }

/*
 * readChoice
 * Reads user input expecting an int
 * Used for making menu choices
 * Return: int - value(user inputted value)
 * Parameter: void
*/
int readChoice()
{
   int value;
   scanf("%d",&value);
   return value;
}

/*
 * readInput
 * Reads user input expecting an double
 * Used for inputting shape dimensions in sub menus
 * Return: double - value(user inputted value)
 * Parameter: void
*/
double readInput()
{
   double value;
   scanf("%lf",&value);
   return value;
}
