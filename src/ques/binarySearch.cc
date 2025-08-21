// Sample code for binary search in array
// use function to check whether condition
// fullfilled

#include<iostream>

#include "utils.hpp"

using namespace std;

int
binarysearch(vector<int> &nums, int st, int end, int k)
{
    int l = st;
    int r = end;
    int m;

    while(l<=r) {
        m = (r+l)/2;

        if(nums[m] == k) {
            return m;
        }

        if(nums[m] < k) {
            l = m+1;
        } else {
            r = m -1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,12,13,14,24,25,27,28,29,34,46,57,62,75,89};

    int k = 34;
    cout << nums <<"\n";
    cout << "Index for " << k <<" is " << binarysearch(nums,0,nums.size()-1, k) << "\n";
    return 0;
}
