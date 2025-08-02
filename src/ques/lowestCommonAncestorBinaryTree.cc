/*
Given a Binary Tree which has left, right and parent
node, present, given two node, We need to find the
lowest common ancestor (LCA) of two given nodes in
this binary tree. By definition, the LCA is the
deepest node that is an ancestor to both nodes.
To clarify, a node can be an ancestor to itself
according to this problem's definition.
*/

#include <iostream>

#include "BinarySearchTree.hpp"

int
lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode *a, *b;
    a = p;
    b = q;

    while(a != b) {
        if(a->parent() != nullptr) {
            a = a->parent();
        } else {
            a = q;
        }
        if(b->parent() != nullptr) {
            b = b->parent();
        } else {
            b = p;
        }
    }
    return a->val();  
}

int
main()
{
    vector<int> nums = {6, 3, 2, 1, 4, 5, 9, 8, 7, 11, 10, 12};
    BST tree = BST(nums);
    int q = 3;
    int p = 12;
    TreeNode* pN = tree.find(p);
    TreeNode* qN = tree.find(q);
    
    int lca = lowestCommonAncestor(tree.root(), pN, qN);
    tree.print();
    cout << "LCA : " << lca <<"\n";
    return 0;
}
