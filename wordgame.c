
// Print at the terminal a random word in the list;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void scramble(char s[]);

int main(void) {
    srand(time(NULL));
    char words [][13]={"intelligence", "clouds", "navigate", "random", "seed"};
    char randomword[50];
    int count = 1;
    bool success = false;
    char guess[50];
    int correct = 0;
    
    int random = 0+rand()%(4+1);
    strcpy(randomword,words[random]);
    
    scramble(randomword);
    printf("this is the scrambled word %s \nplease enter the original word\n",randomword);
    
    while(count<=5 && !success){
        
       printf("Attempt %d\n", count);
       scanf("%s", guess);
       correct = strcmp(guess, words[random]);
       
       if(correct == 0){
           success = true;
       }
       if(count != 5){
          printf("please try agian\n", count);  
       }
       count++;
       
    }
    
    if(success){
        printf("you guessed in %d tries\n", count-1);
    }
    else{
        printf("ops you used all youe tries!");
    }

return 0;
}

void scramble(char s[]){
    int len = strlen(s);
    
    for(int i =0; i<len;i++){
        int randomindex = rand()%(len);
        char temp = s[i];
        s[i] = s[randomindex];
        s[randomindex] = temp;
    }
}
