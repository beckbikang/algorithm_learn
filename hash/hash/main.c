//
//  main.c
//  hash
//
//  Created by bikang on 16/9/22.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>
#include "hashpjw.h"
#include "match.h"
#include "cntbl.h"

void thashpjw();
void tres();

void tcntble();

int main(int argc, const char * argv[]) {
    printf("start\n");
    //测试hash函数
    thashpjw();
    //tres();
    tcntble();
    return 0;
}
void tcntble(){
    void **data;
    int findret;
    //新建一个hash表
    CHTbl *t1 = malloc(sizeof(CHTbl));
    chtbl_init(t1, 1024, hashpjw, match_chars, NULL);
    
    //插入几个数据
    chtbl_insert(t1, "hello");
    chtbl_insert(t1, "hello world");
    chtbl_insert(t1, "struct");
    chtbl_insert(t1, "cpp");
    //删除一个数据
    char str_test[4] = "cpp";
    char *ptr = str_test;
    char **pptr = &ptr;
    //查找数据
    findret = chtbl_lookup(t1,(void**)pptr);
    if(findret == 0){
        puts("find ok\n");
    }else{
        puts("find faild\n");
    }
    
    findret = chtbl_remove(t1, (void**)pptr);
    if(findret==0){
        puts("delete sucess");
    }else{
        puts("delete faild");
    }
    //查找数据
    pptr = &ptr;
     findret = chtbl_lookup(t1,(void**)pptr);
    if(findret == 0){
        puts("find ok\n");
    }else{
        puts("find faild\n");
    }
    printf("chtbl_size=%d",chtbl_size(t1));
    //销毁数据
    chtbl_destroy(t1);
}

void tres(){
    unsigned int res = 0;
    printf("res=%d,",(res << 4)& 0xf0000000);
    printf("\n");
}

void thashpjw(){
    unsigned int res;
    
    
    res = hashpjw("adfasdd课啊");
    char str_test[4] = "cpp";
    char *ptr = str_test;
    res = hashpjw(ptr);
    printf("adfasdd convert to res=%d\n",res);
}
