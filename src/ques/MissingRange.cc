/*
 * Given a sorted integer array nums, where the range of elements
 * are in the inclusive range [lower, upper], return its missing ranges.

   Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
        [[2,2], [4,49], [51,74],[76,99]]
*/

#include <iostream>

using namespace std;

vector<vector<int>>
missingRange(vector<int> &nums, int lower, int upper)
{
    vector<vector<int>> result;
    int prev = lower;
    for(auto n:nums) {
        if((n-prev)>0) {
            result.push_back({prev, n-1});
        }
        prev = n+1;
    }
    if((upper - prev) > 0) {
        result.push_back({prev, upper});
    }
    return result;
}

int
main()
{
    vector<int> nums = {0, 1, 3, 50, 75, 99};
    int lower = 0;
    int upper = 99;
    vector<vector<int>> result = missingRange(nums, lower, upper);

    cout <<"[";
    for(auto range:result) {
        cout <<"[";
        for(auto r:range) {
             cout << r <<",";
        }
        cout <<"], ";
    }
    cout <<"]\n";
    return 0;
}
