#include<stdio.h>
#include<stdint.h>

// Given a 128 bits number write a function that returns 
//the number of sequences of ones. 

#define NUM_BYTES_128_BITS  8
#define BITS_IN_BYTE        8
#define true  1
#define false 0

int
numSeqOnes(const void* data)
{
    // since its 128 bits
    uint8_t *nums = (uint8_t*)data;
    uint8_t mask = 1;
    int numSeqOne = 0;
    uint8_t found = false;

    for(int i = NUM_BYTES_128_BITS-1;i>=0;i--) {
        for(int j=0;j<BITS_IN_BYTE;j++) {
            mask = 1  << j;
            if((nums[i] & mask) == 0) {
                if(found) {
                    numSeqOne++;
                }
                found = false;
            } else {
                found = true;
            }
        }
    }

    if(found) {
        numSeqOne++;
    } 
    return numSeqOne;   
}

int
main()
{
    uint64_t data = 0xfff6fffff7ffffff;
    //uint64_t data = 0x3f4a6cb37cd19830;
    //uint64_t data = 5;

    int res = numSeqOnes(&data);
    printf("Number of seq ones %d\n", res);
    return 0;
} 
