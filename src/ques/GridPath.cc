/* There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square.
 * Each path corresponds to a 48-character description consisting of characters D (down),
 * U (up), L (left) and R (right).
 * Eg: DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
 * You are given a description of a path which may also contain characters ? (any direction).
 * Your task is to calculate the number of paths that match the description.
 *
 * gcc -shared -o libGridPath.so GridPath.c
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_GRID_COL 7
#define MAX_GRID_ROW 7
#define MAX_INST_NUM 48

uint32_t
numOfPath(char *I, uint8_t max_instruct, uint8_t ip, int8_t i, int8_t j) {
    uint32_t numPath = 0;
    
    if (i >= MAX_GRID_COL || i < 0) {
        return 0;
    }
    if (j >= MAX_GRID_ROW || j < 0) {
        return 0;
    }
    if (ip >= max_instruct) {
        return 1;
    }

    //printf( "Postion In (%d, %d) for instr %d\n", i, j, ip);
    
    if ( I[ip] == '?') {
        //printf( "Postion ALL (%d, %d ) \n", i, j); 
        numPath = numOfPath(I, max_instruct, ip+1, i+1, j) + 
                  numOfPath(I, max_instruct, ip+1, i-1, j) +
                  numOfPath(I, max_instruct, ip+1, i, j+1) +
                  numOfPath(I, max_instruct, ip+1, i, j-1);
    } else if (I[ip] == 'U') {
        numPath = numOfPath(I, max_instruct, ip+1, i, j-1);
    } else if (I[ip] == 'D') {
        numPath = numOfPath(I, max_instruct, ip+1, i, j+1);
    } else if (I[ip] == 'L') {
        numPath = numOfPath(I, max_instruct, ip+1, i-1, j);
    } else if (I[ip] == 'R') {
        numPath = numOfPath(I, max_instruct, ip+1, i+1, j);
    }
    return numPath;
}

uint32_t
numGridPath(char* I, uint8_t max_instruct) {
    uint32_t maxPath =0;
    maxPath = numOfPath(I, max_instruct, 0, 0, 0);
    return maxPath;
}

void
testCode(char* I, uint8_t max_instruct) {
    printf("Number of Instruction: %d\n", max_instruct);
    
    printf("\n");
    for( int i = 0; i < max_instruct; i++) {
        printf("%c-", I[i] );
    } 
    printf("\n");
    printf("Number of Paths: %d\n", numGridPath(I, max_instruct));
    return;
}
