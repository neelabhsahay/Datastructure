#include<iostream>

using namespace std;

class Node {
    Node* next_;
    int val_;
public:
    Node(int val) {
        val_ = val;
        next_ = nullptr;
    };
    int val() {
        return val_;
    };
    void next(Node* next) {
        next_ = next;
    };
    Node* next() {
        return next_;
    };
};

class CircularLL {
    Node* head;
public:
    CircularLL() {
        head=nullptr;
    };
    bool insert(int val);
    void print();
};

void
CircularLL::print()
{
    Node* n=head;
    if(!head) {
        return;
    }
    cout << "[";
    
    do {
        cout << n->val() <<", ";
        n = n->next();
    } while(n !=head);
    cout <<"]\n";
    return;
}

bool
CircularLL::insert(int val) {
    Node* n = new Node(val);
    Node* prev;
    Node* ahead;
    bool incr = true;
    // case list is empty 
    if(head == nullptr) {
        head = n;
        n->next(n);
    } else if (head->next() == head) {
        // case only one element
        head->next(n);
        n->next(head);
    } else {
        ahead = head->next();
        prev = head; 
        if(ahead->val() < prev->val()) {
            incr = false;
        }
        // find circular
        while(ahead != nullptr && ahead != head) {
            //cout << "Trying " << val<< " between " << prev->val() << " & " <<  ahead->val() <<"\n";
            if(incr) {
               if((prev->val() <= val) && (ahead->val() >= val)) {
                   //found th eplace insert
                   //cout << "Inseert between " << prev->val() << " & " <<  ahead->val() <<"\n";
                   prev->next(n);
                   n->next(ahead);
                   return true;
               } 
            } else {
               if(((prev->val() >= val) && (ahead->val() >= val)) ||
                  ((prev->val() <= val) && (ahead->val() <= val))) {
                   //found th eplace insert
                   //cout << "Insert between " << prev->val() << " & " <<  ahead->val() <<"\n";
                   prev->next(n);
                   n->next(ahead);
                   return true;
               } 
            }
            prev = ahead;
            ahead = ahead->next();
            if(ahead->val() < prev->val()) {
                incr = false;
            }
        }
        prev->next(n);
        n->next(ahead);
    }

    return true;
}


int main()
{
    vector<int> vals = {4, 6, 2, 5, 3, 9, 7,3 };

    CircularLL *list = new CircularLL();

    for(auto v:vals) {
        list->insert(v);
        cout << v << "=> ";
        list->print();
    }
    delete(list);
    return 0;
}
