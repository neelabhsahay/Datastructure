/*
Given a binary tree, get all the element
when viewd from left and right.
*/

#include<iostream>
#include "BinarySearchTree.hpp"

using namespace std;

void
print_views(vector<int> &left_view, vector<int> &right_view)
{
    
    cout <<"Left View: [";
    for(auto r: left_view) {
        cout << r<<", ";
    }
    cout <<"]\n";
    
    cout <<"Right View: [";
    for(auto r: right_view) {
        cout << r<<", ";
    }
    cout <<"]\n";
}

void
left_and_right_view(TreeNode* root)
{
    TreeNode* n;
    vector<int> left_view;
    vector<int> right_view;

    queue<TreeNode*> q;

    q.push(root);
#if 0
    int level_end;
    q.push(nullptr);

    while(!q.empty()) {
        n = q.front();
        q.pop();
        if(n == nullptr) {
            left_view.push_back(level_end);
            if(!q.empty()) {
                right_view.push_back(q.front()->val());
                q.push(nullptr); // end of one level
            }
        } else {
            level_end = n->val();
            // new level start from right so that will be in right
            // view, and ends in left view
            if(n->right() != nullptr) {
                q.push(n->right());
            }
            if(n->left() != nullptr) {
                q.push(n->left());
            }
        }
    }
#endif
     while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            n = q.front();
            q.pop();

            if (i == 0)
                left_view.push_back(n->val());
            if (size == i + 1)
                right_view.push_back(n->val());

            if (n->left() != nullptr)
                q.push(n->left());
            if (n->right() != nullptr)
                q.push(n->right());
        }
    }

    print_views(left_view, right_view);
}

int
main()
{
    vector<int> nums = {4,2,6,1,3,5,7 };
    BST tree = BST(nums);
    tree.print();
    left_and_right_view(tree.root());
    return 0;
}
