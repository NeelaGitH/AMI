#include <stdio.h>

int main(){

    FILE* fptr = fopen("io.txt", "w");
    fputs("Hello how are you doing?\n", fptr);
    fclose(fptr);

    char buffer[256];

    fptr = fopen("io.txt", "r");
    fgets(buffer, 256, fptr);

    printf("%s\n", buffer);

    return 0;
}