#include <stdio.h>
    int main() {
    // Hardcoded string
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    printf("Case-converted string:\n");
    // Loop through the string and manually convert the case
    for (int i = 0; str[i] != '\0'; i++) {
        char convertedChar;
        // Check if character is lowercase (ASCII range: 97-122)
        if (97<=str[i] && str[i]<=122) {
            convertedChar = str[i]-32; 
            //Convert to uppercase
        }
        // Non-alphabetic characters remain unchanged
        else {
            convertedChar = str[i];
        }
        printf("%c", convertedChar);
    }
    printf("\n");
    return 0;
}



#include <stdio.h>
int main(){
    char source[] = "Hello World";
    char destination[50];
    int i =0;
    while(source[i]!='\0'){
        destination[i] = source[i];
        i++;
    }
    //add the null terminator at the end of the str
    destination[i] = '\0';
    printf("source string: %s\n", source);
    printf("copied string: %s\n", destination);
    
    return 0;
    
}