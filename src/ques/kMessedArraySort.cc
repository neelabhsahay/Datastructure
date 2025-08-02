/* Given an array of integers arr where each element is
 * at most k places away from its sorted position,
 * code an efficient function sortKMessedArray that sorts arr.
 * For instance, for an input array of size 10 and k = 2,
 * an element belonging to index 6 in the sorted array will be located...
 */

#include <iostream>
#include <vector>

using namespace std;

/*
   this approch is O(n.k) time complexity
 */
vector<int> 
sortKMessedArray( vector<int>& arr, int k ) 
{
  // your code goes here
  int n = arr.size();
  int t;
  int check_index;
  vector<int> result(n,0);
  for(int i =0; i<n;i++) {
      check_index = (i+k)>=n? n-1:i+k;
      while(check_index >i){
          if(arr[i] >arr[check_index]) {
              t = arr[i];
              arr[i] = arr[check_index];
              arr[check_index] = t;
          }
          check_index--;
      }
      result[i] = arr[i];
   }
   return result;
}

// comment out main() before running tests
int main() {
    // debug your code below
    vector<int> arr = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> result = sortKMessedArray(arr, k);

    cout << "Sorted KMessed Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
