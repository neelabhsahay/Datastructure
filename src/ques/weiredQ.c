#include<stdio.h>

void
weirdedQues(unsigned int n ) {
    if( n == 1 ) {
        return;
    }
    printf("\n");
    // if odd then multiply by 3 and add 1
    // if even divide by 2
    while(n != 1) {
       printf("%d  ", n);
        switch( n & 1 ) {
            case 0:
                  // even case
                  n = n >> 1;
                  break;
            case 1:
                 // odd case
                 n = ( n << 1) + n + 1;
                 break;
       }
    }
    printf("%d \n", n);
    return;
}
