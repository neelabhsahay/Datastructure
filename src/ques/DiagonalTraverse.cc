/* Given an m x n matrix mat,
* return an array of arrays all the elements of the array in a diagonal order.
* 
*e.g.
* [ [ 1, 2, 3]        / / /    0 1 2
    [ 4, 5, 6]  =>    / / / => 1 2 3
    [ 7, 8, 9]]       / / /    2 3 4

  Result
  [[1], [2,4], [7,5,3], [6,8], [9]]
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

vector<vector<int>> 
diagonalTraverse(vector<vector<int>> &matrix, int row, int col)
{
    vector<vector<int>> result;
    int r = row;
    int c = col;

    bool up = true;
    int i =0, j = 0; // i is rows and j  is columns
    int diagonal_num = 0;
    // there will be total (row + colums - 2) diagonals
    // if diagonal starts with ZERO
    vector<int> temp;
    while(diagonal_num < ((r+c)-1)) {
        if(i<0 || i > r-1 || j <0 || j > c-1) {
            up = !up;
            diagonal_num++;
            if(diagonal_num >= ((r+c)-1)) {
                break;
            }
            result.push_back(temp);
            temp = {};
            if(up) {
                if(diagonal_num >= r) {
                    i = r-1;
                } else {
                    i = diagonal_num;
                } 
                j = diagonal_num -i;
            } else {
                if(diagonal_num >= c) {
                    j = c-1;
                } else {
                    j = diagonal_num;
                } 
                i = diagonal_num -j;
            }
        }

        //cout << "[" << i <<"," << j <<"] ";
        temp.push_back(matrix[i][j]);
        if(up) {
            i--;
            j = diagonal_num -i;
        } else {
            i++;
            j = diagonal_num -i;
        }
    }

    return result;
}

#ifndef IS_LIB
int
main()
{
    //vector<vector<int>> matrix = {{1,2,3,4},
    //                              {5,6,7,8},
    //                              {9,10,11,12}};
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    vector<vector<int>> result = diagonalTraverse(matrix, matrix.size(), matrix[0].size());

    cout << matrix << " has diagonals " << result << "\n";
    return 0;
}

#else
#endif
