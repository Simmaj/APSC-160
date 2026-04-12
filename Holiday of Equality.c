// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int citizensSize;
    //hardcoded for testing
    int citizen[]={1,1,0,1,1};
    int totalBurls = 0;
    int max;
    
    //prompting the user to enter the number of citizens
    printf("enter the number of citizens");
    scanf("%d", &citizensSize);
    
    //this is for user input
    // for(int i = 0; i<citizensSize; i++ ){
    //   printf("the number of burl citizen %d has", i);
    //   scanf("%d", &citizen[i]);
    // }
    
    //finiding maximum amoutn of burls a citizen has 
    max = citizen[0];
    for(int i = 0 ; i < citizensSize ; i++){
        if(citizen[i]>max){
            max = citizen[i];
        }
    }
    
    //calculating the total number of burls needed
    for(int i = 0 ; i<citizensSize; i++){
        totalBurls = totalBurls + (max-citizen[i]);
    }
    
    //printing the total number of burls
    printf("the total number of burls is %d", totalBurls);

    return 0;
}
