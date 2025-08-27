/*
   given a Binary tree get all elements in vertical order
   e.g.
                  7
                 / \
                /   \
               4     5
              / \   / \
             2  3  1   6

   Answer: [[2],[4],[7,3,1],[5],[6]]
*/
#include<map>
#include<iostream>
#include "BinarySearchTree.hpp"

#include "utils.hpp"

using namespace std;


void
verticalOrderTraverseHelper(TreeNode* root, 
                            map<int, vector<int>> &loc,
                            int pos)
{
    if(root == nullptr) {
        return;
    }
    
    loc[pos].push_back(root->val());

    verticalOrderTraverseHelper(root->left(), loc, pos-1);
    verticalOrderTraverseHelper(root->right(), loc, pos+1);
}

vector<vector<int>>
verticalOrderTraverse(TreeNode* root)
{
    vector<vector<int>> result;

    // contain postion to value vector
    map<int, vector<int>> loc;

    verticalOrderTraverseHelper(root, loc, 0); 

    for(auto l:loc) {
        result.push_back(l.second);
    }
    return result;
}

int
main()
{
    vector<int> nums = {6,3,4,2,5,1,9,8,11,7,12,10};
    vector<vector<int>> result;
    BST tree = BST(nums);
    
    tree.print();
    result = verticalOrderTraverse(tree.root());
    cout << "Result : " << result << "\n";
    return 0;
}
    
    
