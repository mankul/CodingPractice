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
    int pos = 1;
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




bool findCycleWithTwoPointerTechnique(Node * headNode){

    Node * pointer1 = headNode;
    Node * pointer2 = headNode;

    while(pointer1->next != nullptr && pointer2->next != nullptr && pointer2->next->next != nullptr){
        pointer1 = pointer1->next;
        pointer2 = pointer2->next->next;
        if(pointer1 == pointer2)
            break;
    }
    if(pointer1->next == nullptr || pointer2->next == nullptr || pointer2->next->next == nullptr)
        cout<<"cycle is not present"<<endl;
    else{
        cout<<"cycle in linked list"<<endl;
        return true;
    }
    return false;
}


int getLengthOfLoop(Node * headNode){
    Node * pointer1 = headNode;
    Node * pointer2 = headNode;
    bool isCyclePresent = false;
    while(pointer1->next != nullptr && pointer2->next != nullptr && pointer2->next->next != nullptr){
        pointer1 = pointer1->next;
        pointer2 = pointer2->next->next;
        if(pointer1 == pointer2){
            isCyclePresent = true;
            break;
        }
    }

    int count = 0;
    if(isCyclePresent){
        count = 1;
        while(pointer1->next != pointer2){
            pointer1 = pointer1->next;
            count++;
        }
    }
    return count;
}



vector<int> loopElements(Node * head){
    Node * pointer1 = head;
    Node * pointer2 = head;
    bool loopFound = false;
    while(pointer1->next != nullptr && pointer2->next != nullptr && pointer2->next->next != nullptr){
        pointer1 = pointer1->next;
        pointer2 = pointer2->next->next;
        if(pointer1 == pointer2){
            loopFound = true;
            break;
        }
    }   

    vector<int> loopElements;
    if(loopFound){
        do{
            loopElements.push_back(pointer1->val);
            pointer1 = pointer1->next;
        }while(pointer1 != pointer2);

    }
    return loopElements;
}



void printCyclicList(Node * head){
    int count = 0;
    while(count < 30)
    {
        cout<<head->val;
        head = head->next;
        count++;
    }
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

    cout<<findCycleWithTwoPointerTechnique(head)<<endl;



    head = createCyclicLinkedList(arr, length/2); // creating cycle at the middle position

    count = findCycle(head, & lastNumber, &intersectionPoint);
    cout<<count<<" last number "<<lastNumber<<" intersection point at "<<intersectionPoint<<endl;

    cout<<findCycleWithTwoPointerTechnique(head)<<endl;


    cout<<"loop length is "<<getLengthOfLoop(head)<<endl;


    vector<int> loopEl = loopElements(head);
    for(auto iterator : loopEl){
        cout<<iterator<<endl;
    }
    printCyclicList(head);
    return 0;
}