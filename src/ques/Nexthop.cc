#include <iostream>
using namespace std;

class Node {
public:
    Node* next_;
    int val_; // just to keep value
public:
    Node(int v);
    Node* next() { return next_;}
    int val() { return val_;}
    void next(Node* n) { next_=n;} 
};

Node::Node(int val) {
val_=val;
next_ = nullptr;
}

class LL {
    Node* head;
public:
    int reverse_LL(int s_idx, int e_idx);
    int insert(int val);
    void print();
};

int
LL::reverse_LL(int s_idx, int e_idx)
{
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* last = nullptr; // store last after which reverse
    Node* first = nullptr; // store first from where reverse start
    Node* n = head;

    if(head == nullptr) {
        return 0; // empty linked list
    }
    int count = 0; 

    while(count < s_idx && n != nullptr) {
        count++;
        last = n;
        n = n->next();
    }
    if(count <s_idx) {
        return -1; // linked list given is less that start position;
    }
  
    first = n;
    prev = last; 
    while(count <= e_idx && n != nullptr) {
        count++;
        next = n->next();
        n->next(prev);
        prev = n;
        n = next;
    }


    if(last == nullptr) {
        head = prev;
    } else if(last != prev) {
        last->next(prev);
    }
    if(first != nullptr) {
        first->next(n);
    }
    
    if(count < e_idx) {
         cout << "Count " << e_idx << " Great than LL length: " << count << "\n"; 
         reverse_LL(s_idx, count-1);
         return -1; // linked list given is less that end postion    
    }

    return 0;
}

void
LL::print() {
    Node* n = head;
    cout <<"[";
    while( n != nullptr) {
        cout << n->val() << " ";
        n = n->next();
    }
    cout << "]\n";
}

int
LL::insert(int val) {
    Node* n = new Node(val);
    Node* itr=head;
    
    if(head == nullptr) {
        head = n;
        return 0;
    }

    while(itr->next() != nullptr) {
        itr = itr->next();
    }

    itr->next(n);
    return 0;

}

int main()
{
    //vector<int> vals = {1,3,5,7,9,11};
    //LL* l = new LL();
    
    vector<int> vals = {1,3,5,7,9,11,23,34,12,34,56,89};
    LL* l = new LL();

    for(auto v:vals) {
        l->insert(v);
    }
    l->print();

    l->reverse_LL(12, 12);
    l->print();
     return 0;
}

