#include<iostream>
#include<string>
using namespace std;

class Solution {
int removeSpaces(string& str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' && str[i] != ',' && str[i] != ':' )
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
    return count;
}
public:
    bool isPalindrome(string s) {
        int count = removeSpaces(s);
        s = s.substr(0, count);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
        if(s.empty())
            return true;
        int i = 0, j = s.size()-1;
        
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
Solution S;
string s = "A man, a plan, a canal: Panama";
cout << " Answer: " <<  S.isPalindrome(s) << endl;
return 0;
} 
