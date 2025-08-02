#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int
maxPathLen(vector<int> &nums)
{
   int n = nums.size();
   int s = 0;
   int count;
   pair<int,int> p;
   int maxCount = 0;
   vector<int> indegree(n,0);
   vector<bool> visited(n, false);
   priority_queue<pair<int,int>, vector<pair<int,int>>,
                  greater<pair<int,int>>> min_heap;

   for(int i =0;i<n;i++) {
       indegree[nums[i]-1]++;
   } 
   
   for(int i =0;i<n;i++) {
       min_heap.push(make_pair(indegree[i], i));
   }

   while(!min_heap.empty()) {
       p = min_heap.top();
       min_heap.pop();
       s = p.second;
       cout << s <<":" << nums[s] << " "; 
       count =0;
       while(!visited[s]) {
           count++;
           visited[s] = true;
           s = nums[s]-1;
       }
       maxCount = max(maxCount, count);
   }
   return maxCount;
}

int
main()
{
    //vector<int>  nums = {2,3,4,5,2,4};
    //vector<int> nums = {2,3,4,5,1,4};
    //vector<int> nums = {2,4,5,1,6,3};
    //vector<int> nums = {4, 1, 2, 1};    // Ans = 4
    vector<int> nums = {2, 4, 2, 2, 3}; // Ans = 4
    //vector<int> nums = {4, 3, 5, 1, 2}; // Ans = 3

    cout << "Max Path Len: " << maxPathLen(nums) << "\n";
    return 0;
}
