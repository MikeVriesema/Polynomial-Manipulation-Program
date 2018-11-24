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
  
  printf("\tCreate new polynomials\n");     //FUNCTIONAL
  poly1 = createPoly();
  poly2 = createPoly();
  printf("\tAdd polynomial\n");
  //addPoly(poly1,poly2);
  printf("\tSubtract polynomial\n");
  //subtractPoly(poly1,poly2);
  printf("\tMultiply polynomial\n");
  //multiplyPoly(poly1);           //READ DOUBLE IN METHOD//HAVE REMOVED IT AS PASSED IN PARAMTER
  printf("\tDivide polynomial\n");
  //dividePoly(poly1,double);       //READ DOUBLE IN METHOD//HAVE REMOVED IT AS PASSED IN PARAMTER
  printf("\tNormalise polynomial\n");
  //normalisePoly();
  printf("\tReturn order of polynomial\n"); //FUNCTIONAL
  orderPoly(poly1);
  printf("\tDelete polynomial\n");          //FUNCTIONAL
  deletePoly(poly1);
  printf("\tDisplay polynomial\n");         //FUNCTIONAL
  displayPoly(poly1);
  printf("\tExit Program\n");               //FUNCTIONAL

  return EXIT_SUCCESS;
}
