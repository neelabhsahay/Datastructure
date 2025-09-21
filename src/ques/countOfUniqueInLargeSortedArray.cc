/*
Given a sorted array arr[] of size N, the task is to find the number of unique elements in this array.

Note: The array is very large, and unique numbers are significantly less. i.e., (unique elements <<size of the array).
*/
#include<iostream>

#include"utils.hpp"

using namespace std;

#if 0
// Binary search to find the last occurrence if larger = TRUE
// Binary search to find the first occurrence if larger = FALSE 
int
binarySearchPos(vector<int> &nums, int l, int r, int val, bool larger)
{
    int at = -1;
    int m;
    while(l<=r) {
        m = (r+l)/2;
        if(nums[m] == val) {
            // found one occurance now try to find
            // next item in direction as the varable larger
            at = m;
            if(larger) {
                l = m+1;
            } else {
                r = m-1;
            }
        } else if(val >nums[m]) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return at;
}
#endif

vector<int>
countUnique(vector<int> &nums)
{
    vector<int> result;
    if(nums.size() == 0) {
        return {};
    }
    int pos = 0;
    int val;
    int st = 0;
    while(pos < nums.size()) {
         val = nums[pos];
         // st is the position of val in largest position
         st = binarySearchPos(nums, pos, nums.size()-1, val, true);
         // next item is the next number
         pos = st+1;
         // push the number found earlier to result
         result.push_back(val);
    }
    return result;
}

int
main()
{
    //vector<int> nums = {1,1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 5, 5, 7, 7, 8, 8, 9, 9, 10, 11, 12};
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5, 9, 9, 9, 10, 10, 10};
    vector<int> result = countUnique(nums);

    cout << "Nums: " << nums << " Unique: " << result <<"\n";
    return 0;
}
