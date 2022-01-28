/*
 * You are given the arrival and leaving times of n customers in a restaurant.
 *
 * What was the maximum number of customers in the restaurant at any time?
 *
 * Input:
 *
 * The first input line has an integer n: the number of customers.
 *
 * After this, there are n lines that describe the customers.
 * Each line has two integers a and b: the arrival and leaving times of a customer.
 *
 * You may assume that all arrival and leaving times are distinct.
 *
 * Output:
 *
 * Print one integer: the maximum number of customers.
 *
 * g++ -shared -o libRestaurent.so Restaurent.cpp
 */

#include<cstdint>
#include<iostream>
#include<vector>

typedef struct Reservation {
    uint32_t str;
    uint32_t end;
} Res;

std::ostream& operator<<(std::ostream& os, const Res& res) {
    return os << "(" << res.str << ", " << res.end <<")";
}

template <typename S>
std::ostream& operator<<(std::ostream& os,
                    const std::vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

bool sortByStart (Res i,Res j) { return (i.str<j.str); }
void
MaxPeople(uint32_t* str, uint32_t* end, uint32_t numP) {
    std::vector<Res> res;
    
    for( int i =0; i < numP; i++ ) {
        Res r;
        r.str = str[i];
        r.end = end[i];
        res.push_back(r);
    }
    std::sort(res.begin(), res.end(), sortByStart);
    std::cout << res << std::endl;
    
    uint32_t no = 0;
    uint32_t last_end = 0;
    for(auto r : res) {
        if( r.str <= last_end ) {
            no++;
        }
        last_end = r.end;
    }
    std::cout << "Max people at the restaurant at time is: " << no << std::endl;
    return;
}

 // C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    void testCode(uint32_t* str, uint32_t* end, uint32_t numP) {
        MaxPeople(str, end, numP);
        return;
    }
}