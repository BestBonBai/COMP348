/******************************************************************************
COMP 348  Assignment 3
@author: Hualin Bai
@ID: 40053833
@Date: 2020/04/02
*******************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int row, col; //for row and colum of 2D array 

/* the method is to transpose the elements of 2D array*/
void matrixTranspose( int **array){
   int **transarr;//pointer to pointer to the transarr[col][row]
   
   printf("...doing matrixTranspose...\n");
   //handle memory allocation for 2D array
    transarr = (int**) malloc(col * sizeof(int*));
    for(int r=0; r<col; r++){
        transarr[r] = (int*) malloc(row * sizeof(int));
    }
    
    //judgement whether memory is allocated
    if(transarr == NULL){
        printf("Error: out of memory.\n");
        return;
    }
    
    //transpose
    for(int r=0; r<col; r++){
        for(int c=0; c<row; c++){
            transarr[r][c] = array[c][r];
        }
    }
    
    //show the transposed 2D array
    printf("show the transposed 2D array\n");
    for(int r=0; r < col; r++){
        for(int c=0; c < row; c++){
            printf("%d\t", transarr[r][c] );
        }
        printf("\b \n");
    }
    
    //release transarr memory
    for(int r=0; r<col; r++){
        free(transarr[r]);
    }
    free(transarr);
}

int main()
{
    int **array; //pointer to pointer to the array
   
    //set values of row and colum of 2D array
    printf("Enter values of row and colum of 2D array.\n");
    scanf("%d %d", &row, &col);
    if(row <=0 || col <=0){
        printf("row and col should be a positive integer!");
        return -1;
    }
    
    //handle memory allocation for 2D array
    array = (int**) malloc(row * sizeof(int*));
    for(int r=0; r<row; r++){
        array[r] = (int*) malloc(col * sizeof(int));
    }
    //judgement whether memory is allocated
    if(array == NULL){
        printf("Error: out of memory.\n");
        return 1;
    }
    
    //Enter value of each element of 2D array
    printf("Enter value of each element of 2D array\n");
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            printf("set array[%d][%d]\n", r, c);
            scanf("%d", &array[r][c]);
        }
    }
    
    //show the 2D array
    printf("show the 2D array\n");
    for(int r=0; r < row; r++){
        for(int c=0; c < col; c++){
            printf("%d\t", array[r][c] );
        }
        printf("\b \n");
    }
    
    //recall matrixTranspose
    matrixTranspose(array);
    
    //release array memory
    for(int r=0; r<row; r++){
        free(array[r]);
    }
    free(array);
    
    return 0;
}
