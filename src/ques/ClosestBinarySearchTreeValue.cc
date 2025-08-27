/*
* You're given the root of a binary search tree (BST) and a target value.
* You need to find the value in the BST that is closest to the target value.
* Binary Search Tree: the left child has a value less than the node's value,
* and the right child has a value greater than the node's value.
*/

#include<iostream>

#include "BinarySearchTree.hpp"
#include "utils.hpp"

using namespace std;

int
closestBSTValue(TreeNode* root, double target)
{
    int sub_tree_val;
    if(root == nullptr) {
        return target;
    }

    if(root->val() < target) {
        if (root->right() != nullptr) {
            sub_tree_val = closestBSTValue(root->right(), target);
        } else {
            sub_tree_val = root->val();
        }
    } else {
        if (root->left() != nullptr) {
            sub_tree_val = closestBSTValue(root->left(), target);
        } else {
            sub_tree_val = root->val();
        }
    }

    // Check if the current difference is less than the minimum difference found so far.
    // If the differences are equal, we prioritize smaller values per the problem's constraint.
    if(abs((double)sub_tree_val - target) < (abs((double)root->val() - target))) {
        return sub_tree_val;
    } else {
        return root->val();
    }
}

int
main()
{
    vector<int> nums = {4,3,1,2,8,9,5};
    double target = 6.4;

    BST tree = BST(nums);
    int c_bst_val = closestBSTValue(tree.root(), target);
    cout << "Closest Value to target " << target << " in tree " << tree <<" is " << c_bst_val <<"\n";
    return 0;
}
