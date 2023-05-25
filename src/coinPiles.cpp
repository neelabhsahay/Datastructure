#include<iostream>
#include<vector>


int
canempty(int a, int b, std::vector<std::vector<int> > &say ) {
    int j = 0, k = 0;
    if(say[a][b] != 0)
        return say[a][b];
    if(say[a-2][b-1] != 0)
        k = say[a-2][b-1];
    else
       say[a-2][b-1] = canempty(a-2, b-1, say);
    
    if(say[a-1][b-2] != 0)
        j = say[a-1][b-b];
    else
       say[a-1][b-2] = canempty(a-1, b-b, say);
 
    if( k == 1 || j == 1 )
        return 1;
    else
        return 2;
}

void
canCoinPileEmpty(int a, int b) {
    if((a == 0 && b == 0) ||
       (a == 2 && b == 1) ||
       (a == 1 && b == 2)) {
        std::cout << "Yes" << std::endl;
        return;
    }
    if( a < 3 || b < 3) {
       std::cout << "No" << std::endl;
       return;
    }
    std::vector<std::vector<int> > say(a+1, std::vector<int> (b+1, 0));;
    say[0][0] = 1;
    say[0][1] = 2;
    say[0][2] = 2;
    say[1][0] = 2;
    say[1][1] = 2;
    say[1][2] = 1;
    say[2][0] = 2;
    say[2][1] = 1;
 
    int ret = canempty(a, b, say);
    
    if( ret == 1 )
        std::cout << "Yes" << std::endl;
    else 
        std::cout << "No" << std::endl;
    return;
}

extern "C" {
    void testCode(int a, int b) {
        canCoinPileEmpty(a, b );
        return;
    }
}
