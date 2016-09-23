//
//  queue.h
//  queue
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __queue__queue__
#define __queue__queue__
#include "list.h"

typedef List Queue ;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue(Queue *queue,const void *data);
int queue_dequeue(Queue *queue,void **data);

#define queue_peek(queue)((queue)->head == NULL?NULL:((queue)->head->data))
#define queue_size list_size




#endif /* defined(__queue__queue__) */
