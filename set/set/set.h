//
//  set.h
//  set
//
//  Created by bikang on 16/9/18.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __set__set__
#define __set__set__

#include <stdlib.h>
#include "list.h"

typedef List Set;

void set_init(Set *set,int(*match)(const void *k1,const void *k2),void(*destroy)(void*data));
#define set_destroy list_destroy
//插入
int set_insert(Set *set,const void *data);
//删除
int set_remove(Set *set,void **data);
//并集
int set_union(Set *setu,const Set *set1,const Set *set2);
//交集
int set_intersection(Set *seti,const Set *set1,const Set *set2);
//差集
int set_difference(Set *setd,const Set *set1,const Set *set2);
//是否是他的成员
int set_is_member(const Set *set,const void *data);
//是否是子集
int set_is_subset(const Set *set1,const Set *set2);
//是否相等
int set_is_equal(const Set *set1,const Set *set2);

#define set_size(set) ((set)->size)
#endif /* defined(__set__set__) */
