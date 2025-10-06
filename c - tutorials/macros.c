#include <stdio.h>

#define TO_STRING(x) #x

#define concat(x,y) TO_STRING(x) TO_STRING(y)

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

#define MAX(arr)({\
    int size = ARRAY_SIZE(arr);\
    typeof((arr)[0]) maxm = (arr)[0];\
    for (int i = 1; i < size; i++){\
        if ((arr)[i] > maxm) maxm = (arr)[i];\
    }\
    maxm;\
})

int main(){
    int y = 4;
    float arr[] = {3.7, 2.4, 5.7, 1.0, 6.7, 3.7, 4.9, 8.0, 10.8, 27.9, 11.8};
    //printf("%f", MAX(arr));
}

