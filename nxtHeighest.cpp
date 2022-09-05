// This give the next heighest number in each array index.

#include<iostream>
#include<stack>
#include <iomanip>


void
nxtHeighest(int *A, int num, int* nxtH) {
    if( A == NULL || num == 0 || nxtH == NULL) {
        return;
    }

    std::stack<int> stk;
    stk.push(0);
    int i =1;
    for( i =1; i < num; i++ ) {
        while( !stk.empty() && A[stk.top()] < A[i] ) {
            nxtH[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }

    while( !stk.empty() ) {
        nxtH[stk.top()] = -1;
        stk.pop();
    }
    return;
}

// C-linkage is required as this function we will call from python.
extern "C"  //Tells the compile to use C-linkage for the next scope.
{

void
getNextHeighest(int* A, int num) {
    if( A == NULL || num == 0) {
        return;
    }

    int * nxt = (int*)malloc( num * sizeof(int));
    nxtHeighest(A, num, nxt);
    for( int i = 0; i < num; i++ ) {
        std::cout << std::setw(3) << A[i] << " ";
    }
    std::cout <<std::endl;
    for( int i = 0; i < num; i++ ) {
        std::cout << std::setw(3) << nxt[i] << " ";
    }
    std::cout <<std::endl;

    free(nxt);
    return;
}

}
