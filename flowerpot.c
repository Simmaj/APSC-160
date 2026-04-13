#include <stdio.h>
#include <stdbool.h>

int checkflower(int data[][3], int row, int col, int maxrows, int maxcols);

int main(){
    //hardcoded for testing
    int data[][3]={{0,0,0},{1,0,0},{0,0,0}};
    int rows=3;
    int cols = 3;
    int count = 0;
    
    for(int i = 0 ; i<rows;i++){
        for(int j=0; j<cols; j++){
            int result = 0;
            if(data[i][j]==1){
                count++;
            }
            else{
            result = checkflower(data,i,j, rows, cols);
            }
            if(result == 1){
                count++;
            }
        }
    }
    
    printf("the maximum number of flowers that can planted are:  %d ",count);
    
}

int checkflower(int data[][3], int row, int col, int maxrows, int maxcols)
{
    int result;
    bool adjacentflower = false;
    
    if(row-1>=0){
        if(data[row-1][col]==1){
            adjacentflower = true;
        }
    }
    
    if(col+1<maxcols){
        if(data[row][col+1]==1){
            adjacentflower = true;
        }
    }
    
    if(row+1<maxrows){
        if(data[row+1][col]==1){
            adjacentflower = true;
        }
    }
    
    if(col-1>=0){
        if(data[row][col-1]==1){
            adjacentflower = true;
        }
    }
    
    if(adjacentflower==true){
        result = 0;
    }
    else{
        data[row][col]=1;
        result = 1;
    }
    
    return result;
}
