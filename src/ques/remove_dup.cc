/*
 * Given an integer array nums sorted in non-decreasing order,
 * remove the duplicates in-place such that each unique element appears only once
 * The relative order of the elements should be kept the same.
 * Then return the number of unique elements in nums.
 * Consider the number of unique elements of nums to be k, to get accepted,
 * you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the 
 * unique elements in the order they were present in nums initially.
 * The remaining elements of nums are not important as well as the size of nums.
 * Return k.
*/

#include <iostream>
#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        int j = 1;
        int s = nums.size() - 1;
        while(j <= s && i < s) {
            if(nums[i] == nums[j]) {
                j++;
            } else {
                nums[++i] = nums[j++];
            }
        }
        return i;
    }
};


int
main() {
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int res = sol.removeDuplicates(nums);
    for(int i = 0; i <= res;i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}