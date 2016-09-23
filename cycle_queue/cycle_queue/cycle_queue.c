//
//  cycle_queue.c
//  cycle_queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "cycle_queue.h"
#include <stdlib.h>


int cqueue_enqueue(Cqueue *queue, void *data){
    return clist_ins_next(queue,clist_head(queue),data);
}

int cqueue_dequeue(Cqueue *queue, void **data){
    return clist_rem_next(queue,clist_head(queue),data);
}