/* Given an array of integers nums and an integer k, 
* return the total number of subarrays whose sum equals to k.
*
* A subarray is a contiguous non-empty sequence of elements within an array.
* 
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

int subarraySum(vector<int>& nums, int size, int k) {
    int n = size;;
    unordered_map<int,int> prefix; // for every sum we keep count
                                   // of how many subarray has form this sum
    int count = 0;
    int sum = 0;
    prefix[0] =1;

    for(int i =0;i<n;i++) {
        sum += nums[i];
        // we calculate the sum till ith element
        // we try to find out is there any sub array that has
        // sum equal to sum-k so that if we remove that
        // subarray from zero to ith element sub array we get sum of
        // k
        if(prefix.find(sum-k) != prefix.end()) {
            count += prefix[sum-k];
        }
        prefix[sum]++;
    }

    return count;
}

#ifndef IS_LIB

int
main()
{
    //vector<int> nums = {1,1,1 };
    vector<int> nums = {1,2,3 };
    int k = 3;

    int count = subarraySum(nums, nums.size(), k);

    cout << "For array " << nums << " sub arrays whose sum is " << k << 
            " is " << count << "\n";
    return 0;
}
#else
void
subArraySumPy(vector<int> &nums, int size, int k)
{
    int count = subarraySum(nums, size, k);
    cout << "For array " << nums << " sub arrays whose sum is " << k << 
            " is " << count << "\n";
}
// here its an c extern function to call from python
// C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    void testCode(int* nums, int size, int k {
        subarraySumPy(nums, size, k);
        return;
    }
}
#endif
