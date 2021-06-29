


// #include<<stdlib.h
#include<stdio.h>
#include<stdlib.h>

#define x1 10010    
#define x2 x1, x1
#define x4 x2, x2
#define x8 x4, x4
#define x16 x8, x8
#define x32 x16, x16
#define x64 x32, x32

// you want to define a array of size 64 with all same values


int main(){
    int arr[64] = {x64};

    for(int i = 0; i< 64; i++)
        printf("%d\n", arr[i]);
    return 0;
}

