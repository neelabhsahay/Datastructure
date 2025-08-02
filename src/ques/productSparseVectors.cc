#include<iostream>

using namespace std;

int 
SparseVector(vector<vector<int>> &vec1, vector<vector<int>> &vec2)
{
   int product =0;
   int f = 0;
   int s = 0;
   
   while(f < vec1.size() && s<vec2.size())
   {
       if(vec1[f][0] == vec2[s][0]) {
           product += (vec1[f][1]*vec2[s][1]);
           f++;
           s++;
       } else if(vec1[f][0] < vec2[s][0]) {
          f++;
       } else {
          s++;
       }
   }
   return product;
}


int
main()
{
    vector<vector<int>> vec1 = { {0,1},
                                 {3,2}
                               };
    vector<vector<int>> vec2 = { {1,3},
                                 {3,4}
                               };

    cout << "Result: " << SparseVector(vec1, vec2) <<"\n";
    return 0;
}
