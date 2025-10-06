#include <stdio.h>

#define DEBUG
#undef DEBUG

#define MODE 10

//#define FEATURE_X
//#define FEATURE_Y

int main(){
    #ifdef DEBUG 
    printf("Debug Build\n");
    #else 
    printf("Release Build\n");
    #endif

    #ifdef MODE 
        #if MODE == 1
        printf("Mode is 1\n");
        #elif MODE == 2
        printf("Mode is 2\n");
        #else
        printf("Mode is %d\n", MODE);
        #endif
    #endif

    #if defined(FEATURE_X) && defined(FEATURE_Y)
    printf("Both X and Y enabled\n");

    #elif defined(FEATURE_X)
    printf("Only X enabled\n");

    #elif defined(FEATURE_Y)
    printf("Only Y enabled\n");

    #else 
    printf("Neither enabled");

    #endif

}