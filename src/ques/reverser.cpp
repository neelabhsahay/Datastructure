#include<iostream>

class Solution {
public:
    int reverse(int x) {
        long i = 0;
        int si = 1;
        long check = ((long)1<<31) -1;
        long check2 = -1* (((long)1<<31) -1);
        if( x < 0 ) {
           si = -1;
           x = x * -1;
        }
        while(x) {
            i = (i *10) + (x%10);
            x = x/10;
        }
        i = i * si;
        std::cout << "Int size: " << sizeof(int) <<  " Si :" << si << std::endl;
        std::cout <<"check : " << check << " check2 : " << check2  << " I : " << i << std::endl; 
        if( i > check || i < check2) {
            return false;
        }
        return i;
    }
};

int main() {

   Solution s;
   int ans = s.reverse(1463847412);

   std::cout << "Answer : " << ans <<std::endl;
   return 0;
}
