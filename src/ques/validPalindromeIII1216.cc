/*
The task is to determine if a given string s can be transformed
into a palindrome by removing at most k characters. 
A palindrome is a sequence that reads the same backward as forward,
such as "radar" or "level." A k-palindrome is an extended version
of this concept, where some flexibility is allowed by permitting
the removal of up to k characters to achieve a palindrome. 
To solve this problem, we need to establish a method for deciding
 whether or not the string, after the allowed modifications,
can be considered a palindrome.
*/

#include<iostream>

using namespace std;

bool
validPalindromeIII(string &str, int k, int st, int ed)
{
    if(st >ed) {
        return true;
    }
    while(st<ed && str[ed] == str[st]) {
        ed--;
        st++;
    }

    if(st==ed) {
       return true;
    }
 
    if(k<=0) {
        return false;
    }

    bool left = validPalindromeIII(str, k-1, st+1,ed);
    bool right = validPalindromeIII(str, k-1, st,ed-1);
    
    if(left || right) {
        return true;
    }

    return left&right;
}

int
main()
{
    string str = "abcdeca";
    int k = 0;
    bool result = validPalindromeIII(str,k, 0, str.size()-1);

    cout << "The string " << str <<" is "<< ((result == true)? " ":"NOT") << " a Palindrome\n";
    return 0;
}  
