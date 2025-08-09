/*
Given a Binary Tree which has left, right and parent
node, present, given two node, We need to find the
lowest common ancestor (LCA) of two given nodes in
this binary tree. By definition, the LCA is the
deepest node that is an ancestor to both nodes.
To clarify, a node can be an ancestor to itself
according to this problem's definition.

Algo:
    Start from both node,move up towards root, 
    if we reached root, switch and start form other node,
    since the first travel x distance to root, second
    travel distance y to root, total distance both
    travel is x + y, 
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
    //vector<int> nums = {6, 3, 2, 1, 4, 5, 9, 8, 7, 11, 10, 12};
    vector<int> nums = {30,29,28,27,20,19,21,18,22,16,24, 15, 17, 23, 26, 14};
    BST tree = BST(nums);
    int p = 14;
    int q = 26;
    TreeNode* pN = tree.find(p);
    TreeNode* qN = tree.find(q);
    
    int lca = lowestCommonAncestor(tree.root(), pN, qN);
    tree.print();
    cout << "LCA of " << p << " and " << q <<" is : " << lca <<"\n";

    return 0;
}
