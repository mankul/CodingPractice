// // pointers in C


// pointers = address valiue
// the variables which stores the addresses


// for example
// we want a pointer to a integer 

// int * pointer;
// where pointer is a variable which contains a address to the integer.

// likewise

// struct node{
//     char * name;
//     int class;
//     char * phone_number;
// }


// (head) !value!next!->!value!next!->!value!next!->!value!NULL!


// linked list node, tree node, graph node.

#include<stdio.h>
#include<stdlib.h>

#define LENGTH 20

struct node {
    int value;
    struct node * next;

};


void display_linked_list(struct node * head){
    struct node * pointer;
    pointer = head;
    while (pointer != NULL)
    {
        printf("%d\t", pointer->value);
        pointer = pointer->next;
    }
    
}



void insertion_to_end(int value_, struct node * head){

    struct node * pointer = (struct node *)malloc(sizeof(struct node));
    (*pointer).value = value_;
    // (*pointer).next = NULL;
    pointer->next = NULL;

    if (head == NULL){ 
        printf("Head is null");
        head = pointer;
        printf("%d", head->value);
    }
    else{
        printf("head is not null");
        struct node * pointer_visit_a_node;
        while(pointer_visit_a_node->next != NULL )
            pointer_visit_a_node = pointer_visit_a_node->next;
        pointer_visit_a_node->next = pointer;
        
    }
    // return head;
}




int main(){

    struct node * head;
    // head = NULL;

    for(int i = 0; i < LENGTH;i++){
        insertion_to_end(i,head);
    }
    
    display_linked_list(head);

    // insertion of a value into this linked list into the end

}

