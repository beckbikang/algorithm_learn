//
//  main.c
//  ohash
//
//  Created by bikang on 16/9/23.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ohash.h"

#define PRIME_TBLSIZ 1024

int match_chars(const void *k1,const void *k2){
    if(strcmp((char*)k1,(char*)k2) == 0){
        return 0;
    }else{
        return -1;
    }
}
unsigned int hashpjw(const void *key){
    
    unsigned int val = 0;
    const char *ptr;
    ptr = (char*) key;
    
    while (*ptr != '\0') {
        unsigned int tmp;
        val = (val << 4) + (*ptr);
        if(tmp = (val & 0xf0000000)){
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }
        ptr++;
    }
    return val%PRIME_TBLSIZ;
}


int h1(const void*key){
    unsigned int  key1 = hashpjw(key);
    return key1%4096;
}

int h2(const void*key){
    unsigned int key1 =hashpjw(key)%4096;
    
    if(key1 %2 == 0){
        return key1+1;
    }
    return key1;
}

void print_table(OHTbl *t){
    int i;
    for(i = 0; i< t->positions;i++){
        printf("t->positions[%d]=%s\n",i,t->table[i]);
    }
    return;
}

// m 必须 是 2 次幂, 让 h2 返回 一个 奇 数值
int main(int argc, const char * argv[]) {
 
    int findret;
    
    OHTbl *t1 = (OHTbl *)malloc(sizeof(OHTbl));
    //初始化
    ohtbl_init(t1, 64, h1, h2, match_chars, NULL);
    //插入几个数据
    char *s1 = "hello";
    char *s2 = "hello world";
    char *s3 = "struct";
    char *s4 = "cpp";
    ohtbl_insert(t1, s1);
    ohtbl_insert(t1, s2);
    ohtbl_insert(t1, s3);
    ohtbl_insert(t1, s4);
    printf("chtbl_size=%d\n",ohtbl_size(t1));
    //删除一个数据
    //print_table(t1);
    
    //return 1;
    //查找数据
    findret = ohtbl_lookup(t1,(void**)&s4);
    if(findret == 0){
        puts("find ok\n");
    }else{
        puts("find faild\n");
    }
    //return 1;
    char str_test[4] = "cpp";
    char *ptr = str_test;
    char **pptr = &ptr;
    findret = ohtbl_remove(t1, (void**)pptr);
    if(findret==0){
        puts("delete sucess");
    }else{
        puts("delete faild");
    }
    //查找数据
    pptr = &ptr;
    findret = ohtbl_lookup(t1,(void**)pptr);
    if(findret == 0){
        puts("find ok\n");
    }else{
        puts("find faild\n");
    }
    printf("chtbl_size=%d",ohtbl_size(t1));
    //销毁数据
    ohtbl_destroy(t1);
    
    return 0;
}
