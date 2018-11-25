/*///////////////////////////////////////////////////////////////////////
 * Assignment 3 CE4703
 * mainProgram.c
 * 
 * Modular Program that uses ADT to carry out various functions on 
 * polynomial values
 * 
 * Authors: 
 *      Mike Vriesema 17212359 
 * 			Luke O'Sullivan Griffin 17184614 
 * 			Ryan O'Connor 17209382 
 * 			Conall McAteer 18173586 
 * 			Gearoid Kirwan 17213266
 * 
 * Date Last Modified: 22.11.2018
 *///////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

//FUNCTION DECLARATIONS:

/*
 * The main 
*/
int main()
{
  polynomial *poly1 = NULL;
  polynomial *poly2 = NULL;

  // Provide tests for all operations
  
  printf("\nCreate new polynomials:\nInput values for 1st Polynomial:");     
  poly1 = createPoly();
  printf("\nInput values for 2nd Polynomial:");
  poly2 = createPoly();
  printf("\nAdd polynomial:\n");
  addPoly(poly1,poly2);
  printf("\nSubtract polynomial:\n");
  subtractPoly(poly1,poly2);
  printf("\nMultiply polynomial:\n");
  multiplyPoly(poly1);       
  printf("\nDivide polynomial:\n");
  dividePoly(poly1);      
  printf("\nNormalise polynomial:\n");
  //normalisePoly();
  printf("\nReturn order of polynomial:\n"); 
  orderPoly(poly1);
  printf("\nDelete polynomial:\n");         
  deletePoly(poly1);
  printf("\nDisplay polynomial:\n");       
  displayPoly(poly1);
  printf("\nExit Program\n");               

  return EXIT_SUCCESS;
}
