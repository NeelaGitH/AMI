#include <stdio.h>

void print(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void sortasc(int* arr, int size, int lower, int upper){
    if (upper > size || lower > size - 1 || upper <= lower) return;

    for (int i = lower; i <= upper; i++){
        int min = arr[i];
        int minInd = i;
        for (int j = i + 1; j <= upper; j++){
            if (arr[j] < min){
                min = arr[j];
                minInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }

}

void sortdes(int* arr, int size, int lower, int upper){
    if (upper > size || lower > size - 1 || upper <= lower) return;

    for (int i = lower; i < upper; i++){
        int max = arr[i];
        int maxInd = i;
        for (int j = i + 1; j < upper; j++){
            if (arr[j] > max){
                max = arr[j];
                maxInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxInd];
        arr[maxInd] = temp;
    }

}

int main(){

    int arr[] = {45, 34, 78, 32, 67, 88, 99, 45, 34};
    int size = sizeof(arr)/sizeof(arr[0]);

    sortasc(arr, size, 0, size/2);
    sortdes(arr, size, size/2 + 1, size);

    print(arr, size);

    return 0;
}