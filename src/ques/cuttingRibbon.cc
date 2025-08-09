/*
In this problem, you are given an array of integers named ribbons,
 where each element represents the length of a particular ribbon.
 Additionally, you are given an integer k, which represents the
 target number of ribbons that you want to obtain.
 The challenge is to cut these ribbons into segments of equal length.
 Importantly, the length of each segment must be a positive integer,
 and you're looking for the maximum possible length of these segments
that will allow you to create exactly k segments

Algo:
   We can try cutting the ribbon of size 1 to sum(ribbons[])/k
   using binary seach, because we cannot cut a ribbon greater than
   sum(ribbons[])/k because total length is sum(ribbons[])
*/
#include<iostream>

#include "utils.hpp"

using namespace std;

bool
canCutRibbon(vector<int> &ribbons, int size, int count) {
    for(auto ribbon:ribbons) {
        count -= (ribbon/size);
        if(count <=0) {
            return true;
        }
    }

    if(count <=0) {
        return true;
    } else {
        return false;
    }
}
int
cutRibbons(vector<int> &ribbons, int k)
{
    int max_size = 0;
    int size = 0;
    for(auto ribbon:ribbons) {
        max_size = max(max_size,ribbon);
    }
    int l = 1; // least size ribbon
    int h = max_size; // max size ribbon
    int m;

    // binary search between these two

    while(l <= h) {
        m = (h-l)/2 + l;
        if(canCutRibbon(ribbons, m, k)) {
            size = m;
            l = m+1;
        } else {
            h = m-1;
        }
    }
    return size;
}

int
main()
{
    vector<int> ribbons = {9, 7, 5};
    int k = 22;

    int answer = cutRibbons(ribbons, k);

    cout << ribbons << " these can be cut in max " << answer <<"\n";
    return 0;
}
