#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* upper(char* arr){
    int size= strlen(arr);
    for (int i = 0; i < size; i++){
        if (isalpha(arr[i])){
            if (arr[i] >= 'A' && arr[i] <= 'Z') continue;
            arr[i] = 'A' + arr[i] - 'a';
        }
    }
    return arr;
}

char* lower(char* arr){
    int size = strlen(arr);
    for (int i = 0; i < size; i++){
        if (isalpha(arr[i])){
            if (arr[i] >= 'a' && arr[i] <= 'z') continue;
            arr[i] = 'a' + arr[i] - 'A';
        }
    }
    return arr;
}


int main(){

    char dest[100] = "Dog123";
    char src[] = "HelloIM HAPPPY";

    printf("%s\n", upper(dest));
    printf("%s\n", lower(src));
    return 0;
}