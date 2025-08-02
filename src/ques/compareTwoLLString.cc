/*
Given two singly linked list, where each node contains string,
You need to return true if the concatenated strings from both
 lists represent the same word.
e.g.

LL1 => "happy" --> "new" --> "year";
LL2 => "hap" --> "pyne"--->"wy"-->"ar"

this two are same string.
*/
#include<iostream>

using namespace std;


class Node {
    string val_;
    Node* next_;
public:
    Node(string val) {
      val_=val;
      next_ = nullptr;
    }
    string val() { return val_;}
    void next(Node* next) {next_ = next;}
    Node* next() {return next_;}
};

class LL {
    Node* head_;
public:
    LL(vector<string>&strs);
    Node* begin() {return head_;}
    void insert(string val);
    void print();
};

void
LL::insert(string val)
{
    Node* n = new Node(val);
    Node* t;
    if(head_ == nullptr) {
        head_ = n;
        return;
    }
    t = head_;
    while(t->next() != nullptr) {
       t = t->next();
    }
    t->next(n);
    return;
}   

void
LL::print() {
    Node* t = head_;
    cout << "[ ";
    while(t != nullptr) {
       cout << t->val() <<" ";
       t = t->next();
    }
    cout <<"]\n";
}

LL::LL(vector<string> &str)
{
    int sz = str.size();
    if(sz <1) {
        return;
    }
    Node* n;
    Node *t;
    head_ = new Node(str[0]);
    n = head_;
    for(int i = 1;i<sz;i++) {
        t = new Node(str[i]);
        n->next(t);
        n = t;
   }
}

bool
LLSameString(LL &l1, LL &l2)
{
    int f =0; // store for first list
    int s =0; // store postion for second list
    string ll1;
    string ll2;
    Node* nl1, *nl2;

    nl1 = l1.begin();
    nl2 = l2.begin();

    while(nl1 != nullptr && nl2 != nullptr) {
         ll1 = nl1->val();
         ll2 = nl2->val();
         while(f < ll1.size() && s< ll2.size()) {
             //cout <<"[" << ll1[f] <<"," << ll2[s] <<"], ";
             if(ll1[f] != ll2[s]) {
                 return false;
             }
             f++;
             s++;
         }
         if(f == ll1.size() && s == ll2.size()) {
             nl1 = nl1->next();
             nl2 = nl2->next();
             s = 0;
             f = 0;
         } else if(f == ll1.size()) {
             nl1 = nl1->next();
             f = 0;
         } else {
             nl2 = nl2->next();
             s = 0;
         }
    }

    if(nl1 == nullptr && nl2 == nullptr) {
        return true;
    }
    return false;
}


int
main()
{
    vector<string> str1 = {"happy","new", "year", "2025"};
    vector<string> str2 = {"hap","py", "ne","wy","ear", "20", "25"};
    LL l1 = LL(str1);
    LL l2 = LL(str2);
    l1.print();
    l2.print();
    cout << "Both LL has same strings: " << (LLSameString(l1, l2)? "YES" : "NO") <<"\n";
    return 0;
}

