#include <stdio.h>

int binarySearch(int* arr, int size, int val){
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;

    while (start <= end){
        if (val == arr[mid]) return mid;
        else if (val > arr[mid]){
            start = mid + 1;
        }
        else end = mid - 1;

        mid = start + (end - start)/2;
    }

    return -1;
}

int main(){
    int arr[] = {5, 7, 8, 34, 56, 77};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ele = binarySearch(arr, size, 77);
    if (ele == -1) printf("element not found\n");
    else printf("element found at loc - %d", ele);
}