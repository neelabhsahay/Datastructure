/*/
Given an array of numbers arr[] we need to arrange the number in such a way that 
it become next larger number if we placed the number as digit
in number, e.g.
[1,2,3] then this is treated as 123,
next large number using these digit is 132 hence
nect permutation is [1,3,2]
The replacement must be in place and use only constant extra memory 

Algo:
    First find the peak from left side, the element that break the mountain/peak
    i.e. nums[i-1] < nums[i] then i-1 th element we need to swap
    now find the element which is greater than number i-1 and swap
    it with that number, later reverse from i to end
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

void
nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 1, j;
    // find the first peak from left side
    while((i>0) && (nums[i-1] >= nums[i])) {
        i--;
    }

    // if i <= 0 then the array is in decending order
    // we will just reverse it
    if( i <= 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // now i denote the first element which is smaller than
    // its next element, this number is needed to be swapped
    // we need to find which number to replace, we find number
    // which is greater than this number to replace
    j = n-1;
    while((j >=i) && (nums[j] <= nums[i-1])) {
        j--;
    }
    swap(nums[j], nums[i-1]);

    cout << "Before end swap: " << nums <<"\n";
    // reverse from i-1 to end
    reverse(nums.begin()+i, nums.end());
    return;
}

int
main()
{
    vector<int> nums = {4,3,7,1,5,1};
    //vector<int> nums = {1,2,3};
    //vector<int> nums = {1,1,5};
    //vector<int> nums = {3,2,1};
    //vector<int> nums = {4,2,0,2,3,2,0};
    cout << "Original :" << nums;
    nextPermutation(nums);
    cout << " Next permutation: " << nums << "\n";
    return 0;
}
