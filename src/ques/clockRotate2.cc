

#include<iostream>

using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int>& C) {
  // Write your code here
  long long count = 0;
  long long pos1 = 1;
  long long pos2 = 1;
  long long val1, val2; 
  for(int i =0;i<M;i++) {
      val1 = abs(C[i] - pos1);
      val2 = abs(C[i] - pos2);
      val1 = (val1 <= (N-val1) ? val1:(N-val1));
      val2 = (val2 <= (N-val2) ? val2:(N-val2));
    
      if(val1 <= val2) {
           pos1 = C[i];
           count += val1;
           cout << "Select Clock 1 after " << val1 << " at: " << pos1 << "\n";
      } else {
           pos2 = C[i];
           count += val2;
           cout << "Select Clock 2 after "<< val2 << " at: " << pos2 << "\n";
      }
  }
  return count;
}


int
main()
{
    int N = 10;
    int M = 4;
    vector<int> C = {9, 4, 4, 8};

    long long result = getMinCodeEntryTime(N, M, C);

    cout << "Result: " << result <<"\n";
    return 0;
} 
