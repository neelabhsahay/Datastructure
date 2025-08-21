//
// Given the root of a binary search tree (BST) with duplicates,
// return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:
//The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//
#include <iostream>

#include "BinarySearchTree.hpp"

using namespace std;

class FMBST {

void 
countElement(TreeNode* root, int num, int precount, int &maxcount, vector<int> &count)
    {
        if(root == nullptr) {
            return ;
        }

        if(root->val == num) {
            precount++;
            if(maxcount == precount) {
                count.push_back(root->val);
            } else if(maxcount < precount) {
                count = {root->val};
            }
        } else {
            precount =1;
        }

        cout << "[" << root->val<<":"<<precount<<"] ";

        if(root->left != nullptr) {
            countElement(root->left, root->val, precount, maxcount, count);
        }

        if(root->right != nullptr) {
            countElement(root->right, root->val, precount, maxcount, count);
        }
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> count = {root->val};
        int maxcount =1;
        countElement(root->left,root->val, 1, maxcount, count);
        countElement(root->right,root->val, 1, maxcount, count);

        return count;
    }
};


int
main()
{
    vector<int> nums = {};
    BST tree = BST(nums);
    tree.print();
    FMBST fmbst = FMBST();
    vector<int> result = fmbst.findMode(tree.root());
    cout << result<<"\n";
    return 0;
}
