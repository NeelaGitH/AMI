#include <stdio.h>
#include <limits.h>

int maxsubarraysum(int* arr, int size){
    int sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < size; i++){
        sum += arr[i];
        maxsum = ((sum > maxsum) ? sum : maxsum);
        if (sum < 0) sum = 0;
    }

    return maxsum;
}

int main(){
    int arr[] = {-4,-3 , -2, -10, -3};

    int size = sizeof(arr)/sizeof(arr[0]);
    printf("max sum is %d", maxsubarraysum(arr, size));

    return 0;
}