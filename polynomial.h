#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/* declare structure for polynomial */
struct polynomial
{
    double coefficient;
    double exponent;
};
typedef struct polynomial poly;

/* function prototypes */
int readPoly(struct polynomial[]);
int addPoly(struct polynomial p1[10],struct polynomial p2[10],int t1,int t2,struct polynomial p3[10]);
void displayPoly(struct polynomial[], int terms);

#endif