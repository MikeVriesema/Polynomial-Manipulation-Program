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
 * Date Last Modified: 22.11.2018
 */
//////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

//FUNCTION DECLARATIONS:

/*
 * The main 
*/
int main()
{
  polynomial *mylist = NULL;
  int choice = -1;

  while (choice != 0)
  {
    // provide menu for different operations:
    printf("\t(0) Exit Program\n");          //FUNCTIONAL
    printf("\t(1) Create new polynomial\n"); //FUNCTIONAL
    printf("\t(2) Delete polynomial\n");     //FUNCTIONAL
    printf("\t(3) Add polynomial\n");
    printf("\t(4) Subtract polynomial\n");
    printf("\t(5) Multiply polynomial\n");
    printf("\t(6) Divide polynomial\n");
    printf("\t(7) Normalise polynomial\n");
    printf("\t(8) Return order of polynomial\n"); //FUNCTIONAL (NEEDS REVERSE THO)
    printf("\t(9) Display polynomial\n"); //FUNCTIONAL
    printf("\nPlease select 0-9:");
    scanf("%d", &choice);
    //MUST RUN ALL AS DRIVER NOT AS MENU

    switch (choice)
    {
    case 0: // Exit Program
      break;

    case 1: //CREATE POLYNOMIAL
      if (mylist != NULL){ //CURRENTLY LOCKS POLY CREATION TO 1
        printf("Polynomial already in use,cannot create a new polynomial ...\n");
      }else{
        mylist = createPoly();
      }
      break;

    case 2: //DELETE POLYNOMIAL
      if (mylist != NULL){
        deletePoly(mylist);
        mylist = NULL;
      }else{
        printf("You must create a linked list first ...\n");
      }
      break;

    case 3: //ADD POLYNOMIALS
      if (mylist != NULL){
        //addPoly(mylist,poly2);
      }else{
        printf("You must create a linked list first ...\n");
      }
      break;

    case 4: //SUBTRACT POLYNOMIALS
      if (mylist != NULL){
        //subtractPoly();
      }else{
        printf("You must create a linked list first ...\n");
      }
      break;

    case 5: //MULTIPLY POLYNOMIALS
      if (mylist != NULL){
        //multiplyPoly();
      }else{
        printf("You must create a linked list first ...\n");
      }
      break;

    case 6: //DIVIDE POLYNOMIALS
      if (mylist != NULL){
        //dividePoly();
      }else{
        printf("You must create a linked list first ...\n");
      }
      break;

    case 7: //NORMALISE POLYNOMIAL
      if (mylist != NULL){
        //normalisePoly();
      }else{
        printf("You must create a linked list first ...\n");
      }
      break;

    case 8: //RETURN ORDER OF POLYNOMIAL
        orderPoly(mylist);
      break;

    case 9: // DISPLAY POLYNOMIAL
        displayPoly(mylist);
      break;

    default:
      printf("Invalid choice, please select again\n");
    }
  }
  return EXIT_SUCCESS;
}
