//
//  cycle_queue.h
//  cycle_queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __cycle_queue__cycle_queue__
#define __cycle_queue__cycle_queue__

#include "clist.h"

typedef CList Cqueue;

//从前面入队列
int cqueue_enqueue(Cqueue *queue, void *data);
//从前面出队列
int cqueue_dequeue(Cqueue *queue, void **data);

#define cqueue_peek(queue)((queue)->head == NULL?NULL:((queue)->head->data))

#define cqueue_size clist_size
#define cqueue_init clist_init
#define cqueue_destroy clist_destroy

#endif /* defined(__cycle_queue__cycle_queue__) */
