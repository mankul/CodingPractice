#include<iostream>

using namespace std;


typedef struct LinkedList {
    struct LinkedList * next;
    int val;
} Node;



void createLinkedList(Node ** headPointer, int val){
    Node * node = new Node();
    node->next = nullptr;
    node->val = val;

    if(*headPointer == nullptr)
    {
        *headPointer = node;
    }
    else{
        Node * pointer = *headPointer;
        while(pointer->next != nullptr){
            pointer = pointer->next;
        }
        pointer->next = node;
    }
}

Node * getNodeForPosition(Node * headPointer, int pos){
    Node * pointer;
    int position = 0;
    while (position < pos){
        pointer = pointer->next;
        position += 1;
    }
    return pointer;
}

// Node to be deleted is not the last node of the linked list.
void deleteNode(Node ** pointerAddress){
    (*pointerAddress)->val = (*pointerAddress)->next->val;
    (*pointerAddress)->next = (*pointerAddress)->next->next;
}

void printLinkedList(Node * pointer){
    while(pointer != nullptr){
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    cout<<endl;
}


int main(){


    Node * head = nullptr;
    int totalCount = 100;
    for(int i = 0; i < totalCount; i++){
        createLinkedList(&head, i);
    }

    Node * pointer = getNodeForPosition(head, totalCount/2);


    printLinkedList(head);

    deleteNode(&pointer);

    printLinkedList(head);

    return 0;

}