/*
  * Author: Simranjeet Kaur
 * Student Number: 91551317
 * Lab Section : L2P
 * UBC email : skaur711@student.ubc.ca
 * Date:  22 January, 2026  
 * Purpose: Check if the year entered by the user is leap year or not.
 */

#include <stdio.h>
#include <stdlib.h>


int main( void ) {
   int year;
   
   printf("Enter the year: ");
   scanf("%d", &year);
   
   if(year<1582){
      printf("The Gregorian Calendar had not been adopted at that time.");
   }
   else{
       if(year % 4 == 0){
          if(year % 100 == 0 && year % 400 != 0){
               printf("\n %d is not a leap year", year);
          }
          else{
               printf("\n %d is a leap year", year);
          }
       }
       else
           printf("\n %d is not a leap year", year);
   }
    
    return 0;
}