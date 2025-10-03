#include <stdio.h>

int nCr(int n, int r){
    int ans = 1;
    for (int i = 0; i < r; i++){
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
}

int element(int n, int r){
    return nCr(n-1, r-1);
}

void printrow(int row){
    // row is 1-indexed, col is 0-indexed

    int ans = 1;
    printf("%d\t", ans);

    for (int i = 1; i < row; i++){
        ans = (ans * (row - i))/(i);
        printf("%d\t", ans);
    }
    printf("\n");
}

void printpascal(int n){
    for (int i = 1; i <= n; i++){
        printrow(i);
    }
}

int main(){
    printf("5th row, 3rd col = %d\n", element(5,3));
    printf("6th row, 4th col = %d\n", element(6,4));
    printpascal(6);
    return 0;
}