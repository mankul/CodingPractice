//Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.


//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        Node * prevPointer = NULL;
        Node * pointer = head;
        Node * nextPointer;
        int count = 0;
        while(pointer != NULL){
            count += 1;
            
            //  store the next pointer
            nextPointer = pointer->next;
            // reverse the chain
            pointer->next = prevPointer;
            
            // upgrade the pointers for next loop
            prevPointer = pointer;
            pointer = nextPointer;
            
        }
        
        // Now prevPointer is the head of the reversed list
        
        if(count >= n){
            pointer = prevPointer;
            for( ;  n > 1 ; n--)
                pointer = pointer->next;
            return pointer->data;
        }
        else{
            return -1;
        }
        
           // Your code here
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
