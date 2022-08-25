#include<stdio.h>
#include<stdlib.h>

struct structure{
    int val;
};

typedef struct  structure str;

void address(int * pointer){
    printf("address and value of pointer in called function\n");
    printf("%u\n",pointer);
    printf("%u\n",*pointer);

}

void structureAddress(str * pointer){
    printf("address and value of pointer in called function\n");
    printf("%u\n",pointer);
    printf("%u\n",*pointer);


    printf("reallocating dynamic memory in called function\n");
    pointer = (str *)malloc(sizeof(str) );
    printf("%u\n",pointer);
    printf("%u\n",*pointer);

}

str ** pointerToStructurePointer(str ** doublePointer){
    str * pointer = (str *)malloc(sizeof(str));
    doublePointer = &pointer;
    printf("allocating dynamic memory in called function to pointer To a Structure pointer\n");
    printf("%u\n",*doublePointer);
    return doublePointer;
}



int main(){

    int * pointer;
    int a;

    printf("address and value of pointer\n");
    printf("%u\n",pointer);
    // printf("%u\n",*pointer);


    pointer = &a;

    printf("address and value of pointer after assigning\n");
    printf("%u\n",pointer);
    printf("%u\n",*pointer);

    address(pointer);


    // allocating memory in run time

    pointer = (int *)malloc(sizeof(int));
    printf("address and value of pointer after dynamic memory allocation\n");
    printf("%u\n",pointer);
    printf("%u\n",*pointer);
    address(pointer);
 


    // allocating a structure

    str * pointerStructure;
    printf("address and value of structure pointer\n");
    printf("%u\n",pointerStructure);


    str newStructure;
    pointerStructure = &newStructure;     


    printf("address and value of structure pointer after assigning\n");
    printf("%u\n",pointerStructure);
    printf("%u\n",pointerStructure->val);

    structureAddress(pointerStructure);
    printf("address after called function replaces reallocate memory\n");
    printf("%u\n",pointerStructure);



    // dynamic memory allocating

    pointerStructure = (str *)malloc(sizeof(str));

    printf("address and value of structure pointer after memory allocation \n");
    printf("%u\n",pointerStructure);
    printf("%u\n",pointerStructure->val);

    structureAddress(pointerStructure);
    printf("address after called function replaces reallocate memory\n");
    printf("%u\n",pointerStructure);


    printf("\n\n\n\n\n\n*********************\n");

    str * newPointer;
    pointerToStructurePointer(&newPointer);
    printf("double pointer initialized in called function, printing in calling function\n");
    printf("%u\n", newPointer);


    str ** doublePointer;
    doublePointer = pointerToStructurePointer(doublePointer);
    printf("double pointer initialized in called function, printing in calling function\n");
    printf("%u\n", *doublePointer);

    return 0;
}