// Given two binary search trees root1 and root2, 
// return a list containing all the integers from both trees sorted in ascending order.


// NOTCOMPLETED

#include<iostream>
#include<vector>
using namespace std;

struct  TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right(right){}
};


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sortedArray;
        if(root1->val < root2->val){
            vector<int> leftSortedArray = getAllElements(root1, root2->left);
            
            getAllElements( root2);    
            
            // process current node

            if(root1->right != nullptr){
                // go to right node
            }
        }
        else if(root1->val < root2->val){
           vector<int> leftSortedArray = getAllElements(root1->left, root2);
        }


    }
};