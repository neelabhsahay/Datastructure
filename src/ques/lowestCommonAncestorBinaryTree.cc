/* Given a binary tree, find the lowest common ancestor (LCA)
* of two given nodes in the tree.
*
* According to the definition of LCA on Wikipedia:
* “The lowest common ancestor is defined between two nodes p and q
* as the lowest node in T that has both p and q as descendants
* (where we allow a node to be a descendant of itself).”
*/
#include<iostream>

#include "utils.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

// return if null is found or item not found
TreeNode*
lowestCommonAncestorBinaryTree(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode *left = nullptr, *right = nullptr;
    if(root == nullptr) {
        return nullptr;
    }

    if(root->val() == q->val() ||
       root->val() == p->val()) {
        return root;
    }

    left = lowestCommonAncestorBinaryTree(root->left(), p, q);
    right = lowestCommonAncestorBinaryTree(root->right(), p, q);

    // if the items are found in left and right, means the present node
    // is there ancestor, since we don't have duplicate hence p and q cannot
    // be in two places i.e. in both subtree
    if(left != nullptr && right != nullptr) {
        return root;
    }

    return (left != nullptr) ? left : right;
}


#ifndef IS_LIB
int
main()
{
    // INT_MIN is equal to nullptr
#if 0
    vector<int> nums = {3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
    int pv = 5;
    int qv = 1;
#endif
    vector<int> nums = {3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
    int pv = 5;
    int qv = 4;
    
#if 0
    vector<int> nums = {1,2};
    int pv = 1;
    int qv = 2;
#endif

    TreeNode *p = new TreeNode(pv);
    TreeNode *q = new TreeNode(qv);

    BIT tree = BIT(nums);
    TreeNode *ancestor = lowestCommonAncestorBinaryTree(tree.root(), p, q);

    cout << tree << " Ancestor of " << pv << " and " <<  qv <<
            " is " << ancestor->val() << "\n";
    return 0;
}

#endif
