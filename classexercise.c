#include <stdio.h>

#define NUM_ROWS = 1
#define NUM_COLS = 1

int search(int, int[][]);
int main()
{
    int value;

    int array= {{0,1},{2,3}};
    printf("enter the value");
    scanf("%d", &value);



    return 0;
}
//(a) Using break statements
int search(int value, int array[NUM_ROWS][NUM_COLS]) {
int found = FALSE;
for (int row = 0; row < NUM_ROWS; ++row) {
    for(int col = 0; col < NUM_COLS; ++col){
         if(array[row][col]==value){
             found = TRUE;
             break;
         }
    }
}
return found;
}

//(b) Using return for early exit
int search(int value, int array[NUM_ROWS][NUM_COLS]) {
    for (int row = 0; row < NUM_ROWS; ++row) {
        for(int col = 0; col < NUM_COLS; ++col){
                 if(array[row][col]==value){
                     return TRUE;
                 }
            }
    }
return FALSE;
}

//(c) Without break or return
int search(int value, int array[NUM_ROWS][NUM_COLS]) {
int found = FALSE;
    for (int row = 0; row < NUM_ROWS && !found; ++row) {
        for(int col = 0; col < NUM_COLS; ++col){
                     if(array[row][col]==value){
                         found = TRUE;
                     }
                }
    }
return found;
}