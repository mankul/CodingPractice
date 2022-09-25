#include<iostream>
#include<vector>
#include<map>
using namespace std;


typedef struct LinkedListNode{
    int val;
    struct  LinkedListNode * next;
} Node;



Node * insertToLinkedListW(Node ** node, int value){
    Node * pointer;
    if(*node == nullptr){
        pointer = new Node();
        pointer->val = value;
        pointer->next = nullptr;
        *node = pointer;
    }
    else{
        pointer = *node;
        while(pointer->next != nullptr)
            pointer = pointer->next;
        pointer->next = new Node();
        pointer->next->next = nullptr;
        pointer->next->val = value;
        pointer = pointer->next;
    }
    return pointer;
}


void insertToLinkedList(Node ** node, int value){
    if(*node == nullptr){
        *node = new Node();
        (*node)->val = value;
        (*node)->next = nullptr;
    }
    else{
        Node * pointer = *node;
        while( pointer->next != nullptr){
            pointer = pointer->next ;
        }
        pointer->next = new Node();
        pointer->next->val = value;
        pointer->next->next = nullptr;
    }
}

void displayLinkedList(Node * headPointer){
    while(headPointer != nullptr){
        cout<<headPointer->val;
        if(headPointer->next != nullptr)
            cout<<"----";
        headPointer = headPointer->next;
    }
    cout<<endl;
}



 Node * createCyclicLinkedList(vector<int> array, int position){
    Node * head = nullptr;
    Node * positionPointer = nullptr;
    Node * pointer;
    int pos = 0;
    for(auto number: array){
        pointer = insertToLinkedListW(&head, number);
        if(pos == position)
            positionPointer = pointer;
        pos++;
    }

    pointer->next = positionPointer; // creates cycle at the end of the list
    
    return head;
 }

Node * create_linked_list(vector<int> array){
    Node * head = nullptr;
    for(auto iterator: array){
        insertToLinkedList(&head, iterator);
    }

    displayLinkedList(head);

    return head;
}


// returns the size of linked list
int findCycle(Node * head, int * lastNumber, int * intersectionPoint){
    map<Node *, int> nodeHash;
    Node * pointer = head;
    int count  = 0;
    while(pointer != nullptr){
        if(nodeHash.find(pointer->next) != nodeHash.end()){
            // cycle found as pointer.next
            count += 1 ;
            *intersectionPoint = nodeHash[pointer->next];
            break;

        }
        else{
            nodeHash[pointer] = ++count;
        }
        *lastNumber = pointer->val;
        pointer = pointer->next;
    }
    if(pointer != nullptr){
        *lastNumber = pointer->val;
    }
    return count;
}



int main(){


    int length;
    cin>>length;
    int temp;
    vector<int> arr;
    for(int i = 0; i < length; i++){
        cin>>temp;
        arr.push_back(temp);
    }

    Node * head  = create_linked_list(arr);

    int lastNumber, intersectionPoint = -1;

    int count = findCycle(head, &lastNumber, &intersectionPoint);

    cout<<count<<" last number "<<lastNumber<<" intersection point at "<<intersectionPoint<<endl;

    head = createCyclicLinkedList(arr, length/2); // creating cycle at the middle position

    count = findCycle(head, & lastNumber, &intersectionPoint);
    cout<<count<<" last number "<<lastNumber<<" intersection point at "<<intersectionPoint<<endl;



    return 0;
}