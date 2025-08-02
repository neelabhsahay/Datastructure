#include<iostream>

using namespace std;

class SparseVector {
    vector<vector<int>> vec_;
public:

    // Constructor for sparseVector.
    SparseVector(vector<int> &nums) {
        // Write your code here.
        for(int i =0;i<nums.size();i++) {
            if(nums[i]!=0) {
                vec_.push_back({i,nums[i]});
            }
        }
    }

    // Function to compute dot Product.
    int dotProduct(SparseVector& vec) {
        // Write your code here.
        int product =0;
        int f = 0;
        int s = 0;

        while(f < vec_.size() && s<vec.vec_.size())
        {
           if(vec_[f][0] == vec.vec_[s][0]) {
               product += (vec_[f][1]*vec.vec_[s][1]);
               f++;
               s++;
            } else if(vec_[f][0] < vec.vec_[s][0]) {
               f++;
            } else {
               s++;
            }
        }
        return product;
    }
};

int
main()
{
    //vector<int> nums1 = {2, 4, 0, 0, 1, 0};
    //vector<int> nums2= {0, 0, 3, 0, 5, 0};
    
    vector<int> nums1 = {0,0,1,2,0,3};
    vector<int> nums2 = {4,0,1,0,0,3};
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    int ans = v1.dotProduct(v2);

    cout << "Result: " << ans <<"\n";
    return 0;
}
