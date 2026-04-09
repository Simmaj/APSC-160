#include <stdio.h>

int main()
{
    double temperature = 0.0;
    double increment = 0.0;
    double number = 0;
    int count = 0 ;
    double fahrenheit = 0.0;
    
    printf("Please enter starting temperature in degrees Celsius:");
    scanf("%lf", &temperature);
    
    printf("Please enter the increment:");
    scanf("%lf", &increment);
    
    printf("Please enter the number of temperatures to convert:");
    scanf("%lf", &number);
    
    while(number<0){
        printf("Error! the number of temperatures can't be negtive, please enter the number again");
        scanf("%lf", &number);
    }
    
    while(count < number){
        fahrenheit = (9.0/5.0)*temperature + 32.0;
        printf("%.2lf    %.2lf\n", temperature, fahrenheit);
        count++;
        temperature = temperature + increment; 
    }
    
    
}