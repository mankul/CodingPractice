#include<iostream>
#include<map>
using namespace std;

struct LinkedListNode{
    int val;
    struct LinkedListNode * next;
    struct LinkedListNode * arbitrary;
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
        pointer->arbitrary = NULL;
    }
}


void display_list(node * pointer){
    while(pointer != NULL){
        cout<<pointer->val<<endl;
        pointer = pointer->next;
    }
}

node * optimaLstrategy(node * head){// 1, 3 6, 7
    node * deep = NULL;
    node * headPointer = head;
    node * deepPointer;
    map<node * , node *> mapHeadDeepPointers;
    while(headPointer != NULL){
        if(deep == NULL){            
            deep = new node();
            deepPointer = deep;
        }
        else{
            deepPointer->next = new node();
            deepPointer = deepPointer->next;
        }
        
        deepPointer->val = headPointer->val;
        mapHeadDeepPointers[headPointer] = deepPointer;
        headPointer = headPointer->next;

    }
    headPointer = head;
    deepPointer = deep;
    while(headPointer != NULL){
        deepPointer->arbitrary = mapHeadDeepPointers[deepPointer->arbitrary];
        deepPointer = deepPointer->next;
        headPointer = headPointer->next;
    }
    return deep;
}


node * deepCopyOfLinkedList(node * head){
    node * headPointer  = head;
    node * deepPointer=NULL;
    node * pointer;
    map<node * , node *> mapArbitraryNode;
    map<node *, node *> nodePointer;
    while(headPointer != NULL){
        if(deepPointer == NULL){
            // first insertion to the deepPointer
            deepPointer = new node();
            deepPointer->val = headPointer->val;
            mapArbitraryNode[headPointer->arbitrary] = deepPointer;
            pointer = deepPointer;
            headPointer = headPointer->next;
        }
        else{
            pointer->next = new node();
            pointer = pointer->next;
            if(mapArbitraryNode.find(headPointer) != mapArbitraryNode.end()){
                mapArbitraryNode[headPointer]->arbitrary = pointer;
                mapArbitraryNode.erase(headPointer);
            }
            pointer->val = headPointer->val;
            mapArbitraryNode[headPointer->arbitrary] = pointer; 
            headPointer = headPointer->next;
        }
    }

    pointer = deepPointer;
    headPointer = head;

    for(auto iterator = mapArbitraryNode.begin(); iterator != mapArbitraryNode.end(); iterator++){
        pointer = deepPointer;
        headPointer = head;
        while(headPointer != iterator->first){
            headPointer = headPointer->next;
            pointer = pointer->next;
        }
        iterator->second->arbitrary = headPointer;
    }    

    return deepPointer;

}


int main(){
    int size1;
    node * head1;
    cin>>size1;
    createLinkedList(head1, size1);

    node * copyNode;


    copyNode = optimaLstrategy(head1);

    display_list(head1);
    display_list(copyNode);

    return 0;

}
