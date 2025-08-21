/*
Given a string s which represents an expression,
 evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid.
All intermediate results will be in the range of [-231, 231 - 1].
*/
#include <iostream>
using namespace std;

int calculate(string &s, int pos, int &ret_answer) {
    int n = s.size();
    int ret_pos;
    int answer = 0; // store addition and substraction of numbers
    int prevNum = 0;
    int currNum = 0;
    char op = '+';

    for(int i =pos;i<n;i++) {
        if(isdigit(s[i])) {
            currNum = (10*currNum) + (s[i]-'0');
        }
        // call the same function to calculate
        // whats inside the bracket
        if(s[i] == '(') {
            ret_pos = calculate(s, i+1, currNum);
        }
        if((!isdigit(s[i]) && !isspace(s[i])) || i == n-1) {
            // op is what sign was previous
            // now we calculate the current
            // add that to answer
            // and set current to zero
            // if we find sign we will again set op to appropiate
            // sign
            if (op == '-' || op == '+') {
                answer += prevNum;
                prevNum = (op == '+' ? currNum : -1*currNum);
            } else if (op == '*') {
               prevNum *= currNum;
            } else if (op == '/') {
               prevNum /= currNum;
            }
            op = s[i];
            currNum = 0;
            // we have reached end of parenthese hence
            // we will calculate the inside and
            // return the value along with till where
            // we have reached in string
            if(s[i] == ')') {
                ret_answer = answer + prevNum;
                return i;
            }
            // we called for parentheses so we update i to move to
            // closing parentheses, for loop increment will move to next
            if(s[i] == '(') {
                i = ret_pos;
            }
        }
    }
    ret_answer = answer + prevNum;
    return n;
}

int
main()
{
    //string str ="3+2*2";
    string str = "(2+6* 3+5- (3*14/7+2)*5)+3";
    //string str ="2*(5+5*2)/3+(6/2+8)";
    int result;
    calculate(str, 0, result);
    cout << "\nValue of " << str << " is " << result << "\n";
    return 0;
}
