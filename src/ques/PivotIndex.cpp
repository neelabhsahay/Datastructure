#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t = 0;
        for(auto n : nums) {
            t += n;
        }
        int i = 0;
        int l = 0;
        while(i < nums.size()-1) {
            int r = t - (l + nums[i]);
            cout << "T: " << t << " L: " << l << " nums[" << i << "]: " << nums[i] <<  " R: " << r << endl;
            if(l == ( t -(l + nums[i]))) {
                return i;
            }
            l += nums[i];
            i++;
        }
        if(l==0)
            return i;
        return -1;
    }
};

int
main() {
vector<int> nums{-1,-1,0,1,1,0};
//cout << nums << endl;
Solution s;
int i = s.pivotIndex(nums);
cout << "Index : " << i << endl;
return 0;
}
