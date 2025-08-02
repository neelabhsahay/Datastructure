// Given a Tree print as looked into mirror when mirror
// is kept at right
//         8       |        8
//       /   \     |      /   \
//      9     7    |     7     9


#include<iostream>
using namespace std;

class TreeNode {
    int val_;
    TreeNode* left_;
    TreeNode* right_;
public:
    TreeNode(int val) {
        val_ = val;
        left_ = nullptr;
        right_ = nullptr;
    }
    TreeNode* left() { return left_;}
    void left(TreeNode* left) { left_ = left;}
    TreeNode* right() { return right_;}
    int val() { return val_;}
    void right(TreeNode* right) { right_ = right;}
};

class BSTree {
    TreeNode* root;
    TreeNode* helper_insert(TreeNode *root, TreeNode* n);
    void helper_printDFS(TreeNode* root);
    TreeNode* helper_mirrorImage(TreeNode* root);
public:
    int insert(int val);
    void printDFS();
    void mirrorImage();
};

TreeNode*
BSTree::helper_insert(TreeNode *root, TreeNode* n)
{
    if(root == nullptr) {
        return n;
    }

    if(root->val() < n->val()) {
        root->right(helper_insert(root->right(), n));
    } else {
        root->left(helper_insert(root->left(), n));
    }
    return root; 
}

int
BSTree::insert(int val)
{
    TreeNode* n = new TreeNode(val);

    if(root == nullptr) {
        root = n;
        return 0;
    }
    if(root->val() < val) {
        root->right(helper_insert(root->right(), n));
    } else {
        root->left(helper_insert(root->left(), n));
    }
    return 0;
}

void
BSTree::helper_printDFS(TreeNode* root)
{
    if(root == nullptr) {
        return;
    }
    cout << root->val() <<", ";
    helper_printDFS(root->left());
    helper_printDFS(root->right());
}

void
BSTree::printDFS()
{
   cout << "[";
   helper_printDFS(root);
   cout << "]\n";
}

TreeNode* 
BSTree::helper_mirrorImage(TreeNode* root)
{
    TreeNode* l;
    if(root == nullptr) {
        return root;
    }
    l = helper_mirrorImage(root->left());
    root->left(helper_mirrorImage(root->right()));
    root->right(l);
    return root;
}

void
BSTree::mirrorImage()
{
    if(root == nullptr) {
        return;
    }
    helper_mirrorImage(root);
}


int
main()
{
    vector<int> vals = { 4,3,1,2,8,6,7,5,9};
    //vector<int> vals = {1,2,3,4,5,6,7,8,9};

    BSTree* b = new BSTree();

    for(auto v:vals) {
        b->insert(v);
    }

    b->printDFS();
    b->mirrorImage();
    b->printDFS();
    return 0;
}
