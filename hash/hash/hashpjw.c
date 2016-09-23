//
//  hashpjw.c
//  hash
//
//  Created by bikang on 16/9/22.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "hashpjw.h"

unsigned int hashpjw(const void *key){
    
    unsigned int val = 0;
    const char *ptr;
    ptr = (char*) key;
    
    while (*ptr != '\0') {
        unsigned int tmp;
        //往左移动4位,乘以16
        val = (val << 4) + (*ptr);
        //printf("*ptr=%d,val=%d,",*ptr,val);
        //当val大于2^28位的时候，取前四位
        if(tmp = (val & 0xf0000000)){
            //printf("tmp=%d,",tmp);
            //val和val的前16位异或运算
            val = val ^ (tmp >> 24);
            //val和val的28位异或运算
            val = val ^ tmp;
        }
        //printf("new_val=%d,",val);printf("\n");
        ptr++;
    }
    
    
    return val%PRIME_TBLSIZ;
}
