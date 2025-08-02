/* implementation of Binary Search Tree
*/
#include<iostream>

using namespace std;

#include "BinarySearchTree.hpp"

TreeNode*
BST::insert_helper(TreeNode* root, int val) 
{
    if(root == nullptr) {
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }
    
    if(root->val() < val) {
        root->right(insert_helper(root->right(), val));
        root->right()->parent(root);
    } else {
        root->left(insert_helper(root->left(), val));
        root->left()->parent(root);
    }
    return root;
}

BST::BST(vector<int> &nums) {
    root_ = nullptr;
    int n = nums.size();
    if(n == 0) {
        return;
    }

    for(int i =0;i<n;i++) {
        root_ = insert_helper(root_, nums[i]);
    }
}

void
BST::print_preorder(TreeNode* n)
{
    if(n == nullptr) {
       return;
    }
    cout << n->val() << ", ";
    print_preorder(n->left());
    print_preorder(n->right());
}

void
BST::print()
{
    cout <<"[";
    print_preorder(root_);
    cout <<"]\n";
}

TreeNode*
BST::find_helper(TreeNode* root, int val)
{
    if(root == nullptr) {
        return root;
    }
    if(val == root->val()) {
        return root;
    }

    if (val < root->val()) {
        return find_helper(root->left(), val);
    } else {
        return find_helper(root->right(), val);
    }
}

TreeNode*
BST::find(int val) {
     return find_helper(root_, val);
}
