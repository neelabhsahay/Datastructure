/* Given the root of a binary tree, imagine yourself standing on
* the right side of it, return the values of the nodes
* you can see ordered from top to bottom.
*
*           9
*         /  \
*       10    11
*        \     \
*        12     13
*         \
*          14
*  Output:
*      [9,11,13,14]
*
* Similarly left side view for same
*  output:
*       [9, 10, 12,14]
*/
#include<iostream>

#include "BinarySearchTree.hpp"
#include "utils.hpp"

using namespace std;

void
leftRightView(TreeNode* root, vector<int> &leftView,
              vector<int> &rightView)
{
    queue<TreeNode*> q;
    TreeNode* n;
    int size;
    if(root == nullptr) return;
    q.push(root);

    while(!q.empty()) {
        size = q.size();
        for(int i = 0;i<size;i++) {
            n = q.front();
            q.pop();
            // we push first right child hence first in level goes to
            // rightView and last in leftView 
            if(i == 0) {
                rightView.push_back(n->val());
            }
            if(i == size -1) {
                leftView.push_back(n->val());
            }
            if(n->right() != nullptr) {
                q.push(n->right());
            }
            if(n->left() != nullptr) {
                q.push(n->left());
            }
        }
    }
    return;
}

int
main()
{
    vector<int> nums= {9,10,11,INT_MIN,12,INT_MIN,13,INT_MIN,14}; // INT_MIN neams a null
    BIT tree = BIT(nums);
    vector<int> leftView;
    vector<int> rightView;

    leftRightView(tree.root(), leftView, rightView);

    cout << tree << " Left view: " << leftView << " Right view: " << rightView <<"\n";
    return 0; 
}
