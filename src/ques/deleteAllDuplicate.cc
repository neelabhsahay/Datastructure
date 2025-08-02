/*
 * You are given a string which contain only lower case
 * english letter.
 * Return the final string after ALL continues duplicates has
 * been removed. 
 * "abbbbacxdd" => cx
 * "abbbbacxadd" => cxa
*/

#include <iostream>

using namespace std;

typedef pair<char,int> pci;
#define MP(a,b) make_pair(a,b)
string
removeAllDuplicate(string &str)
{
    stack<pci> stk;
    string result;
    pci e;

    int i =0;
    while(i < str.size()) {
        if(stk.empty()) {
             stk.push(MP(str[i],1));
             i++;
        } else {
            if(str[i] == stk.top().first) {
                e = stk.top();
                stk.pop();
                e.second++;
                stk.push(e);
                i++;
            } else {
                if(stk.top().second > 1) {
                    stk.pop();
                } else {
                    stk.push(MP(str[i],1));
                    i++;
                }
            }
        }
    }
    while(!stk.empty()) {
         if(stk.top().second <=1) {
             result.push_back(stk.top().first);
         }
         stk.pop();
    }
    reverse(result.begin(), result.end());
    return result; 
}


int
main()
{
     //string str = "abbbbacxadd";
     string str = "abbbbacxxcadd";

     string result = removeAllDuplicate(str);
     cout << "Original: " << str << " And Final: " << result << "\n";
     return 0;
}
