#include<stdio.h>
#include<stdlib.h>


// Call by reference: passing reference of the variable to the function
// 
// call by value: passes variable copy to the called function. Now the copy of variable can be any kind: a variable, a pointer variable, a pointer to a pointer variable

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;


    printf("addresses in swap function\n");
    printf("%u\n", a);
    printf("%u\n", b);
    
}


struct Node{
    int val;
};

typedef struct Node node;

void SwapStruct(node * a, node * b){
    printf("\ninside swap function \n");

    printf("addresses of structures in swap\n");
    printf("%u\n", a);
    printf("%u\n", b);

    printf("addresses of pointer to structures in swap\n");
    printf("%u\n", &a);
    printf("%u\n", &b);

}

void printAddress( node ** nd){
    printf("\naddress\n");
    printf("%u\n", *nd);

}


int main(){



    int *a, *b;
    int c, d;

    c = 30;
    d = 40;

    a = &c;
    b = &d;
    scanf("%d", a);


    printf("address of a and b\n");
    printf("%u\n", a);
    printf("%u\n", b);

    swap(a, b);



    printf("address of c and d\n");
    printf("%u\n", &c);
    printf("%u\n", &d);
    swap(&c, &d);





    printf("addresses of structures\n");
    
    node * first, * second;



    printf("%u\n", first);
    printf("%u\n", second);
    first = (node *)malloc(sizeof (node) );
    second = (node *)malloc(sizeof (node) );
    printf("addresses of pointer to structures\n");

    printf("%u\n", &first);
    printf("%u\n", &second);

    printf("addresses of structures after initialization\n");

    printf("%u\n", first);
    printf("%u\n", second);

    printf("addresses of pointer to structures after initialization\n");

    printf("%u\n", &first);
    printf("%u\n", &second);

    SwapStruct(first, second);




    node third;
    node fourth;
    printf("\n\n\naddresses of structures \n");
    printf("%u\n", &third);
    printf("%u\n", &fourth);

    SwapStruct(&third, &fourth);


    node * newNode = (node *)malloc(sizeof(node));
    printf("\n\n\n\n\n\n\n\n%u\n",newNode);
    printAddress(&newNode);

    return 0;
}