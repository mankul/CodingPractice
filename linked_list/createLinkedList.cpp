#include<iostream>


using namespace std;



struct LinkedListNode{
    int val;
    struct LinkedListNode * next;
};


typedef struct LinkedListNode Node;


void printLinkedList(Node * head){
    Node * node = head;
    while(node != NULL){
        cout<<node->val<<endl;
        node = node->next;
    }
}




void createLinkedList(Node ** doublePointer, int val){
    Node * node = new Node();
    node->next = NULL;
    node->val = val;
    if(*doublePointer == NULL){
        *doublePointer = node;
        return;
    }
    Node * pointer = *doublePointer;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = node;
}

void insertLinkedList(Node * &head, int val){
    Node * node = new Node();
    node->next = NULL;
    node->val = val;
    if(head == NULL){
        head = node;
        return;
    }
    Node * pointer = head;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = node;
}


int main(){

    Node * head;
    for(int i = 0 ; i < 100; i++)
        createLinkedList(&head, i);
        // insertLinkedList(head, i);
    printLinkedList(head);





    return 0;
}