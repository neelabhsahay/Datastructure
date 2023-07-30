/*
 * There are n applicants and m free apartments.
 * Your task is to distribute the apartments so that
 * as many applicants as possible will get an apartment.
 * Each applicant has a desired apartment size, and they
 * will accept any apartment whose size is close enough to the desired size.
 * Input
 * The first input line has three integers n, m, and
 * k: the number of applicants, the number of apartments,
 * and the maximum allowed difference.
 * The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant.
 * If the desired size of an applicant is x, he or she will accept any apartment
 * whose size is between x−k and x+k.
 * The last line contains m integers b1,b2,…,bm: the size of each apartment..
 *
 * g++ -shared -o libApartments.so Apartments.cpp
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
numApartments(uint32_t* dSize, uint32_t* apSize, uint32_t numP, uint32_t numA, uint32_t k) {
    std::vector<uint32_t> dS;
    std::vector<uint32_t> aS;
    
    for( int i =0; i < numP; i++ ) {
        dS.push_back(dSize[i]);
    }
    for( int i =0; i < numA; i++ ) {
        aS.push_back(apSize[i]);
    }
    std::sort(dS.begin(), dS.end());
    std::sort(aS.begin(), aS.end());
    //std::cout << cW << std::endl;
    int i =0;
    int j = 0;
    uint32_t taken = 0;
    while( i < numA && j < numP) {
        //std::cout << " n: " << n << " m: " << m << std::endl;
        if((aS[i] - k) < dS[j] && dS[j] < (aS[i] + k)) {
            taken++;
            i++;
            j++;
        } else if (dS[j] < (aS[i] - k)) {
            j++;
        } else if (dS[j] > (aS[i] + k)) {
            i++;
        } else {
          std::cout << "Should not reach here" << std::endl;
          std::cout << "dS[" << j << "] = " << dS[j] << "and aS[ " << i << " ] = " << aS[i] << std::endl;
          break;
        } 
    }
    std::cout << "Number of apartment taken: " << taken << std::endl;
    return;
}

 // C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    void testCode(uint32_t* dSize, uint32_t* apSize, uint32_t numP, uint32_t numA, uint32_t th) {
        numApartments(dSize, apSize, numP, numA, th);
        return;
    }
}