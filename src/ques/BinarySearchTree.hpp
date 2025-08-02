#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

#include<vector>

using namespace std;

class TreeNode {
    int val_;
    TreeNode* left_;
    TreeNode* right_;
    TreeNode* parent_;
public:
    TreeNode(int val) { val_= val; left_ = nullptr; right_ = nullptr;}
    void left(TreeNode* left) { left_ = left;}
    void right(TreeNode* right) { right_ = right;}
    void parent(TreeNode* parent) { parent_ = parent;}
    TreeNode* left() {return left_;}
    TreeNode* right() {return right_;}
    TreeNode* parent() { return parent_;}
    int val() { return val_;}
};

class BST {
    TreeNode* root_;
    TreeNode* insert_helper(TreeNode* root, int val);
    void print_preorder(TreeNode* n);
    TreeNode* find_helper(TreeNode* root, int val); // return first occurance of the value 
public:
    BST(vector<int> &nums);
    TreeNode* root() { return root_;}
    void print();
    TreeNode* find(int val); // return first occurance of the value 
};
#endif  //  __BINARY_SEARCH_TREE_HPP__
