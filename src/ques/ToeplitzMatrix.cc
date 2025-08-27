/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

Variant:
The matrix is given as a array/list with two more element, num of rows and nums of columns
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

bool
isToeplitzMatrix(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    for(int i = 0;i<c;i++) {
        for(int j = 1;j<r;j++) {
            if(i+j < c) {
                if(matrix[j-1][i+j-1] != matrix[j][i+j]) {
                    return false;
                }
            }
        }
    }

    for(int i = 1;i<r;i++) {
        for(int j = 1;j<c;j++) {
            if(i+j < r ) {
                if(matrix[i+j-1][j-1] != matrix[i+j][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool
isToeplitzArrayMatrix(vector<int>& nums, int row, int col) {
    int r = row;
    int c = col;

    for(int i = 0;i<c;i++) {
        for(int j = 1;j<r;j++) {
            if(i+j < c) {
                if(nums[((j-1)*c)+i+j-1] != nums[(j*c)+i+j]) {
                    return false;
                }
            }
        }
    }

    for(int i = 1;i<r;i++) {
        for(int j = 1;j<c;j++) {
            if(i+j < r ) {
                if(nums[((i+j-1)*c)+j-1] != nums[((i+j)*c)+j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int
main()
{
    vector<vector<int>> matrix = {{0,  1,  2,  3,  4,  5},
                                  {6,  0,  1,  2,  3,  4},
                                  {7,  6,  0,  1,  2,  3},
                                  {8,  7,  6,  0,  1,  2},
                                  {9,  8,  7,  6,  0,  1}};
#if 0
    vector<int> nums = { 0,  1,  2,  3,  4,  5,
                         6,  0,  1,  2,  3,  4,
                         7,  6,  0,  1,  2,  3,
                         8,  7,  6,  0,  1,  2,
                         9,  8,  7,  6,  0,  1};
    int row = 5;
    int col = 6;
#endif
    vector<int> nums =  {0,  1,  2,  3,  4,  5,
                         6,  0,  1,  2,  3,  4,
                         7,  6,  0,  1,  2,  3,
                         8,  7,  6,  0,  1,  2,
                         9,  8,  7,  6,  3,  1};
   int row = 5;
   int col = 6;

    cout << matrix << "\n This is ToeplitzMatrix: " << ((true == isToeplitzMatrix(matrix))?"YES":"NO") <<"\n";

    cout << nums << "\n This is ToeplitzMatrix: " << ((true == isToeplitzArrayMatrix(nums, row, col))?"YES":"NO") <<"\n";
    return 0;
}
