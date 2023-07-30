#include<iostream>
#include<vector>

using namespace std;

class Solution {
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int partition(vector<int>& nums, int lo, int hi) {
        int pivotVal = nums[hi];
        int wall = lo;
        for (int i = lo; i < hi; i++) {
            if (nums[i] < pivotVal) {
                swap(nums, wall, i);
                wall++;
            }
        }
        swap(nums, wall, hi);
        return wall;
    }
 
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return nums[0];
        }
 
        int lo = 0;
        int hi = nums.size() - 1;
        int targetIndex = nums.size() - k;
 
        while (lo <= hi) {
            int pivot = partition(nums, lo, hi);
            if (pivot < targetIndex) {
                 lo = pivot + 1;
            } else if (pivot > targetIndex) {
                 hi = pivot - 1;
            } else {
                 return nums[pivot];
            }
        }
        return -1;
    }
 
};
