#include <stdio.h>
#include <stdlib.h>

void printmatrix(int** arr, int rows, int cols){
    for (int i = 0; i < rows;i++){
        for (int j = 0; j < cols; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void printarr(int* arr, int size){
    for (int i = 0; i < size;i++){
        printf("%d\t", arr[i]);
    }
}

int* spiral(int** arr, int matrixSize, int matrixColSize){
    int returnSize = matrixSize * matrixColSize;
    int* traversal = malloc((returnSize) * sizeof(int));

    int left = 0, right = matrixColSize - 1;
    int top = 0, bottom = matrixSize - 1;
    int tr = 0;

    while (top <= bottom && left <= right){
        for (int i = left; i <= right; i++){
            traversal[tr++] = arr[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++){
            traversal[tr++] = arr[i][right];
        }
        right--;

        if (top <= bottom){
            for (int i = right; i >= left; i--){
                traversal[tr++] = arr[bottom][i];
            }
            bottom--;
        }

        if (left <= right){
            for (int i = bottom; i >= top; i--){
                traversal[tr++] = arr[i][left];
            }
            left++;
        }

    }

    return traversal;
}

int main(){
    int rows, cols;
    printf("enter no. of rows\n");
    scanf("%d", &rows);

    printf("enter no. of cols\n");
    scanf("%d", &cols);

    int** arr = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++){
        arr[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++){
            printf("enter row - %d, col - %d element:\n", i, j);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    printf("original array:\n");
    printmatrix(arr, rows, cols);
    printf("\n\n");


    printf("spiral traversal\n");
    int* traversal = spiral(arr, rows, cols);
    printarr(traversal, rows*cols);

    //freeing arr memory
    for (int i = 0; i < rows; i++){
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr);
    arr = NULL;

    //freeing traversal memory

    free(traversal);
    traversal = NULL;

}