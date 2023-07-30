#include<iostream>
#include<vector>

using namespace std;

class Solution{
   public:
      // return index of found number if not found return -1;
      int binarySearch( vector<int> &nums, int f) {
          int e = nums.size()-1;
          int s = 0;
          int m = nums.size()/2;
          while(s <= e) {
              cout << "St: " << s << " En: " << e << " nums[" << m <<" ] : " << nums[m] << endl;
              if(nums[m] == f) 
                  return m;
              if(nums[m] < f) {
                  s = m +1;
                  m = s + (e-s)/2;
              } else {
                  e = m -1;
                  m = s + (e-s)/2;
              }
         }
         return m;
      }
};

int main() {
   //vector<int> nums{1,2,3,4,5,6,7,13,16,45,98};
   Solution s;
   vector<int> nums{0,1,1,1,2,3,6,7,8,9};
   int f = 4;
   int pos = s.binarySearch(nums, f);

   cout << "Number: " << f << " found at index: " << pos <<endl;
   return 0;
}
