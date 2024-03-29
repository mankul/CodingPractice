given-a-linked-list-of-0s-1s-and-2s-sort-it




//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node * pointer = head;
        int one = 0;
        int zer = 0;
        int two = 0;
        while(pointer != NULL){
            if(pointer->data == 0)
                zer += 1;
            else if(pointer->data == 1)
                one += 1;
            else
                two += 1;
            pointer = pointer->next;
        }
        pointer = head;
        while(pointer != NULL){
            if (zer != 0){
                zer -= 1;
                pointer->data = 0;
            }
            else if(one != 0){
                one -= 1;
                pointer->data = 1;
            }
            else{
                two -= 1;
                pointer->data = 2;
            }
            pointer = pointer->next;
        }
        // Add code here
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends

