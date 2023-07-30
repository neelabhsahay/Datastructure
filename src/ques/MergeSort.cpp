#include<iostream>
#include<vector>

using namespace std;

void
printVector(vector<int>& nums) {
    cout << "[ ";
    for(auto n : nums) {
       cout << n << ", ";
    }
    cout << " ] " << endl;
    return;
}

class MergeSort{
    private:
    /* sl => Start index of left list
     * el => End index of left list
     * sr => Start index of right list
     * er => End index of right list
     * sl <= el < sr <= er
     * 0 <= sl, er < nums.size()
     * The both lists left and right should not overlap.
     */
    void Merge(vector<int>& nums, int sl, int el, int sr, int er) {
        int k;
        while(sr <= er && sl < sr) {
            if(nums[sl] > nums[sr]) {
                int t = nums[sr];
                k = sr;
                sr++;
                while(k > sl) {
                    nums[k] = nums[k-1];
                    k--;
                }
                nums[k] = t;
            }
            sl++;
        }
    }
    /* Divided the list into two list 
     * and then merge those two list.
     * we continue dividing the list in smaller list
     * untill size of list become two, then we sort this smallest
     * list and later merge them.
     */ 
    void MergeSortVec( vector<int>& nums, int s, int e) {
        // the list is of size two hence now sort this.
        if( s == e) {
             return;
        } else if( s+1 == e) {
           if( nums[s] > nums[e]) {
               int t = nums[e];
               nums[e]  = nums[s];
               nums[s] = t;
           }
           return;
        }

        // divide the two list in two sub list 
        // and merge them.
        int el = (e-s)/2 + s;
        int sr = el +1;
     
        MergeSortVec(nums, s, el);
        MergeSortVec(nums, sr, e);
        //cout << " SL: " << s << " EL: " << el << " SR: " << sr << " ER: " << e << endl;
        Merge(nums, s, el, sr, e);
    }
    public:
    void Sort(vector<int>& nums) {
        MergeSortVec(nums, 0, nums.size()-1);
    
    }
};

int 
main() {
    vector<int> nums{3, 7, 9, 2,5, 11, 24, 8, 13, 6, 32};
    MergeSort ms;
    printVector(nums);
    ms.Sort(nums);
    printVector(nums);
    return 0;
}  
