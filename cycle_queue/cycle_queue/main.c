//
//  main.c
//  cycle_queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "cycle_queue.h"

void tqueue();
void p_queue(Cqueue *queue);

int main(int argc, const char * argv[]) {
    tqueue();
    
    
    return 0;
}
void tqueue(){
    Cqueue *queue = (Cqueue *)malloc(sizeof(Cqueue));
    cqueue_init(queue,NULL);
    
    int *p1,*p2,*p3;
    int i1 = 1;p1 = &i1;
    int i2 = 2;p2 = &i2;
    int i3 = 3;p3 = &i3;
    
    cqueue_enqueue(queue,(void*)p1);
    cqueue_enqueue(queue,(void*)p2);
    cqueue_enqueue(queue,(void*)p3);

    printf("queue_size=%d\n",cqueue_size(queue));
    p_queue(queue);
    int *data1 = (int*)malloc(sizeof(int));
    cqueue_dequeue(queue, (void**)&data1);
    printf("dequeue=%d\n",*data1);
    
    if(cqueue_size(queue)){
        printf("top=%d\n",*(int*)cqueue_peek(queue));
    }
    p_queue(queue);
    cqueue_destroy(queue);
}

void p_queue(Cqueue *queue){
    if(cqueue_size(queue) == 0)return;
    CListElmt *cur = queue->head;
    int i;
    for(i=0;i<cqueue_size(queue);i++){
        printf("%d,",*(int*)cur->data);
        cur = cur->next;
    }
    printf("\n");

    
}