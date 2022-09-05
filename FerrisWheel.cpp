/*
 * There are n children who want to go to a Ferris wheel,
 * and your task is to find a gondola for each child.
 * Each gondola may have one or two children in it, and in addition,
 * the total weight in a gondola may not exceed x.
 * You know the weight of every child.
 * What is the minimum number of gondolas needed for the children?
 *
 * Input:
 * The first input line contains two integers n and
 * x: the number of children and the maximum allowed weight.
 * The next line contains n integers p1,p2,…,pn: the weight of each child.
 *
 * g++ -shared -o libFerrisWheel.so FerrisWheel.cpp
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
numFerrisWheel(uint32_t* childW, uint32_t numC, uint32_t maxW ) {
    std::vector<uint32_t> cW;
    for( int i =0; i < numC; i++ ) {
        cW.push_back(childW[i]);
    }
    std::sort(cW.begin(), cW.end());
    //std::cout << cW << std::endl;
    int n =0;
    int m = numC -1;
    uint32_t go = 0;
    while( n <= m) {
        //std::cout << " n: " << n << " m: " << m << std::endl;
        if(cW[m] > maxW) {
            go++;
            m--;
        } else if ((cW[m] + cW[n]) > maxW) {
            go++;
            m--;
        } else {
            go++;
            m--;
            n++;
        }        
    }
    std::cout << "Number of gondola required: " << go << std::endl;
    return;
}

 // C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    void testCode(uint32_t* cW, uint32_t numC, uint32_t maxW ) {
        numFerrisWheel(cW, numC, maxW);
        return;
    }
}