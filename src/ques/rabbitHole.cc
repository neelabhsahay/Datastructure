#include<iostream>
#include<map>
using namespace std;
// Write any include statements here

int getMaxVisitableWebpages(int N, vector<int> &L) {
  // Write your code here
  map<int, int> cir_len;
  vector<int> maxVisit(N,-1);
  int maxVal = 0;
  int s = 0;
  int c_num = 1;
  for(int i = 0;i<N;i++) {
    if(maxVisit[i] != -1) {
      continue;
    }
    s = i;
    while(s < N && maxVisit[s] != c_num ) {
         cout << s << ":" << c_num << " ";
         maxVisit[s] = c_num;
         cir_len[c_num]++;
         maxVal = max(maxVal, cir_len[c_num]);
         s = L[s]-1;
    }
    c_num++;
  }
  
  return maxVal;
}

int
main() {
    //std::vector<int> L = {4, 1, 2, 1};
    //int N =4;
    //std::vector<int> L = {2, 4, 2, 2, 3};
    //int N =5;
    //std::vector<int> L = {2, 4, 2, 2, 3, 2 ,6 };
    //int N =7;
    std::vector<int> L = {4, 3, 5, 1, 2};
    int N =5;

    for(int i =0;i<N;i++) {
        cout << L[i] << " ";
    }
    cout <<"\n";
    int result = getMaxVisitableWebpages(N,L); 
    cout << "\nResult: " <<  result << "\n";

    return 0;
}

