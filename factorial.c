#include <stdio.h>
int factorial (int n);

int main() {
    int n;
    int result = 1 ;
    
    printf("Enter the number: ");
    scanf("%d", &n);
    
    result = factorial(n);
    
    printf("the factorial is: %d", result);
    
    return 0;
}

int factorial (int n){
    int result = 1;
    int i = 1;
    
   if(n == 0){
        result = 1;
    }
    else{
        while(i<=n){
            result = result * i;
            i++;
        }
    }
    
    return result;
}