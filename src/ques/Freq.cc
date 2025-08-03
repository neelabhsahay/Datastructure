#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> v) {
   for( auto n : v) {
      cout << n << " ";
   }
   cout << endl;
   return;
}

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = 0;
        int max = 0;
        while(e < nums.size() && s <=e) {
           if(((nums[e] - nums[e-1])*(e-s)) <=k) {
               k -= ((nums[e]-nums[e-1])*(e-s));
               e++;
           } else {
              max = (max < (e-s)) ? (e-s) : max;
              k += (nums[e-1] - nums[s]);
              s++;
           }
        }
        max = (max < (e-s)) ? (e-s) : max;
        return max;
    }
};



int main(){
Solution S;

vector<int> nums{9922,9980,9990,9922,9932,9989,9929,9938,9941,9966,9985,9906,9964,9903,9995,9963,10000,9950,9939,9985,9944,9960,9989,9977,9901,9923,9997,9971,9909,9985,9979,9906,9955,9988,9996,9995,9901,9996,9924,9967,9991,9981,9914,9933,9946,9928,9975,9990,9968,9985,9963,9927,9946,9919,9931,9955,9979,9943,9905,9918,9962,9970,9939,9901,9940,9933,9917,9988,9935,9941,9947,9971,9901,9926,9908,9969,9978,9984,9952,9945,9958,9958,9930,9923,9950,9993,9938,9976,9942,9946,9990,9951,9971,9980,9966,9944,9976,9954,9970,9984,9939,9961,9996,9993,9935,9949,9975,9952,9998,9956,9957,9949,9902,9946,9979,9904,9925,9948,9952,9961,9948,9982,9922,9958,9956};
int k = 1911;

//vector<int> nums{1,2,4};
//int k = 5;
int ans  = S.maxFrequency(nums, k);
cout << "Answer: " << ans << endl;
return 0;
}
