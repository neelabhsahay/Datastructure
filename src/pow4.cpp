#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        int c = 0;
        while(n) {
            if( n&1) {
                break;
            }
            n = n >> 1;
            c++;
        }
        cout << " Value of C: " << c << endl; 
        if(c%2 == 0 && c !=0 && n == 1 )
            return true;
        else
            return false; 
    }
};


int
main() {

Solution s;
int n = 12;
bool res = s.isPowerOfFour(n);
cout << "Is " << n << " powder of 4:" << res << endl;
return 0;
} 
