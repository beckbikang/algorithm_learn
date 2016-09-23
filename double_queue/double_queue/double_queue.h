//
//  double_queue.h
//  double_queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __double_queue__double_queue__
#define __double_queue__double_queue__

#include "double_list.h"

typedef DList Dqueue;

#define dqueue_init list_init
#define dqueue_destroy list_destroy

//从前面入队列
int dqueue_head_enqueue(Dqueue *queue, void *data);
//从前面出队列
int dqueue_head_dequeue(Dqueue *queue, void **data);

//从后面入队列
int dqueue_tail_enqueue(Dqueue *queue, void *data);
//从后面出队列
int dqueue_tail_dequeue(Dqueue *queue, void **data);

#define dqueue_tail_peek(queue)((queue)->tail == NULL?NULL:((queue)->tail->data))
#define dqueue_head_peek(queue)((queue)->head == NULL?NULL:((queue)->head->data))
#define dqueue_size dlist_size

#endif /* defined(__double_queue__double_queue__) */
