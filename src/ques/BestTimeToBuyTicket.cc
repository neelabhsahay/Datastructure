/*
Given two arrays departure[] and return[s]
that contain price of departure and return ticket
you need to bu ticket for departure an d in future
return, minimise the cost.
departure = {1,2,3,4}
returns = {4,3,2,1}
Answer= 2
*/

#include<iostream>

using namespace std;

int
minFlightCost(vector<int> &departure, vector<int> &returns)
{
    int min_cost = INT_MAX;
    int n = departure.size();

    int d = 0;
    int r = 1;
    while(d<n && r<n) {
        min_cost = min(min_cost, departure[d] + returns[r]);
        if(departure[d] > departure[r]) {
            d = r;
        }
        r++;
    }

    return min_cost;
}


int
main() {
    vector<int> departure = {4,3,5,11,2};
    vector<int> returns = {1,6,10,2,9};

    int cost = minFlightCost(departure, returns);

    cout << "Min Cost: " << cost <<"\n";
    return 0;
} 
