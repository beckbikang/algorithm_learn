//
//  cover.c
//  set
//
//  Created by bikang on 16/9/19.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "cover.h"
#include "list.h"
#include "set.h"
#include <stdlib.h>

/**
 
 完全覆盖集合算法
 S 大的集合
 P 集合列表
 C 需要完全覆盖的数据
 
 
 1 找出S&P的最大集合a，插入C
 2 从S中删除a，从P中删除a,继续查找最大的集合，如果max为0则退出
 
 
 **/

int cover(Set *members,Set *subsets,Set *covering){
    Set intersection;
    KSet *subset;
    ListElmt *member = NULL;
    ListElmt *max_member = NULL;
    void *data;
    int max_size;
    
    set_init(covering, subsets->match, NULL);
    
    while(set_size(members) > 0 && set_size(subsets) > 0){
        max_size = 0;
        //循环p，查找p和s的交集，找到最大的交集
        for(member = list_head(subsets);member != NULL;member=list_next(member)){
            if(set_intersection(&intersection,&((KSet*)list_data(member))->set,members)!= 0) {
                return -1;
            }
            if(set_size(&intersection) > max_size){
                max_member = member;
                max_size = set_size(&intersection);
            }
            set_destroy(&intersection);
        }
        //如果为0，说明已经查找成功
        if(max_size == 0) return 1;
        
        //将数据插入covering  插入c
        subset = (KSet *)list_data(max_member);
        
        if(set_insert(covering, subset) != 0){
            return -1;
        }
        
        //从s中删除
        for(member = list_head(&((KSet*)list_data(max_member))->set);member!= NULL;member = list_next(member)){
            data = list_data(member);
            
            if(set_remove(members, (void**)&data) ==0 &&members->destroy != NULL) members->destroy(data);
        }
        
        
        //subsets中删除数据 从p删除
        if(set_remove(subsets, (void**)&subset) != 0){
            return -1;
        }
        
    }
    if(set_size(members) > 0) return -1;
    
    return 0;
}