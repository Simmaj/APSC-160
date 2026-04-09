#include <stdio.h>

int main()
{
    int size;
    printf("enter a number between 1 and 9");
    scanf("%d", &size);
   while(!(size>=1 && size <= 9)){
       printf("\nError! invalid number entered, enter a number between 1 and 9");
       scanf("%d", &size);
   }

    int count2 = 1;
   while(count2 <= size){
       int i = 1;
       int j = size-count2;
       while(j>0){
           printf(".");
           j--;
       }
       while(i <= count2){
           printf("%d",i);
           i++;
       }
       printf("\n");
       count2++;
   }
   

    return 0;
}