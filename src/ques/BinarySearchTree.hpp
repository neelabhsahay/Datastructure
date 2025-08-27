#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

#include<vector>

#include "utils.hpp"

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
    const int val() const { return val_;}
};

// create binary search Tree
class BST {
    TreeNode* root_;
    TreeNode* insert_helper(TreeNode* root, int val);
    void print_preorder(ostream& os, TreeNode* n) const;
    TreeNode* find_helper(TreeNode* root, int val); // return first occurance of the value 
public:
    BST(vector<int> &nums);
    TreeNode* root() const { return root_;}
    void print();
    void print(ostream& oc) const;
    TreeNode* find(int val); // return first occurance of the value 
    // Declare the overloaded operator<< as a friend function
    friend std::ostream& operator<<(ostream& os, const BST& obj);
};

// this creates binary tree using inorder
class BIT {
    TreeNode* root_;
    void print_preorder(ostream& os, TreeNode* n) const;
public:
    BIT(vector<int> &nums);
    TreeNode* root() { return root_;}
    void print();
    void print(ostream& oc) const;
    // Declare the overloaded operator<< as a friend function
    friend std::ostream& operator<<(ostream& os, const BIT& obj);
};
#endif  //  __BINARY_SEARCH_TREE_HPP__
