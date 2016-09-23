//
//  cntbl.h
//  hash
//
//  Created by bikang on 16/9/22.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __hash__cntbl__
#define __hash__cntbl__

#include "list.h"
#include <stdlib.h>

typedef struct CHTbl_{

    int buckets;//桶的大小
    unsigned int (*h)(const void *key);//哈希函数
    
    int (*match)(const void *key1,const void *key2);//比较,匹配
    void (*destroy)(void *data);//内存释放函数
    
    int size;//数据的多少
    List *table;
    
}CHTbl;

//初始化
int chtbl_init(CHTbl *htbl,int buckets,int (*h)(const void *key),
int(*match)(const void *k1,const void *k2),
void(*destroy)(void*data));

//销毁
void chtbl_destroy(CHTbl *htbl);
//插入
int chtbl_insert(CHTbl *htbl,void *data);
//删除
int chtbl_remove(CHTbl *htbl,void **data);
//查找
int chtbl_lookup(CHTbl *htbl,void **data);

//数据的多少
#define chtbl_size(htbl) ((htbl)->size)

#endif /* defined(__hash__cntbl__) */
