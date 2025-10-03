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

int** matrix_transpose(int** arr, int rows, int cols){
    int** transpose = malloc(rows * sizeof(int*));
    if (transpose == NULL) return NULL;

    for (int i = 0; i < rows; i++){
        transpose[i] = malloc(cols * sizeof(int));
        if (transpose[i] == NULL) return NULL;
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            transpose[j][i] = arr[i][j];
        }
    }

    return transpose;
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

    int** transpose = matrix_transpose(arr, rows, cols);

    printf("transpose matrix:\n");
    printmatrix(transpose, rows, cols);

    
    //freeing arr memory
    for (int i = 0; i < rows; i++){
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr);
    arr = NULL;

    //freeing transpose memory
    for (int i = 0; i < rows; i++){
        free(transpose[i]);
        transpose[i] = NULL;
    }

    free(transpose);
    transpose = NULL;

}