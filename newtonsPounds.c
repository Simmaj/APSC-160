/*
 * Author: Simranjeet Kaur
 * Student Number: 91551317
 * Lab Section: L2P
 * Date: January 20, 2026
 * Purpose: Prompts the user for a fore in Newtons and converts it into pounds and prints on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

/* constants */
#define CONVERSION_FACTOR 4.448

int main ( void ){
    double force;
    double force_pounds;
    

    printf("Please enter the force (in Newtons): \n");
    scanf("%lf", &force);

    force_pounds = force/CONVERSION_FACTOR;

    printf("Force in pounds %.3lf \n" , force_pounds);

    /* system( "PAUSE" ); is optional */
    return 0;

}