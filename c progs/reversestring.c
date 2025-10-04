#include <stdio.h>
#include <string.h>

void reverseStr(char* str, int n){
    int size = strlen(str);
    if (n == size/2) return;
    char temp = str[size - 1 - n];
    str[size - 1 - n] = str[n];
    str[n] = temp;
    reverseStr(str, n + 1);
}

void reverse(char* str){
    reverseStr(str, 0);
}


int main(){
    char str[] = "Shyam";
    reverse(str);
    printf("%s", str);
    return 0;
}