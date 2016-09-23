//
//  cover.h
//  set
//
//  Created by bikang on 16/9/19.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __set__cover__
#define __set__cover__

#include <stdio.h>

#include "set.h"

typedef struct KSet_{
    void *key;
    Set set;
}KSet;

int cover(Set *members,Set *subsets,Set *covering);


#endif /* defined(__set__cover__) */
