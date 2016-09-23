//
//  ohash.h
//  ohash
//
//  Created by bikang on 16/9/23.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __ohash__ohash__
#define __ohash__ohash__

#include <stdlib.h>

typedef struct OHTbl_{
    int positions;//数据个数
    void *vacated;//哨兵--指向不可用的元素
    
    int (*h1)(const void *key);//哈希函数
    int (*h2)(const void *key);//哈希函数
    int (*match)(const void *key1,const void *key2);//比较,匹配
    void (*destroy)(void *data);//内存释放函数
    
    int size;//数据的多少
    void **table;//数据
    
}OHTbl;


int ohtbl_init(OHTbl *htbl,int positions,int (*h1)(const void *key),int (*h2)(const void *key),
               int(*match)(const void *k1,const void *k2),
               void(*destroy)(void*data));

//销毁
void ohtbl_destroy(OHTbl *htbl);
//插入
int ohtbl_insert(OHTbl *htbl,const void *data);
//删除
int ohtbl_remove(OHTbl *htbl,void **data);
//查找
int ohtbl_lookup(OHTbl *htbl,void **data);

#define ohtbl_size(htbl) ((htbl)->size)
#endif /* defined(__ohash__ohash__) */
