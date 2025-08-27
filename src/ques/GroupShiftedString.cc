/* Given an array of strings (all lowercase letters), the task is to
* group them in such a way that all strings in a group are shifted
* versions of each other.
*
* Two strings s1 and s2 are called shifted if the following conditions
* are satisfied:
*
* s1.length is equal to s2.length
* s1[i] is equal to s2[i] + m for all 1 <= i <= s1.length for a constant
* integer m. Consider the shifting to be cyclic, that is if s2[i] + m > 'z',
* then start from 'a' or if s2[i] + m < 'a', then start from 'z'.
*
* e.g.
* Input: arr[] = ["acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"]
* Output: [ ["acd", "dfg", "wyz", "yab", "mop"], ["bdfh", "moqs"], ["a", "x"] ]
* Explanation: All shifted strings are grouped together.
* 
* Algo:
* Store each string making first char as 'a' 
* like : "dfg" => "acd"
*         'd' - 'a' = 3
*         'f' - 3 => 'c'
*         'g' - 3 => d 
*
*  we will get same string which will fall in same group   
* same them in a hash table which store vector of index for given key
*/

#include <iostream>

#include "utils.hpp"

using namespace std;

vector<vector<string>>
groupShiftedString (vector<string> &strs)
{
    vector<vector<string>> result;
    unordered_map<string, vector<int>> str_2_idx;
    int n = strs.size();
    for(int i =0;i<n;i++) {
        // find the derived hash
        string s = strs[i];
        string temp;
        int diff = s[0] -'a';
        // if first element it self is a then we push the same
        if(diff == 0 || s.size() == 1) {
             str_2_idx[s].push_back(i);
             continue;
        }
        temp.push_back('a');
        //cout << s <<":a";
        for(int j = 1;j<s.size();j++) {
            if((s[j] - 'a' - diff) < 0) {
                //cout << (char)(26 + s[j] - diff);
                temp.push_back(26 + s[j] - diff);
            } else {
                //cout << (char)(s[j] - diff);
                temp.push_back(s[j] - diff);
            }
        }
        //cout <<"\n";
        str_2_idx[temp].push_back(i);
    }
    
    for(auto &s : str_2_idx) {
        vector<string> temp_vec;
        for(auto i:s.second) {
            //cout << s.first << ":" << strs[i] <<"=>" ;
            temp_vec.push_back(strs[i]);
        }
        result.push_back(temp_vec);
    }
    return result;
}

int
main()
{
    //vector<string> strs = {"acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"};

    vector<string> strs = {"geek", "for", "geeks"};
    vector<vector<string>> result = groupShiftedString(strs);
    cout << strs << " groups as " << result << "\n";
    return 0;
}
