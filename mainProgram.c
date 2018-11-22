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
 *///////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"
#include "linkedlist.h"

//FUNCTION DECLARATIONS:
double inputTerm();

/*
 * The main 
*/
int main() 
{
  llist *mylist=NULL;
  poly newdata;
  int choice=-1;
  
  while (choice != 0) {
    // provide menu for different operations:
    printf("\t(0) Exit Program\n");
    printf("\t(1) Create new linked list of polynomials\n");
    printf("\t(2) Insert new data\n");
    printf("\t(3) Delete node\n");
    printf("\t(4) Goto next node\n");
    printf("\t(5) Goto Head\n");
    printf("\t(6) Print current node\n");
    printf("\t(7) Print entire list\n");
    printf("\t(8) Delete entire list\n");
    printf("\nPlease select 0-7:");
    scanf("%d",&choice);
    
    switch (choice) {
      
    case 0: // Exit Program
      break;
      
    case 1: //Create new linked list
      // check if list already exist
      if (mylist != NULL)
	printf("list already in use, cannot "
	       "create new list ...\n");
      else {
	// create list
	mylist = listCreate();
      }
      break;
      
    case 2: // Insert new data
      if (mylist != NULL) {
	// fill newdata with user input
	printf("\nplease enter name: ");
	scanf("%lf",&newdata.coefficient);
	printf("\nplease enter description: ");
	scanf("%lf",&newdata.exponent);
	// call insertAfter
	if (insertAfter(&newdata, mylist) == ok)
	  printf("\nInserted data successfully\n");
	else 
	  printf("\nInsuffient ressources, operation cancelled\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 3: // delete node
      if (mylist != NULL) {
	// attemtp to delete node and report result
	if (deleteNext(mylist) == ok) 
	  printf("Node deleted ...\n");
	else 
	  printf("Invalid successor of current, operation cancelled\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 4: // goto next node
      if (mylist != NULL) {
	// attempt to goto next node and report result
	if (gotoNextNode(mylist) == ok) 
	  printf("Moved to next node ...\n");
	else 
	  printf("Invalid successor of current, operation cancelled\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 5: // goto head
      if (mylist != NULL) {
	gotoHead(mylist);
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 6: // print current node
      if (mylist != NULL) {
	// print "Head" if current is head
	if (mylist->current == mylist->head) {
	  printf("Head\n");
	} else {
	  // otherwise print all data elements
	  poly *d = accessData(mylist);
	  printf("%lf x^ %lf", 
		 d->coefficient, d->exponent);
	}
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 7: // print entire list
      if (mylist != NULL) {
	int counter = 0;
	// start at head
	gotoHead(mylist);
	do {
	  // print current node
	  if (mylist->current == mylist->head) {
	    printf("\nHead\n");
	  } else {
	    printf("Node #%d\n", ++counter);
	    poly *d = accessData(mylist);
	    printf("\t%lf x^ %lf", 
		   d->coefficient, d->exponent);
	  }
	  // goto next node in list
	} while( gotoNextNode(mylist) == ok);
	printf("\n\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;

    case 8: // delete entire list
      if (mylist != NULL) {
	listDelete(mylist);
	mylist = NULL;
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    default:
      printf("Invalid choice, please select again\n");
    }
    
  }
  return EXIT_SUCCESS;
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
