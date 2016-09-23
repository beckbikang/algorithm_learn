//
//  page.h
//  cycle_list
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __cycle_list__page__
#define __cycle_list__page__

#include <stdio.h>
#include "clist.h"

typedef struct Page_{
    int number;
    int reference;
}Page;

int replace_page(CListElmt ** current);





#endif /* defined(__cycle_list__page__) */
