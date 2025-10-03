#include <stdio.h>
#include <stdlib.h>

int zerosubarray(int* arr, int size){
    int count = 0;
    int* prefix_sum = malloc(size * sizeof(int));
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
        if (sum == 0) count++;
        for (int j = 0; j < i; j++){
            if (prefix_sum[j] == sum) count++;
        }
        prefix_sum[i] = sum;
    }

    free(prefix_sum);
    prefix_sum = NULL;

    return count; // empty subarray
}

int main(){

    int arr[] = {1, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("no. of subarrays with sum 0 is %d", zerosubarray(arr,size));
    return 0;
}