

// Compilers
// MAchine dependent
 
// converts human readable format code to assembly language/ machine language
// code




// Lets talk about c

// include preprocessors

// in which we have include statements

// in the process


// Lets start coding

// Compilers

// _____ a, find address of a or location of the variable a -> & 
// call by reference or call by value. The values are passed to a function or message 
// being passed.
// Csharp . Microsoft. Call by refernece. Method u pass a variable. A variable address 
// is passed. But in c, cpp, o c, variable value is passed. In the funciton,  a local variable
// is generated. and the value is assigned as the value being passed. As the function is returned,
// the local variable is removed from the stack.




// 0x12445643 a
// b



#include<stdio.h>
#define Length 10

void display(int a){
    printf("%d", a);
}

// scope.
// when u call a function. when we return, the local variables are vanished.


void sum(int a, int b){
    int sum_ = a + b + 10;
    display(sum_);
}

void main(){
    int a, b;
    
    scanf("%d%d",&a,&b);
    int sum_ = a+b;
    display(sum_);
    sum(a,b);
    display(sum_);
}


// * value at the address
// & address of the variable
// 

// pointers :- int a 0X1253463
// int c = 35;

// int * address_of_int = &a;
// address_of_int = &b;






