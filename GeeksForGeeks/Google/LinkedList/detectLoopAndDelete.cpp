#include<iostream>
#include<map>

using namespace std;


struct Node{
    int val;
    Node * next;
};

typedef Node node;


node * insertIntoNode(node * head, int value){
    node * pointer;
    if(head == NULL){
        head = new node();
        head->val = value;
        head->next = NULL;
    }
    else{
        pointer = head;
        while(pointer->next != NULL)
            pointer = pointer->next;
        pointer->next = new node();
        pointer = pointer->next;
        pointer->val = value;
        pointer->next = NULL;
    }
    return head;
}

node * createLoopAtIndex(node * head, int index){
    int counter = 0;
    node * pointer = head;
    node * pointerIndex = NULL;
    while(pointer->next != NULL){
        cout<<pointer->val<<endl;
        if(counter == index)
            pointerIndex = pointer;
        pointer = pointer->next;
        counter+=1;
    }
    pointer->next = pointerIndex;
    return head;
}


node * identifyAndRemoveLoop(node * head){
    map<node *, node*> dictionary;
    node * pointer = head;
    node * prevPointer;
    while(pointer != NULL){
        map<node *, node *>::iterator nodePointer;
        nodePointer = dictionary.find(pointer->next);
        // auto nodePointer = dictionary.find(pointer->next);
        if(nodePointer == dictionary.end()){
            dictionary[pointer] = prevPointer;
        }
        else{
            pointer->next = NULL; // loop is detected. breaking the loop
            break;
        }
        prevPointer = pointer;
        pointer = pointer->next;
        
    }
    return head;
}

void printNode(node * head){
    node * pointer = head;
    while(pointer != NULL){
        cout<<pointer->val;
        pointer = pointer->next;
    }
}

void printKNodes(node * head, int k){
    for(int i = 0; i < k; i++){
        if(head!= NULL)
            cout<<head->val<<"\t";
        else
            break;
        head = head->next;
    }
}

node * createLinkedList(int numbers){
    node * head;
    for(int i = 0; i < numbers; i++){
        head = insertIntoNode(head, i);
    }
    printNode(head);
    return head;
}
int main(){
    node * head;
    head = createLinkedList(20);
    printKNodes(head, 30);
    head = createLoopAtIndex(head, 10);
    printKNodes(head, 30);
    head = identifyAndRemoveLoop(head);
    printNode(head);

    return 0;
}