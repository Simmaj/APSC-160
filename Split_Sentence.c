//Prompts the user to type a sentence at the keyboard
//Reads the full line of input (including spaces) into a char array
//Scans through the sentence character by character to extract each word
//Counts how many times each unique word appears
//Prints a frequency table when done

#include <stdio.h>
#include <string.h>

int checkifrepeated(char words[][50],int n, char word[]){
    int alreadyseen = 0;
    for(int i = 0; i < n;i++){
        if(strcmp(words[i],word)==0){
            alreadyseen = 1;
        }
    }
    return alreadyseen;
}


int main(){
    
    char sentence[5000];
    char words[100][50];
    int count[100];
    int index = 0;
    int totalwords = 0;
    
    printf("enter the sentence\n");
    fgets(sentence, 5000, stdin);
    
    int len= strlen(sentence);
    
    int j = 0;
    for(int i = 0; i< len; i++){
        char word[50];
        if(sentence[i]==' '||sentence[i] == '\n'){
           strcpy(words[index],word);
           index++;
           j = 0;
           if(sentence[i] == '\n'){
               totalwords = index;
           }
        }
        else{
            word[j] = sentence[i];
            j++;
        }
    }
    
    for(int i = 0; i < totalwords; i++){
        int num = 0;
        int alreadyseen = checkifrepeated(words,i,words[i]);
        for(int j = i; j < totalwords; j++){
            if((strcmp(words[i],words[j]))==0){
                if(alreadyseen==0){
                num++;
                }
            }
        }
        count[i] = num;
    }
    
    for(int i = 0; i < totalwords; i++){
        if(count[i]>0){
            printf("%s -> %d\n", words[i], count[i]);
        }
    }
    
    
}
