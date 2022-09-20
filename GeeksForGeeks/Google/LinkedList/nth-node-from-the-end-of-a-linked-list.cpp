#include<iostream>

using namespace std;
struct Node{
    Node * next;
    int value;
};


typedef struct  Node node;


void nth_from_last(node * pointer, int & current_position, int position, int & positionElement){
    if(pointer->next == nullptr){
        current_position = 1;
        if(current_position == position){
            positionElement = pointer->value;
        }
        return;
    }

    nth_from_last(pointer->next, current_position, position, positionElement);
    current_position += 1;
    if(current_position == position)
        positionElement = pointer->value;
    
}

void display(node * head){
    while(head != nullptr)
    {
        cout<<head->value<<endl;
        head = head->next;
    }
}

int main(){

    int num;
    cin>>num;
    node * head = nullptr;
    node * pointer;
    for(int i = 0; i < num; i++){
        if(head == nullptr){
            head = new node();
            cin>>head->value;
            head->next = nullptr;
            pointer = head;
            
        }
        else{
            pointer->next = new node();
            pointer = pointer->next;
            cin>>pointer->value;
            pointer->next = nullptr;
        }
    }
    // display(head);

    int position;
    cin>>position;

    int current_position = 0;
    int positionElement = -1;

    nth_from_last(head, current_position, position, positionElement);
    cout<<positionElement<<endl;




    return 0;
}