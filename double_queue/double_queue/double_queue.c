//
//  double_queue.c
//  double_queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "double_queue.h"
//从前面入队列
int dqueue_head_enqueue(Dqueue *queue, void *data){
    return list_ins_pre(queue,dlist_head(queue),data);
}
//从前面出队列
int dqueue_head_dequeue(Dqueue *queue, void **data){
    return list_rem(queue,dlist_head(queue),data);
}

//从后面入队列
int dqueue_tail_enqueue(Dqueue *queue, void *data){
    return list_ins_next(queue,dlist_tail(queue),data);
}
//从后面出队列
int dqueue_tail_dequeue(Dqueue *queue, void **data){
    return list_rem(queue,dlist_tail(queue),data);
}