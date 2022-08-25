#include<iostream>

using namespace std;

struct LinkedListNode{
    int val;
    struct LinkedListNode * next;
};


typedef struct LinkedListNode node;


void display_list(node * pointer);

void createLinkedList(node * & head, int size){
    int value;
    node * pointer;
    for(int i = 0; i < size ; i++){
        cin>>value;
        if(head == NULL){
            head = new node();
            pointer = head;
            }
        else{
            pointer->next = new node();
            if(pointer->next == NULL){
                cout<<"pointer initialized points to garbage"<<endl;
            }
            pointer = pointer->next;
        }
        pointer->val = value;
        pointer->next = NULL;    
    }
}


node * mergeLinkedLists(node * pointer1, node * pointer2){
    node * mergePointer;
    node * mergedList = NULL;
    display_list(pointer1);
    display_list(pointer2);
    if(mergedList == NULL){
        cout<<"mergeList variable declare"<<endl;
    }
    while(1){
        if(pointer1 == NULL && pointer2 == NULL)
            break;
        else if(pointer1 == NULL){
            if(mergedList == NULL)
                mergedList = pointer2;
            else
                mergePointer->next = pointer2;
            break;
        }
        else if(pointer2 == NULL){
            if(mergedList == NULL)
                mergedList = pointer1;
            else
                mergePointer->next = pointer1;
            break;
        }
        else if(mergedList == NULL){
            if(pointer1->val < pointer2->val){
                mergedList= pointer1;
                mergePointer = mergedList;
                pointer1 = pointer1->next;
            }
            else{
                mergedList = pointer2;
                mergePointer = mergedList;
                pointer2 = pointer2->next;
            }
        }
        else{
            if(pointer2->val < pointer1->val){
                mergePointer->next = pointer2;
                pointer2 = pointer2->next;
                mergePointer = mergePointer->next;
            }
            else{
                mergePointer->next = pointer1;
                pointer1 = pointer1->next;
                mergePointer = mergePointer->next;

            }
        }
    }

    return mergedList;
}


void display_list(node * pointer){
    while(pointer != NULL){
        cout<<pointer->val<<endl;
        pointer = pointer->next;
    }
}

int main(){
    int size1, size2;
    node * head1;
    node * head2;
    cin>>size1>>size2;
    createLinkedList(head1, size1);
    createLinkedList(head2, size2);


    node * mergedList = mergeLinkedLists(head1, head2);

    display_list(mergedList);
    return 0;
}