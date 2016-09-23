//
//  set.c
//  set
//
//  Created by bikang on 16/9/18.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
#include <stdlib.h>
#include <string.h>

#include "set.h"


//初始化集合
void set_init(Set *set,int(*match)(const void *k1,const void *k2),void(*destroy)(void*data)){
    list_init(set,destroy);
    set->match = match;
    return;
}

//插入数据
int set_insert(Set *set,const void *data){
    if(set_is_member(set, data)){
        return 1;
    }
    return list_ins_next(set, list_tail(set), data);
}

//删除数据
int set_remove(Set *set,void **data){
    
    ListElmt *item,*pre;
    pre = NULL;
    for(item = list_head(set);item != NULL;item = list_next(item)){
        if(set->match(*data,list_data(item))) break;
        pre = item;
    }
    if(item == NULL) return -1;
    return list_rem_next(set, pre, data);
}
//并集
int set_union(Set *setu,const Set *set1,const Set *set2){
    ListElmt *item;
    void *data;
    set_init(setu, set1->match, NULL);
    for(item = list_head(set1);item != NULL;item = list_next(item)){
        data = list_data(item);
        if(list_ins_next(setu, list_tail(setu), data) != 0){
            set_destroy(setu);
            return -1;
        }
    }
    
    for(item = list_head(set2);item != NULL;item = list_next(item)){
        data = list_data(item);
        if(!set_is_member(setu, list_data(item))){
            if(list_ins_next(setu, list_tail(setu), data) != 0){
                set_destroy(setu);
                return -1;
            }
        }
    }
    return 0;
}

//交集
int set_intersection(Set *seti,const Set *set1,const Set *set2){
    ListElmt *item;
    void *data;
    set_init(seti, set1->match, NULL);
    
    for(item = list_head(set1);item != NULL;item = list_next(item)){
        if(set_is_member(set2, list_data(item))){
            data = list_data(item);
            if(list_ins_next(seti, list_tail(seti), data) != 0){
                set_destroy(seti);
                return -1;
            }
        }
    }
    return 0;
}

//差集
int set_difference(Set *setd,const Set *set1,const Set *set2){
    ListElmt *item;
    void *data;
    set_init(setd, set1->match, NULL);
    
    for(item = list_head(set1);item != NULL;item = list_next(item)){
        if(!set_is_member(set2, list_data(item))){
            data = list_data(item);
            if(list_ins_next(setd, list_tail(setd), data) != 0){
                set_destroy(setd);
                return -1;
            }
        }
    }
    return 0;
}


//是否是他的成员
int set_is_member(const Set *set,const void *data){
    ListElmt *item;
    for(item = list_head(set);item != NULL;item = list_next(item)){
        if(set->match(data,list_data(item))) return 1;
    }
    return 0;
}

//set1是否是set2的子集
int set_is_subset(const Set *set1,const Set *set2){
    ListElmt *item;
    // set1
    if(set_size(set1) > set_size(set2)) return 0;
    for(item = list_head(set1);item != NULL;item = list_next(item)){
        if(!set_is_member(set2, list_data(item))) return 0;
    }
    return 1;
}

//是否相等
int set_is_equal(const Set *set1,const Set *set2){
    if(set_size(set1) != set_size(set2)) return 0;
    
    return set_is_subset(set1, set2);
    return 0;
}




