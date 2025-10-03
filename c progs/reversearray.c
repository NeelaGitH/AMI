#include <stdio.h>

void selectionsort(int* arr, int size){
    for (int i = 0; i < size; i++){
        int min = arr[i];
        int minInd = i;
        for (int j = i + 1; j < size; j++){
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

void find_repeating(int* arr, int size){
    for (int i = 0; i < size; i++){
        if (i + 1 < size && arr[i] == arr[i + 1]) printf("%d\t", arr[i]);
        while (i + 1 < size && arr[i] == arr[i + 1]){
            i++;
        }
    }
}

int main(){

    int arr[] = {1, 4, 5, 2, 6, 4, 1, 9, 4, 1, 5, 5, 5};
    int size = sizeof(arr)/sizeof(int);

    selectionsort(arr, size);
    find_repeating(arr, size);

}