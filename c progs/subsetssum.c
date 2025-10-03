#include <stdio.h>
#include <math.h>

void print(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int* subsetsum(int* arr, int size){
    int subset_size = 1 << size;
    int* subset_sum = malloc(subset_size * sizeof(int));
    if (subset_sum == NULL) return NULL;

    for (int i = 0; i < subset_size; i++){
        int sum = 0;
        for (int j = 0; j < size; j++){
            if ( i & (1 << j)) sum += arr[j];
        }
        subset_sum[i] = sum;
    }
    return subset_sum;
}

int main(){
    int arr[] = {2, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int* arr_sum = subsetsum(arr, size);

    print(arr_sum, pow(2, size));
    return 0;
}