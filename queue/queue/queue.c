//
//  queue.c
//  queue
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "queue.h"

//入队列
int queue_enqueue(Queue *queue,const void *data){
    return list_ins_next(queue,list_tail(queue),data);
}
//出队列
int queue_dequeue(Queue *queue,void **data){
    return list_rem_next(queue,NULL,data);
}