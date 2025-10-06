#include <stdio.h>
#include <stdbool.h>

int main(){

    FILE *fptr = fopen("io.txt", "w");

    int ip;
    while (true){
        printf("Enter no. (-1 to quit):\n");
        scanf("%d", &ip);
        if (ip == -1)break;
        fprintf(fptr, "%d             \t\t\t\n", ip);
    }
    fclose(fptr);

    int num[100], no;
    int lines = 0;
    FILE *fread = fopen("io.txt", "r");
    while (fscanf(fread, "%d", &no) != EOF){
        num[lines++] = no;
    }

    int sum = 0;
    for (int i = 0; i < lines; i++){
        printf("line is %d - val is %d\n", i, num[i]);
        sum += num[i];
    }
    printf("avg is %d\n", sum/lines);

    return 0;
}