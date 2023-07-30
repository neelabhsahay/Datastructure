#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int maxLength(vector<vector<int>>& dp, vector<int>& nums, int s, int e, int c0, int c1) {
        if(dp[s][e] != -1) {
            return dp[s][e];
        }
        dp[s][e] = 0;
        cout << "s: " << s << " e: " << e << " c0: " << c0 << " c1: " << c1 << endl;  
        while(s < e) {
            if(c1 == c0) {
                dp[s][e] = e-s+1;
                return e -s + 1;
            } else {
                if( c1 > c0) {
                    if( nums[s]) {
                        s++;
                        c1--;
                    } else if(nums[e]) {
                        e--;
                        c1--;
                    } else {
                        c0--;
                        break;
                    }                        
                } else {
                    if( nums[s] == 0) {
                        s++;
                        c0--;
                    } else if(nums[e] ==0) {
                        e--;
                        c0--;
                    } else {
                        c1--;
                        break;
                    }                        
                }
            }
        }
        if( s < e) {
            int r1 = maxLength(dp, nums, (s+1), e, c0, c1);
            int r2 = maxLength(dp, nums, s, (e-1), c0, c1);
            if( r1 < r2)
                return r2;
            else
                return r1;
        }

        return 0;
    }
public:
    int findMaxLength(vector<int>& nums) {
        int c0=0, c1=0;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1)); 
        for(auto n : nums) {
            if(n)
               c1++;
            else
               c0++;
        }
        return maxLength(dp, nums, 0, nums.size()-1, c0, c1);
    }
};


int
main() {

  vector<int> nums{0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1};
  //vector<int> nums{0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,1,0};
  Solution s;
  int siz = s.findMaxLength(nums); 
  cout << " Max Size: " << siz << endl;
  return 0;
}
