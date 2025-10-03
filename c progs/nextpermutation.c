#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* str, int start, int end){
    int len = strlen(str);
    while (start < end){
        int temp = str[end];
        str[end] = str[start];
        str[start] = temp;

        start++;
        end--;
    }

}

char* nextpermutation(char* str){
    int len = strlen(str);
    int pivot = -1;
    for (int i = len - 2; i >= 0; i--){
        if (str[i] < str[i + 1]){
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        reverse(str, 0, len - 1);
        return str;
    }

    for (int i = len - 1; i > pivot; i--){
        if (str[i] > str[pivot]){
            char temp = str[pivot];
            str[pivot] = str[i];
            str[i] = temp;
            break;
        }
    }

    reverse(str, pivot + 1, len - 1);
    return str;

}

void printpermutations(char* str){
    char* newstr = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(newstr, str);
    printf("%s\n", newstr);
    while (strcmp(nextpermutation(newstr), str)){
        printf("%s\n", newstr);
    }
    free(newstr);
    newstr = NULL;
}


int main(){
    char* str = "he1";
    printpermutations(str);

    return 0;
}