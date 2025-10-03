#include <stdio.h>
#include <limits.h>

void print(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void rotate(int* arr, int k, int size){
    k = k % size;
    if (size == 0) return;
    while (k){
        int temp = arr[0];
        for (int i = 1; i < size; i++){
            arr[i - 1] = arr[i];
        }
        arr[size - 1] = temp;
        k--;
    }
}

int main(){
    int arr[] = {45, 56, 99, 22, 34, 89, 12};
    int size = sizeof(arr)/ sizeof(arr[0]);
    rotate(arr, 8, size);

    print(arr, size);

    return 0;
}