/*
Given a non-empty string word and an abbreviation abbr,
 return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

Input : s = "internationalization", abbr = "i12iz4n"
Output : true

Input : s = "apple", abbr = "a2e"
Output : false
i
Input: word = "internationalization", abbr = "i12iz4n"
Output: true

*/

#include<iostream>

using namespace std;

bool
validWordAbbreviation(string &word, string &abbr)
{
    int wl = word.size();
    int al = abbr.size();

    int w =0;
    int a = 0;
    int d =0;
    int mul = 1;

    while(a<al && w <wl) {
        if(isdigit(abbr[a])) {
            d = (d*mul) + (abbr[a] -'0');
            mul = mul*10;
            a++;
        } else {
            mul = 1;
            w +=d;
            d = 0;
            if(word[w] != abbr[a]) {
                return false;
            }
            a++;
            w++;
       }
    }
    if(a == al && w == wl) {
        return true;
    }
    return false;
}

int
main()
{
    //string word = "internationalization";
    //string abbr = "i12iz4n";
    string word = "apple";
    string abbr = "a2e";
    bool result = validWordAbbreviation(word, abbr);
    cout << abbr << " is " << (result ? " " : "NOT") << " valid abbreviate of " << word <<"\n";
    return 0;
} 
