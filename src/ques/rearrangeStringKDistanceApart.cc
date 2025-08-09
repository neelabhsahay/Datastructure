/*
The given problem involves taking a string s and an integer k.
The task is to rearrange the characters of the string in such
a way that the same characters in the new string are separated 
by at least k distances from each other. If it is not possible
to perform such a rearrangement that satisfies the condition,
the output should be an empty string "".

For example, If we have the string s = "aabbcc" and k = 3,
one possible rearrangement could be "abcabc",
as any same characters are at least k = 3 units apart.

Algo;
    1. count number of each char in a array[26] (as its only lower case)
    2. push the char in a max_heap with pair <count, char>. this will
       have on top that char that has max occurance
    3. pop the top of stack and use one from that and decrement
       the count, if it still greater than ZERO add in a queue.
    4. if the size of queue is greater than K pop all the char from queue and 
       push to max_heap.
    5. if queue is not of size k and max_heap is empty then we cannot make a string.
*/
#include<iostream>

using namespace std;
typedef pair<int,int> pi;

string
reorganizeString(string s, int k) {
    string result;
    vector<int> count(26,0);
    pi maxv;
    queue<pi> q;
    priority_queue<pi> max_heap;
    for(auto ss:s) {
        count[ss-'a']++;
    }
    for(int i =0;i<26;i++) {
        if(count[i] !=0) {
            max_heap.push(make_pair(count[i],i));
        }
    }
    
    while(!max_heap.empty()) {
        maxv = max_heap.top();
        max_heap.pop();
        result.push_back(maxv.second+'a');
        maxv.first--;
        if(maxv.first != 0) {
            q.push(maxv); // waiting for one round so that it doesn't come at adj
        }
        //cout << result << " Q.size:" << q.size() << "\n";
        if(q.size() == k) {
            while(!q.empty()) {
                max_heap.push(q.front());
                q.pop();
            }
        } else {
            if(max_heap.empty() && q.size() != 0) {
                return ""; // cannot be made
            }
        }
    }

    return result;
}

int
main()
{
    //string str = "aabbcc";
    //string str = "aaabc";
    string str = "aaadbbcc";
    int k = 2;

    string result = reorganizeString(str,k);
    cout << "Original: " << str << " K= " << k << " Changed: " << result <<"\n";
    return 0;
}
