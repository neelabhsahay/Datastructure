#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include<string>

class ListNode {
    std::string key_;
    int val_;
    ListNode* next_;
    ListNode* prev_;
public:
   ListNode(std::string key) {
       key_ = key;
       next_ = nullptr;
       prev_ = nullptr;
   }
   ListNode(int val) {
       val_ = val;
       next_ = nullptr;
       prev_ = nullptr;
   }
   ListNode(std::string key, int val) {
       val_ = val;
       key_ = key;
       next_ = nullptr;
       prev_ = nullptr;
   }
   std::string key() {return key_;}
   int val() {return val_;}
   ListNode* next(){return next_;}
   ListNode* prev(){return prev_;}
   void next(ListNode* next) {next_ = next;}
   void prev(ListNode* prev) {prev_ = prev;}
};
#endif  //  __LINKED_LIST_HPP__  
