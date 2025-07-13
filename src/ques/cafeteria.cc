#include <iostream>

// given a bench of lengh len, maked 1, len, we need to
// place people which has distance d between them
// a vector of place already occupied at position
// return how many people we can place more

int
cafeteria(std::vector<int> &N, int len, int K)
{
    int count = 0;
    int prev = 1;
    int n = N.size();

    std::sort(N.begin(), N.end());

    // from 1 to first filled, we have to divide this into
    // K+1 size blocks, as only one side is not allowed.
    // same is for last seated position to end we are allowed
    // till end of same size.
    //std::cout << (N[0]-prev) << ":" << (N[0]-prev)/(K+1) << " ";
    count += ((N[0]-prev)/(K+1));
   
    // For position between people we are not allowed the last hence
    // we decrease one block this its K+1 sized block and substract ONE
    // the number of blocks  
    prev = N[0];
    for(int i =1;i<n;i++) {
        //std::cout << (N[i]-prev) << ":" << ((N[i]-prev)/(K+1) -1) << " ";
        if(((N[i]-prev)/(K+1) -1) >0)
            count += ((N[i]-prev)/(K+1) -1);
        prev = N[i];
    } 

    //std::cout << (len-prev) << ":" << (len-prev)/(K+1) << "\n";
    count += (len-prev)/(K+1);

    return count;
}

int
main()
{
    #if 0
    // Test 1:
    std::vector<int> occupied = {2, 6};
    int len = 10;
    int gap = 1;
    //Expected Return Value = 3
    #endif
    std::vector<int> occupied = {11, 6, 14};
    int len = 15;
    int gap = 2;
    // Expected Return Value = 1
    #if 0
    std::vector<int> occupied = {12,24, 29};
    int len = 40;
    int gap = 4;
    #endif
    //1----6-----12----17------24----29----34----39-
    int count = cafeteria(occupied, len, gap);
    std::cout << "total extra " << count <<"\n";
    return 0;
}
