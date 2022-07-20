// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit.
//  Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero,
//  except the number 0 itself.

// COMPLETED // SCOPE IMPROVEMENT

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * head = l1;
        while(l1 ->next != nullptr && l2 -> next != nullptr){
            carry += (l1->val + l2->val);
            l1->val = carry % 10;    
            carry = carry/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 -> next == nullptr && l2 ->next == nullptr){
         
            carry += (l1->val +  l2->val);
            l1->val = carry%10;
            carry /= 10;
            if(carry != 0)
                l1->next = new ListNode(carry);
            
        } 
        else if(l1->next != nullptr){
           
            carry += (l1->val + l2->val);
            l1->val = carry % 10;
            carry /= 10;
            l1 = l1->next;
            while(l1->next != nullptr){
             
                carry+=l1->val;
                l1->val = carry%10;

                carry = carry/10;
             

                l1 = l1->next;
            }
            if(carry > 0){
                carry = (l1->val + carry);
                l1->val = carry %10;
                carry = (carry)/10;
                if(carry > 0){
                ListNode * endingNode = new ListNode(carry);
                l1->next = endingNode;
                }
            }
        }
        else{
            carry += (l1->val + l2->val);
            l1->val = carry%10;
            carry /= 10;
            l1->next = l2->next;
            l1 = l1->next;
            while(l1->next != nullptr){
                carry += l1->val;
                l1->val = carry %10;
                carry = carry/10;
                l1 = l1->next;
            }
            if(carry > 0){
                carry = (l1->val + carry);
                l1->val = carry %10;
                carry = (carry)/10;
                if(carry > 0)
                {
                    ListNode * endingNode = new ListNode(carry);
                    l1->next = endingNode;
                    }
                
            }
        }
        return head;

    }
};

ListNode * createNumber(int num){
    ListNode * head;
    ListNode *  node;
    node = new ListNode( num %10);
    head = node;
    num = num/10;
    while (num > 0)
    {
        node->next = new ListNode(num%10);
        num = num/10;
        node = node->next;
    }
    return head;
    
}

int main(){

    int m, n, val;
    cin>>m>>n;
    ListNode * istNumber = createNumber(m);
    ListNode * scndNumber = createNumber(n);
    
    Solution s;
    ListNode * pointer = s.addTwoNumbers(istNumber, scndNumber);
    while(pointer != nullptr){
        cout<<pointer->val;
        pointer = pointer -> next;
    }
    
    return 0;
}