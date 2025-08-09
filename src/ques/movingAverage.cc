#include <iostream>
#include <vector>

#include "utils.hpp"

// given an num array and window size
// return the average of all teh windows 
std::vector<double>
movingAverage(std::vector<int> &nums, int k)
{
    std::vector<double> res;
    double sum =0;
    int s = 0;
    int n = nums.size();

    for(int i = 0;i<k;i++) {
        sum += (double)nums[i];
    }
    res.push_back(sum/(double)k);

    while(s < (n-k)) {
        sum -= (double)nums[s];
        sum += (double)nums[s+k];
        res.push_back(sum/(double)k);
        s++;
    }
    return res;
}


int
main()
{
     std::vector<int> data = {5,2,8,14,3};
     int k = 3;
     std::vector<double> res = movingAverage(data, k); 
     std::cout << res << "\n";
     return 0;
}
