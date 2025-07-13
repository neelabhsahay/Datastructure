#include<iostream>

using namespace std;

vector<int> oceanView(vector<int> &nums)
{
    vector<int> result;
    int prev = 0;
    int n = nums.size();

    for(int i = n-1;i>=0;i--) {
        if(prev < nums[i]) {
            result.push_back(i);
            prev = nums[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
}


int
main()
{
    vector<int> nums = {4,3,2,1}; //{4,2,3,1};

    vector<int> result = oceanView(nums);

    cout <<"[";
    for(auto r: result) {
        cout <<r << ",";
    }
    cout <<"]\n";
    return 0;
}
