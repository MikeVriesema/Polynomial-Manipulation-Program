#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/* Declare structure for polynomial */
struct polynomial
{
    double coefficient;
    double exponent;
};
typedef struct polynomial poly;

/* Function Declarations: */
poly create();
void delete(poly);
poly add(poly p1, poly p2);
poly subtract(poly p1, poly p2);
poly multiply(poly p, double value);
poly divide(poly p, double value);
poly normalise(poly p);
poly order(poly p);
void display(poly p);

/*
	Function that obtains required data for a polynomial from
	the user, constructs a polynomial (linked list of terms)
	and returns a pointer to the first (head) term.
*/
poly create();

/*
	Function that takes in a polynomial and deletes it
*/
void delete (poly);

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of adding polynomials p1 and p2
	
	return NULL if either p1 or p2 is NULL
*/
poly add(poly p1, poly p2);

/*
	Function that takes two polynomials, constructs and returns 
	a new polynomial that is the result of subtracting polynomial p2 from p1
	
	return NULL if either p1 or p2 is NULL
*/
poly subtract(poly p1, poly p2);

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of multiplying polynomial p and double value
*/
poly multiply(poly p, double value);

/*
	Function that takes a polynomial, constructs and returns 
	a new polynomial that is the result of dividing polynomial p and double value
*/
poly divide(poly p, double value);

/*
	Function that normalises the polynomial adjusting the coefficients so that
    the coefficient of the highest order is 1
*/
poly normalise(poly p);

/*
	Function that displays the highest order of the polynomial
    returning the highest power and the coefficient
*/
poly order(poly p);

/*
	Function that displays the polynomial to the standard output
	in the traditional mathematical form
*/
void display(poly p);

#endif
