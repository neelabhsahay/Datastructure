/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element and valley element,
and return its index. If the array contains multiple peaks/valley,
return the index to any of the peaks/valley.

When finding peak:
You may imagine that nums[-1] = nums[n] = -∞.
In other words, an element is always considered to be strictly greater
than a neighbor that is outside the array.

When finding valley:
You may imagine that nums[-1] = nums[n] = ∞.
In other words, an element is always considered to be strictly smaller
than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

int
findPeakElement(vector<int>& nums) {
    int r = nums.size() -1; // right end
    int l = 0;
    int m; // contain middle
    
    while(l<=r) {
        m = l +(r-l)/2;

        //find if m is peak
        if(((m == 0) || (nums[m-1] < nums[m])) &&
           ((m == nums.size()-1) || (nums[m+1]) < nums[m])) {
            return m;
        }
        // we will move towards higher side as chance of peak will 
        // always be higher side, we check m & m+1 to see if they are higher
        if(nums[m] < nums[m+1]) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return -1;
}

int
findValleyElement(vector<int>& nums) {
    int r = nums.size() -1; // right end
    int l = 0;
    int m; // contain middle
    
    while(l<=r) {
        m = l +(r-l)/2;

        //find if m is peak
        if(((m == 0) || (nums[m-1] > nums[m])) &&
           ((m == nums.size()-1) || (nums[m+1]) > nums[m])) {
            return m;
        }
        // we will move towards lower side as chance of valley will 
        // always be lower side, we check m & m+1 to see if they are higher
        if(nums[m] > nums[m+1]) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return -1;
}

int
main()
{
    //vector<int> nums = {1,2,3,1};
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << "Peak for " << nums << " is at index " << findPeakElement(nums) <<"\n";
    cout << "Valley for " << nums << " is at index " << findValleyElement(nums) <<"\n";
    return 0;
}
