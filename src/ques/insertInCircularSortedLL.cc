/* Given a head of circular on decreasing linked list
 * insert the element in that list, the head may not be the
 * smallest node.
 * head
 * |
 * 45--> 5-->7-->19-->23-->34-+
   ^                          |
   |                          |
   +--------------------------+
*/

#include<iostream>

using namespace std;

class Node {
    int val_;
    Node* next_;
public:
    Node(int val) { 
                val_= val;
                next_ = nullptr;
            }
    Node* next() {return next_;}
    void  next(Node* n) { next_ = n;}
    int val() {return val_;}
};

class CLL {
    Node* head_;
public:
    CLL() { head_ = nullptr;}
    void insert(int val);
    Node* insertNode(int val); // return the node which is inserted
    void print();
    void print(Node* n);
};

Node*
CLL::insertNode(int val) {
    Node* n = new Node(val);
    Node* t = head_;
    if(head_ == nullptr) {
        head_ = n;
        head_->next(head_);
        return n;
    }

    // check that we reach the start or we found a place
    // to insert the value.    
    while(t->next()->next() != head_ && t->next()->val() < val) {
        t = t->next();
    }
    if(t->next()->next() == head_) {
        n->next(t->next()->next());
        t->next()->next(n);
    } else if(t->next()->val() >= val) {
        n->next(t->next());
        t->next(n);
    }
    return n;
}

void
CLL::insert(int val) {
    insertNode(val);
}

void
CLL::print(Node* n)
{
    Node* t = n;
    cout <<"[";
    if(n == nullptr) {
        cout <<"]\n";
        return;
    }
    do {
        cout << t->val() <<", ";
        t = t->next();
    } while(t != n);
    cout <<"]\n";
}

void
CLL::print()
{
    print(head_);
}


int
main()
{
    //vector<int> nums = {45,8,10,10,15,20};
    vector<int> nums = {5,8,10,10,15,20};
    CLL l;
    for(auto n:nums) {
        l.insert(n);
    }
    l.print();
    l.insert(10);
    l.print();
    l.insert(6);
    l.print();
    Node* p = l.insertNode(12);
    l.print(p);
    return 0;
} 
