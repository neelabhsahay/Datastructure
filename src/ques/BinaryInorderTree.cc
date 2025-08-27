/* implementation of Binary Search Tree
*/
#include<iostream>

using namespace std;

#include "BinarySearchTree.hpp"

// INT_MIN in value means its a null ptr
BIT::BIT(vector<int> &nums) {
    root_ = nullptr;
    queue<TreeNode*> q;
    TreeNode *node;
    TreeNode *left;
    TreeNode *right;
    int n = nums.size();
    if(n == 0) {
        return;
    }

    root_ = new TreeNode(nums[0]);
    q.push(root_);
    for(int i =1;i<n && !q.empty();i++) {
        node = q.front();
        q.pop();
        if(nums[i] != INT_MIN) {
            left = new TreeNode(nums[i]);
            node->left(left);
            q.push(left);
        }

        i++;
        if(i < n && nums[i] != INT_MIN) {
            right = new TreeNode(nums[i]);
            node->right(right);
            q.push(right);
        }
    }
}

void
BIT::print_preorder (ostream& os, TreeNode* n) const
{
    if(n == nullptr) {
       return;
    }
    os << n->val() << ", ";
    print_preorder(os, n->left());
    print_preorder(os, n->right());
}

void
BIT::print()
{
    cout <<"[";
    print_preorder(cout, root_);
    cout <<"]\n";
}

void
BIT::print(ostream& os) const
{
    print_preorder(os, root_);
}

// Definition of the overloaded operator<<
std::ostream& operator<<(ostream& os, const BIT& obj) {
    os <<"[";
    obj.print(os);
    os <<"]";
    return os; // Return the ostream reference for chaining
}
