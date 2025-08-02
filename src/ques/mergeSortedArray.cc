/* Given two sorted arrays, one is enough to store
 * all the elements of both the arrays, i.e if first 
 * array has n element and second array hold m elements
 * then first array is of length n+m; 
 */

#include<iostream>

using namespace std;

void
mergeSortedArray(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(); // m will always be greater as as it need to store
                          // second array also
    int n = nums2.size();
    int f =m-1 - n;
    int s = n-1;
    int pos = m-1;

    while(f>=0 && s>=0) {
        if(nums1[f] > nums2[s]) {
            nums1[pos] = nums1[f];
            f--;
        } else {
            nums1[pos] = nums2[s];
            s--;
       }
       pos--;
   }
}

void
printArray(vector<int> &nums)
{
    cout << "[";
    for(auto n:nums) {
        cout <<n <<",";
    }
    cout <<"]\n";
}

int
main()
{
    vector<int> nums1 = {1,3,5,7,9,0,0,0,0,0};
    vector<int> nums2 = {2,4,6,11,13};

    printArray(nums1);
    printArray(nums2);
    
    mergeSortedArray(nums1, nums2);
    printArray(nums1);
    printArray(nums2);
    return 0;
}
