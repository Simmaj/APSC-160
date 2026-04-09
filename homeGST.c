/*
  * Author: Simranjeet Kaur
 * Student Number: 91551317
 * Lab Section : L2P
 * UBC email : skaur711@student.ubc.ca
 * Date:  22 January, 2026  
 * Purpose: Prompts the user to entrer the home price and than calculates the GST payable on a new home
 */

#include <stdio.h>
#include <stdlib.h>

#define TAX_RATE  0.05
#define REBATE_RATE  0.36

int main(void){

    double home_price = 0.0;
    double tax_amount;
    double rebate;
    double gst;

    //prompts the user to enter the house price
    printf("Enter the price of the house: ");
    scanf("%lf", &home_price);

    // if the price entered by the user is negative, display error message 
    if(home_price < 0)
    {
        printf("The house price cannot be negative.");
    }
    else {
        tax_amount = home_price + home_price * TAX_RATE;
        if(home_price <= 350000.00){
            rebate = tax_amount * REBATE_RATE;
        }
        else if(home_price > 350000.00 && home_price < 450000.00){
            rebate = (5000.00*(450000.00 - home_price))/100000.00;
        }
        else if(home_price >= 450000.00){
            rebate = 0;
        }
        gst = tax_amount -  rebate ;
        printf("the gst is %lf", gst);
    }

    return 0; 
}