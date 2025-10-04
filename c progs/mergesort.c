#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int low, int high){
    int* temp = malloc((high - low + 1) * sizeof(int));
    int mid = low + (high - low)/ 2;
    int left = low;
    int right  = mid + 1;
    int t = 0;

    while (left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp[t] = arr[left];
            left++;
            t++;
        }
        else {
            temp[t] = arr[right];
            t++;
            right++;
        }
    }

    while (left <= mid){
        temp[t] = arr[left];
        left++;
        t++;
    }

    while (right <= high){
        temp[t] = arr[right];
        right++;
        t++;
    }

    for (int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

    free(temp);
    temp = NULL;

}


void mergesort(int* arr, int low, int high){
    if (low >= high) return;
    int mid = low + (high - low)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, high);
}

int main(){
    int arr[] = {4, 5, 2, 1, 2, 5,4, 7, 8, 1, 3, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("original array - ");
    print(arr, size);


    mergesort(arr, 0, size - 1);
    printf("sorted array - ");
    print(arr, size);

    return 0;
}