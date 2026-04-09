int factorial (int n);
int choose(int n , int r);
#include <stdio.h>

int main()
{
    int n, r, comb;
    
    printf("enter the n:" );
    scanf("%d", &n);
    
    printf("\nenter the r:" );
    scanf("%d", &r);
    
    comb = choose (n, r);
    printf("the comb is : %d", comb);

    return 0;
}


int choose(int n , int r){
    
    int comb = (factorial(n))/(factorial(r)*factorial(n-r));
    return comb;
    
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