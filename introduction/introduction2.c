#include<stdio.h>

void calculate( int  * a, int * b, int  c){
    int temp_b = *b;
    int temp_a = *a;
    *a = *a * *b + c;
    *b = *a;
    
    printf("%d\t%d\n",*a,*b);
    
}


int main(){


    int a=10,b=20,c=30;

    // calculate the a*b+c and store it into both a and b.
    calculate(&a,&b,c);
    printf("%d\t%d\n",a,b);
    return 0;

}