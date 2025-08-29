/* Create Least recent used cache alogrithm
* Algo:
*     We maintain a hash table that store key to Doubly linkedList Node
*     When we get access a key we move the Node for the key to head
*     When the cache is full be delete tail to make space.
*/
#include<iostream>
#include<map>

#include "LinkedList.hpp"
#include "utils.hpp"

using namespace std;

class LRU {
    map<string, ListNode*> key_val;
    int capacity_;
    ListNode* head_;
    ListNode* tail_;

public:
    LRU(int capacity);
    int capacity() {return capacity_;}
    ListNode* head() {return head_;}
    ListNode* tail() {return tail_;}
    void head(ListNode* head) {head_ = head;}
    void tail(ListNode* tail) {tail_=tail;}

    void print();
    int get(string &key, int& val); // this return the value store in key_val cache
    void put(string &key, int val); // this place the key valye in key_val cache
};

LRU::LRU(int capacity)
{
    capacity_ = capacity;
    head_ = nullptr;
    tail_ = nullptr;
}

void
LRU::put(string &key, int val)
{
    ListNode* node = new ListNode(key, val);
    // we have space in cache
    if(key_val.size() >= capacity_) {
        // there is no space in cache
        // we will remove the tail node
        key_val.erase(tail_->key());
        ListNode* temp = tail_->prev();
        temp->next(nullptr);
        free(tail_);
        tail_=temp;
    }
    if(head_ != nullptr) {
        head_->prev(node);
        node->next(head_);
    }
    head_ = node;
    key_val[key] = node;
    if(tail_ == nullptr) {
        tail_ = node;
    }
}

// return 0 : success
//        -1: not found
//        -2: other error  
int
LRU::get(string &key, int &val)
{
    ListNode* node;
    // find whether the key is present
    if(key_val.find(key) == key_val.end()) {
        return -1;
    }
        
    node = key_val[key];
    node->prev()->next(node->next());
    if(node->next() != nullptr) {
        node->next()->prev(node->prev());
    }
    head_->prev(node);
    node->next(head_);
    head_ = node;
    val = node->val();
    return 0;
}

void
LRU::print()
{
    ListNode *node = head_;
    cout <<"[";
    while(node != nullptr) {
        cout << node->key() << ":" << node->val() <<", ";
        node = node->next();
    }
    cout << "]\n";
    return;
}


#ifndef IS_LIB

int
main()
{
    int lru_cap = 6;
    int test_idx1 = 3;
    int test_idx2 = 5;
    int test_val1;
    int test_val2;
    int ret;
    string newKey = "mikki";
    int newVal = 11;
    LRU lru = LRU(lru_cap);

    vector<string> keys = {"neel", "aash", "apar", "tanu","rimmi", "renu"};
    vector<int> vals = {4,5,6,7,8,9};

    cout << keys << vals;
    for(int i = 0;i<keys.size();i++) {
        lru.put(keys[i], vals[i]);
    }
    lru.print();

    // now lru is filled try some actions

    ret = lru.get(keys[test_idx1], test_val1);
    if(ret != 0) {
        cout << "Error finding key: " << keys[test_idx1] <<"\n";
    } else {
        cout << "Key: " << keys[test_idx1] << " val: " << test_val1 <<"\n";
    }
    
    lru.print();
    
    ret = lru.get(keys[test_idx2], test_val2);
    if(ret != 0) {
        cout << "Error finding key: " << keys[test_idx2] <<"\n";
    } else {
        cout << "Key: " << keys[test_idx2] << " val: " << test_val2 <<"\n";
    }
    
    lru.print();

    lru.put(newKey,newVal);
    
    lru.print();
    return 0;
}
#endif
