
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void scramble(char s[]);

int main(){
    
    srand(time(NULL));
    char s[]="hello WORld";
    scramble(s);
    printf("%s",s);
}
void scramble (char s[]){
    int len = strlen(s);
    
    for(int i =0; i < len; i++){
        int random = 0+rand() % (len-1-0+1);
        char temp = s[i];
        s[i]=s[random];
        s[random]=temp;
    }
}
