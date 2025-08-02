#include<stdio.h>
#include<stdint.h>

//32-bits byte swap- implement a function that swap
// 32-bits number bytewise

uint32_t 
swapBytes2(uint32_t num) {
    uint32_t res;
    res = (((num >> 24 ) & 0xFF) |
            ((num >> 8) & 0xFF00) |
            ((num << 8) & 0xFF0000) |
            ((num << 24) & 0xFF000000));
     return res; 
}

uint32_t 
swapBytes(uint32_t *num) {
    *num = (((*num >> 24 ) & 0xFF) |
            ((*num >> 8) & 0xFF00) |
            ((*num << 8) & 0xFF0000) |
            ((*num << 24) & 0xFF000000));
     return *num; 
}

int
main()
{
   uint32_t num = 0x02030405;
   uint32_t swap2 = swapBytes2(num);
   //uint32_t swap = swapBytes(&num);
   //printf("Number 0x%08x  Swap 0x%08x \n", num, swap);
   printf("Number 0x%08x  Swap 0x%08x \n", num, swap2);
   return 0;
}
