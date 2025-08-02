/*
Given a binary tree, return the values of its boundary in
 anti-clockwise direction starting from root.
 Boundary includes left boundary, leaves, and
 right boundary in order without duplicate nodes.
(The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node.
 Right boundary is defined as the path from root to the right-most node.
 If the root doesn't have left subtree or right subtree,
 then the root itself is left boundary or right boundary.
 Note this definition only applies to the input binary tree,
 and not applies to any subtrees.
*/

#include<iostream>
#include "BinarySearchTree.hpp"

using namespace std;

void
boundary_right_helper(TreeNode* root, vector<int> &result) {
    if(root == nullptr) {
        return ;
    }
    result.push_back(root->val());
    if(root->right() == nullptr) {
        boundary_right_helper(root->left(), result);
    } else {
        boundary_right_helper(root->right(), result);
    }
}

void
boundary_right(TreeNode* root)
{
    vector<int> result;
    boundary_right_helper(root, result);
    cout <<"[";
    for(auto r: result) {
        cout << r<<", ";
    }
    cout <<"]\n";
}

void
boundary_left_helper(TreeNode* root, vector<int> &result) {
    if(root == nullptr) {
        return ;
    }
    result.push_back(root->val());
    if(root->left() == nullptr) {
        boundary_left_helper(root->right(), result);
    } else {
        boundary_left_helper(root->left(), result);
    }
}

void
boundary_left(TreeNode* root)
{
    vector<int> result;
    boundary_left_helper(root, result);
    cout <<"[";
    for(auto r: result) {
        cout << r<<", ";
    }
    cout <<"]\n";
}

int
main()
{
    vector<int> nums = {4,2,6,1,3,5,7 };
    BST tree = BST(nums);
    tree.print();
    boundary_left(tree.root());
    boundary_right(tree.root());
    return 0;
}
