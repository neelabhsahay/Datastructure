/*
You're trying to open a lock. The lock comes with two wheels, each of which has the integers from 
1 to N arranged in a circle in order around it (with integers 
1 and N adjacent to one another). Each wheel is initially pointing at 1.
For example, the following depicts the lock for 
N=10 (as is presented in the second sample case).
It takes 1 second to rotate a wheel by 
1 unit to an adjacent integer in either direction,
 and it takes no time to select an integer once a wheel is pointing at it.
The lock will open if you enter a certain code. The code consists of a sequence of 
M integers, the ith of which is Ci. For each integer in the sequence,
you may select it with either of the two wheels.
Determine the minimum number of seconds required to select all 
M of the code's integers in order.
*/

#include<iostream>
#include<map>
using namespace std;

long long getMinCodeEntryTimeHelper(int N, int M, vector<int>& C,
                                    vector<vector<long long>> &cache,
                                    int pos1, int pos2, int code_idx)
{
    long long val1, val2;
    if(code_idx >=M) {
       return 0;
    }
    if(cache[pos1+pos2][code_idx] != -1) {
        return cache[pos1+pos2][code_idx];
    }
    val1 = abs(C[code_idx] - pos1);
    val2 = abs(C[code_idx] - pos2);
    val1 = (val1 <= (N-val1) ? val1:(N-val1));
    val2 = (val2 <= (N-val2) ? val2:(N-val2));

    long long first = getMinCodeEntryTimeHelper(N, M, C, cache, C[code_idx], pos2, code_idx+1);
    long long second = getMinCodeEntryTimeHelper(N, M, C, cache, pos1, C[code_idx], code_idx+1);

    if((first+val1) < (second+val2)) {
        cache[pos1+pos2][code_idx] = first+val1;
        return first+val1;
    } else {
        cache[pos1+pos2][code_idx] = second+val2;
        return second+val2;
    }
}

long long 
getMinCodeEntryTime(int N, int M, vector<int> &C) {
  vector<vector<long long>> cache(2*N+2,vector<long long>(M,-1));
  // Write your code here
  return getMinCodeEntryTimeHelper(N,M,C,cache, 1,1,0);
}


int
main()
{
   int N = 10;
   int M = 4;
   vector<int> C = {9, 4, 4, 8};
   
   //int N = 3;
   //int M = 3;
   //vector<int> C = {1, 2, 3};

   int count = getMinCodeEntryTime(N,M,C);
   cout << "Result: " << count <<"\n";
   return 0;
}
