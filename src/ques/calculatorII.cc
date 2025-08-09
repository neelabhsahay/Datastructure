/*
Given a string s which represents an expression,
 evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid.
All intermediate results will be in the range of [-231, 231 - 1].
*/
#include <iostream>
using namespace std;

int calculate(string s) {
    int ans = 0; // store addition and substraction of numbers
    int prevNum = 0;
    int currNum = 0;
    char op = '+';

    // we move from left to right
    // the first number incounter will ne previous number
    // then we will get a operator, if its addition
    // or substraction then we will save the previous number
    // as per sign in answer, for multiplication
    // and division we use the number and find the product/div
    // and store in previous number
    for (int i = 0; i < s.length(); ++i) {
        const char c = s[i];
        if (isdigit(c))
            currNum = currNum * 10 + (c - '0');
        if ((!isdigit(c) && !isspace(c)) || i == s.length() - 1) {
            if (op == '+' || op == '-') {
                ans += prevNum;
                prevNum = op == '+' ? currNum : -currNum;
            } else if (op == '*') {
                prevNum *= currNum;
            } else if (op == '/') {
                prevNum /= currNum;
            }
            op = c;
            currNum = 0;
        }
    }

    return ans + prevNum;
}

int
main()
{
    //string str ="3+2*2";
    string str ="-7*3+2*-2";

    int result = calculate(str);
    cout << "Value of " << str << " is " << result << "\n";
    return 0;
}
