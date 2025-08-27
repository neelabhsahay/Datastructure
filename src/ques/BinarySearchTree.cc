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
BST::print_preorder (ostream& os, TreeNode* n) const
{
    if(n == nullptr) {
       return;
    }
    os << n->val() << ", ";
    print_preorder(os, n->left());
    print_preorder(os, n->right());
}

void
BST::print()
{
    cout <<"[";
    print_preorder(cout, root_);
    cout <<"]\n";
}

void
BST::print(ostream& os) const
{
    print_preorder(os, root_);
}

// Definition of the overloaded operator<<
std::ostream& operator<<(ostream& os, const BST& obj) {
    os <<"[";
    obj.print(os);
    os <<"]";
    return os; // Return the ostream reference for chaining
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
