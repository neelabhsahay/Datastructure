#include<iostream>

using namespace std;
// Write any include statements here

int getMaxVisitableWebpages(int N, vector<int> &L) {
  // Write your code here
  vector<int> maxVisit(N,-1);
  stack<int> stk;
  int maxVal = 0;
  int count;
  
  for(int i =0;i<N;i++) {
    int s =i;
    count = 0;
    vector<int> visited(N,0);
    while(s<N) {
      cout << s+1 <<"(" << maxVisit[s] << ")"<< "=>";
      if(maxVisit[s] != -1) {
          count += maxVisit[s];
          break;
      }
      if(visited[s]) {
        break;
      } else {
         if(maxVisit[s] != -1) {
             count += maxVisit[s];
             break;
        } 
        stk.push(s);
        count++;
        visited[s]=count;
        s = L[s]-1;
      }
    }
    cout <<"\n";
    maxVisit[i] = count;
    //if we break due to circle update lent for all 
    // node
    while(!stk.empty()) {
        if(stk.top() == s) {
            break;
        }
        maxVisit[stk.top()] = count - visited[s];
        stk.pop();
    }
    while(!stk.empty()) {
        //maxVisit[stk.top()] = count - visited[stk.top()];        
        stk.pop();
    }
    maxVal = max(maxVal, count);
  }
    for(int i =0;i<N;i++) {
        cout << maxVisit[i] << " ";
    }
  
  return maxVal;
}

int
main() {
    //std::vector<int> L = {4, 1, 2, 1};
    //int N =4;
    //std::vector<int> L = {2, 4, 2, 2, 3};
    //int N =5;
    std::vector<int> L = {2, 4, 2, 2, 3, 2 ,6 };
    int N =7;
    //std::vector<int> L = {4, 3, 5, 1, 2};
    //int N =5;

    for(int i =0;i<N;i++) {
        cout << L[i] << " ";
    }
    cout <<"\n";
    int result = getMaxVisitableWebpages(N,L); 
    cout << "\nResult: " <<  result << "\n";

    return 0;
}

