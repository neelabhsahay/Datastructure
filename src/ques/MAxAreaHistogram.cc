#include<iostream>
#include<vector>
#include<stack>

using namespace std;
void printVector(vector<int>& h) {
   cout << "[";
   for(auto n : h) {
       cout << n << ", ";
   }
   cout << "]" << endl;
}
 
class Solution {
public:
    int maxAreaHosto(vector<int>& h) {
        stack<int> s;
        int ma = 0;
        int m, b, i;
        for(i = 0; i < h.size();i++) {
            if(s.empty() || h[s.top()]<h[i]) {
                s.push(i);
            } else {
                while(!s.empty() && h[s.top()]>= h[i]) {
                    m = s.top();
                    s.pop();
                    if(s.empty()) {
                        b=-1;
                    } else {
                        b = s.top();
                    }
                    ma = max(ma, ((i-(b+1))*h[m]));
                }
                s.push(i);
            }
        }
        if(s.empty()) {
            return ma;
        }
        i = s.top();
        while(!s.empty()) {
            m = s.top();
            s.pop();
            if(s.empty()) {
                b = -1;
            } else {
                b = s.top();
            }
            ma = max(ma, (i-b)*h[m]);
        }
        return ma;
    }
};

int
main() {
    vector<int> h{3,1,3,2,2};
    //vector<int> h{2,0,2,1,1};
    Solution s;
    int ma = s.maxAreaHosto(h);
    printVector(h);
    cout << "Max Area of Histogram: " << ma << endl;
    return 0;
}
