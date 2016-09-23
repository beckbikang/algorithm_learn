//
//  page.c
//  cycle_list
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "page.h"
#include "clist.h"

/**
 比如我们可以根据使用时间周期性的更新所有的number的reference
 定期没有使用的number的reference 都更新为0
 
 查找reference 为0 的页的number，你就可以使用它了
 **/
int replace_page(CListElmt ** current){
    
    while( ((Page*)((*current)->data))->reference != 0){
        ((Page*)((*current)->data))->reference =0;
        *current = clist_next(*current);
    }
    
    return ((Page*)((*current)->data))->number;
}
