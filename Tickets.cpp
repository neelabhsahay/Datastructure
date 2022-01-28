/*
 * There are n concert tickets available, each with a certain price.
 * Then, m customers arrive, one after another.
 * Each customer announces the maximum price they are willing to pay
 * for a ticket, and after this, they will get a ticket with the nearest
 * possible price such that it does not exceed the maximum price.
 *
 * Input:
 * The first input line contains integers n and m: the number of tickets
 * and the number of customers.
 *
 * The next line contains n integers h1,h2,…,hn: the price of each ticket.
 *
 * The last line contains m integers t1,t2,…,tm: the maximum price for each
 * customer in the order they arrive.
 *
 * Output:
 *
 * Print, for each customer, the price that they will pay for their ticket.
 * After this, the ticket cannot be purchased again.
 *
 * If a customer cannot get any ticket, print −1.
 *
 * g++ -shared -o libTickets.so Tickets.cpp
 */

#include<cstdint>
#include<iostream>
#include<vector>

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

void
ticketsAllocate(uint32_t* tckP, uint32_t* maxGP, uint32_t numT, uint32_t numP) {
    std::vector<uint32_t> tkP;
    std::vector<uint32_t> mP;
    
    for( int i =0; i < numT; i++ ) {
        tkP.push_back(tckP[i]);
    }
     for( int i =0; i < numP; i++ ) {
        mP.push_back(maxGP[i]);
    }

    std::sort(tkP.begin(), tkP.end());

    int i = 0;
    int j = 0;
    
    std::cout << mP << std::endl;
    
    while( j < numP) {
        i= 0;
        while( i < tkP.size()) {
            if(mP[j] > tkP[i]) {
                i++;
            } else {
                if ( i <= 0) {
                    std::cout << "-1 ";
                } else {
                    if(mP[j] == tkP[i]) {
                        std::cout << tkP[i] << " ";
                        tkP.erase(tkP.begin() + i);
                    } else {
                        std::cout << tkP[i-1] << " ";
                        tkP.erase(tkP.begin() + i -1);
                    }   
                }
                break;
            }
        }
        j++;
    }
    std::cout << std::endl;
    return;
}

 // C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    void testCode(uint32_t* tckP, uint32_t* maxGP, uint32_t numP, uint32_t numA) {
        ticketsAllocate(tckP, maxGP, numP, numA);
        return;
    }
}