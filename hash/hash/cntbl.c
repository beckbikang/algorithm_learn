//
//  cntbl.c
//  hash
//
//  Created by bikang on 16/9/22.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cntbl.h"
#include "list.h"

//初始化
int chtbl_init(CHTbl *htbl,int buckets,int (*h)(const void *key),
               int(*match)(const void *k1,const void *k2),
               void(*destroy)(void*data)){
    int i;
    //初始化数据
    if((htbl->table =(List*)malloc(sizeof(List)*buckets) ) == NULL) return -1;
    htbl->buckets = buckets;
    for(i=0;i<htbl->buckets;i++){
        list_init(&htbl->table[i], destroy);
    }
    
    htbl->h = h;
    htbl->match = match;
    htbl->destroy = destroy;
    htbl->size = 0;
    return 0;
}

//释放数据
void chtbl_destroy(CHTbl *htbl){
    int i;
    for(i=0;i<htbl->buckets;i++){
        list_destroy(&htbl->table[i]);
    }
    free(htbl->table);
    memset(htbl, 0, sizeof(CHTbl));
    return;
}

//插入
int chtbl_insert(CHTbl *htbl,void *data){
    void *temp;
    int bucket,retval;
    
    temp = (void*)data;
   
    //是否存在,存在直接返回
    if(chtbl_lookup(htbl, &temp) == 0) return 1;
    
    //找到hash key，我们采用除以余数的方法
    bucket = htbl->h(data)%(htbl->buckets);
    //插入数据
    if((retval= list_ins_next(&htbl->table[bucket], NULL, data)) == 0)htbl->size++;
    return 0;
}
//删除
int chtbl_remove(CHTbl *htbl,void **data){
    ListElmt *element=NULL,*prev=NULL;
    int bucket=0;
    
    bucket = htbl->h(*data)%htbl->buckets;
    
    for(element=list_head(&htbl->table[bucket]);element!= NULL;element=list_next(element)){
        if (htbl->match(*data,list_data(element)) == 0) {
            //如果pre为空删除表头，否则删除pre的下一个元素
            if(list_rem_next(&htbl->table[bucket], prev, data)==0){
                htbl->size--;
                return 0;
            }else{
                return -1;
            }
        }
        prev = element;
    }
    return -1;
}

//查找是否存在元素
int chtbl_lookup(CHTbl *htbl,void **data){
    ListElmt *element=NULL;
    int bucket=0;
    
    bucket = htbl->h(*data)%htbl->buckets;
    
    for(element=list_head(&htbl->table[bucket]);element!= NULL;element=list_next(element)){
        if (htbl->match(*data,list_data(element)) == 0) {
            *data = list_data(element);
            return 0;
        }
    }
    return -1;
}


