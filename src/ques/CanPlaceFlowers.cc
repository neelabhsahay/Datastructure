/* You have a long flowerbed in which some of the plots are planted,
*  and some are not. However, flowers cannot be planted in adjacent plots.
*
* Given an integer array flowerbed containing 0's and 1's,
* where 0 means empty and 1 means not empty, and an integer n,
* return true if n new flowers can be planted in the flowerbed
* without violating the no-adjacent-flowers rule and false otherwise.
* 
*/

#include<iostream>

#include "utils.hpp"

using namespace std;

bool
canPlaceFlowers (vector<int>& flowerbed, int k) {
    int n = flowerbed.size();
    int i = 0;
    while(i<n) {
        if(((i == 0) || flowerbed[i-1] == 0) &&
           ((i == n-1) || flowerbed[i+1] == 0) &&
           flowerbed[i] == 0) {
            cout << i << " ";
            k--;
            if(k <=0) {
                return true;
            }
            i +=2;
        } else if(flowerbed[i] == 1) {
            // the index is already full so no need to check next
            // move two place
            i +=2;
        } else {
            // move three places as next two is invalid
            // this will only happen when i+1 is filled
            // so we cannot put in i+2 hence we move to i+3
            // to check whether its allowed.
            i +=3;
       }
    }
    return false;
}

int
main()
{
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    cout << "On location " << flowerbed <<
            " we can place " << n << " floweres " <<
            (canPlaceFlowers(flowerbed, n) ? "Yes" : "No") << "\n";
    return 0;
}
