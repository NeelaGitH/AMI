#include <stdio.h>

void print(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int findpartition(int* arr, int low, int high){
    int pivot = arr[low];

    int i = low, j = high;

    while (i < j){
        while (arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while (arr[j] > pivot && j >= low - 1){
            j--;
        }

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
    
};

void quicksort(int* arr, int low, int high){
    if (low >= high) return;

    int partition = findpartition(arr,low,high);
    quicksort(arr, low, partition - 1);
    quicksort(arr, partition + 1, high);
}


int main(){
    int arr[] = {4, 5, 2, 1, 2, 5,4, 7, 8, 1, 3, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("original array - ");
    print(arr, size);


    quicksort(arr, 0, size - 1);
    printf("sorted array - ");
    print(arr, size);

    return 0;
}