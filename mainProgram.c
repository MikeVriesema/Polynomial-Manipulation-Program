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
int readOrder();
double readCoeff();

/*
 * The main 
*/
int main(){







	
}

/*
 * readOrder
 * Reads user input expecting an int
 * Used for taking in the order of the polynomials
 * Return: int - value(user inputted value)
 * Parameter: void
*/
int readOrder(){
   int value;
   scanf("%d",&value);
   return value;
}

/*
 * readCoeff
 * Reads user input expecting an double
 * Used for coeeficients in polynomials
 * Return: double - value(user inputted value)
 * Parameter: void
*/
double readCoeff(){
   double value;
   scanf("%lf",&value);
   return value;
}
