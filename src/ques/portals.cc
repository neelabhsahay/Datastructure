#include<iostream>
#include<map>

using namespace std;
// Write any include statements here

int getSecondsRequired(int R, int C, vector<vector<char>> &G) {
  // Write your code here
  map<char,vector<int>> edg;
  pair<int,int> start;
  vector<vector<bool>> visited(R,vector<bool>(C, false));
  pair<int,int> p;
  queue<pair<int,int>> q;
  int cost = INT_MAX;
  int path_cost= 0;

  cout << "R: " << R << " C: " << C << "\n";  
  for(int i = 0;i<R;i++) {
      for(int j = 0;j<C;j++) {
          if(G[i][j] == 'S') {
              //cout << "Start " << i <<"," <<j << "\n";
              start = make_pair(i,j);
          } else if(G[i][j] != 'S' && G[i][j] != 'E' 
             && G[i][j] != '.' && G[i][j] != '#') {
            //cout << "Aplha " << G[i][j]  <<"=" << i <<"," <<j << "\n";
            edg[G[i][j]].push_back((i*C)+j);
          }
      }
  }

  // use BDF to get the path
  q.push(start);
  q.push(make_pair(-1,-1)); // this is to increment path_cost;
  //cout << "Start [" << start.first <<","<< start.second <<"] \n ";
  
  while(!q.empty()) {
      p = q.front();
      q.pop();
    
      //cout << " [" << p.first <<","<<p.second<<"]" << " ";
    
      if(p.first == -1) {
          //cout <<"\n";
          if(!q.empty()) {
              q.push(make_pair(-1,-1)); 
              path_cost++;
          }
      } else {
           if(G[p.first][p.second] == 'E') {
               cost = min(cost, path_cost);
           } else {
               if(G[p.first][p.second] != '#') {
                   if(p.first >0 && !visited[p.first-1][ p.second] && G[p.first-1][p.second] != '#') {
                       q.push(make_pair(p.first-1,p.second));
                       visited[p.first-1][p.second] = true;
                   }
                   if(p.second >0 && !visited[p.first][p.second-1] && G[p.first][p.second-1] != '#') {
                       q.push(make_pair(p.first,p.second-1));
                       visited[p.first][ p.second-1] = true;
                   }
                   if(p.first <R-1 && !visited[p.first+1][p.second] && G[p.first+1][p.second] != '#') {
                       q.push(make_pair(p.first+1,p.second));
                       visited[p.first+1][ p.second] = true;
                   }
                   if(p.second <C-1  && !visited[p.first][p.second+1] && G[p.first][p.second+1] != '#') {
                       q.push(make_pair(p.first,p.second+1));
                       visited[p.first][p.second+1] = true;
                   }
               }
               if (G[p.first][p.second] != '#' && (G[p.first][p.second] != '.') &&
                   (G[p.first][p.second] != 'S') && (G[p.first][p.second] != 'E')) {
                   //
                   for(auto e: edg[G[p.first][p.second]]) {
                       // skip self
                       if(!visited[e/C][e%C]) {
                             //cout << "\nAp: "<< "["  << (e/C) <<","<< (e%C) << "] V:" << visited[e/C][e%C]<< "\n";
                             q.push(make_pair((e/C),(e%C)));
                             visited[e/C][e%C] = true;
                       }  
                   }  
               }
           }
      }
  }
  
  return cost == INT_MAX? -1 : cost;
}


int 
main()
{
#if 0
   int R = 3;
   int C = 3;
   vector<vector<char>> G = {{'.','E','.'},
                             {'.','#','E'},
                             {'.','S','#'}
                            }; 
#endif

#if 0
   int R = 3;
   int C = 4;
   vector<vector<char>> G = {{'a','.','S','a'},
                             {'#','#','#','#'},
                             {'E','b','.','b'}
                            };
#endif

#if 1
   int R = 3;
   int C = 4;
   vector<vector<char>> G = {{'a','S','.','b'},
                             {'#','#','#','#'},
                             {'E','b','.','a'}
                            };
#endif

#if 0
   int R = 1;
   int C = 9;
   vector<vector<char>> G = {{'x','S','.','.','x','.','.','E','x'},
                            };
#endif
   int result = getSecondsRequired(R,C,G);
   cout << "\nResult " << result << "\n";
   return 0;
}  
