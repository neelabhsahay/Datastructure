/*
Given an arrays prices[] that contain price of stocks
you need to buy stock and sell in future
return, maximum profit.
prices = {4,3,2,1}
Answer= 3
*/

#include<iostream>

using namespace std;

int
maxStockGain(vector<int> &prices)
{
    int max_gain = 0;
    int n = prices.size();

    int b = 0;
    int s = 1;
    while(b<n && s<n) {
        max_gain = max(max_gain, (prices[s] - prices[b]));
        if(prices[b] > prices[s]) {
            b = s;
        }
        s++;
    }

    return max_gain;
}


int
main() {
    vector<int> prices = {1,2,3,4};

    int cost = maxStockGain(prices);

    cout << "Max Gain: " << cost <<"\n";
    return 0;
} 
