/*
 * Author: Simranjeet Kaur
 * Student Number: 91551317
 * Lab Section: L2P
 * Date: January 22, 2026
 * Purpose: prompts the user for the length (in metres) of each of: the first segment (AB) and the second segment (BC) of the robot arm;
            prompts the user for the angle that the first segment of the robot arm makes with the positive x-axis, measured counterclockwise in radians from the positive x-axis (see  on the diagram above);
            prompts the user for the angle that the second segment of the robot arm makes with the positive x-axis, measured counterclockwise in radians from the positive x-axis (see  on the diagram above);
            computes the coordinates of point C;
            prints the coordinates of point C on the screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( void ){
    double length_ab;
    double length_bc;
    double theta1;
    double theta2;
    double c_x;
    double c_y;
    

    printf("Please enter the length (in metres) of the first segment (AB): \n");
    scanf("%lf", &length_ab);
    
    printf("Please enter the length (in metres) of the first segment (BC): \n");
    scanf("%lf", &length_bc);
    
    printf("Please enter the angle that the first segment of the robot arm makes with the positive x-axis (in radians): \n");
    scanf("%lf", &theta1);
    
    printf("Please enter the angle that the second segment of the robot arm makes with the positive x-axis (in radians): \n");
    scanf("%lf", &theta2);

    c_x = length_ab*cos(theta1) + length_bc*cos(theta2);
    c_y = length_ab*sin(theta1) + length_bc*sin(theta2);

    printf("The coordinates for C are: (%f, %f )\n" , c_x , c_y);

    system( "PAUSE" );
    return 0;

}