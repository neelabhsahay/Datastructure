/*
Encode the string -
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Decond the string, return shortest decoded string.
Input: s = "aaabcbc"
Output: "3[a]2[bc]"
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

string
encodeStr(string &str)
{
    string result;
    int n = str.size();
    int s = 0;
    int e = 0;
    int count = 0;

    while(s<n) {
        if(isdigit(str[s])) {
            count = (10*count) + str[s] - '0';
            s++; 
        } else {
            // we will be here then the element will be '['
            // there is gaurentee that we will find ']' hence we
            // can move s
            if (str[s] == '[') {
                s++;
                e = s;
                while(e <n && str[e] != ']') {
                    result.push_back(str[e]);
                    e++;
                }
                // since we will always have ']' e will point to ']'
                // so we decrement e by 1
                e--;
                // we decrease count by 1 as we have pushed one element
                count--;
                // now we will push count time sub string between s and e;
                while(count >0) {
                    for(int i = s;i<=e;i++) {
                        result.push_back(str[i]);
                    }
                    count--;
                }
                // e is pointing before ']' and we want to start after that
                // hence we will increment by 2
                s = e+2;
            } else {
                result.push_back(str[s]);
                s++;
            }
        }
    }
    return result;
}

string
decodeStr(string &str)
{
    string result;

    return result;
}

#ifndef IS_LIB
int
main()
{
    string str = "3[a]zxy2[bc]edf";
    cout << "Coded string " << str << " after encoding " << encodeStr(str) <<"\n";
    return 0;
}
#endif
