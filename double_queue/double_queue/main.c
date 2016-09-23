//
//  main.c
//  queue
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>
#include "double_queue.h"

void tqueue();
void p_queue(Dqueue *queue);

int main(int argc, const char * argv[]) {
    tqueue();
    
    
    return 0;
}

void tqueue(){
    Dqueue *queue = (Dqueue *)malloc(sizeof(Dqueue));
    dqueue_init(queue,NULL);
    
    Dqueue *queue2 =(Dqueue *)malloc(sizeof(Dqueue));
    dqueue_init(queue2,NULL);
    int *p1,*p2,*p3;
    int i1 = 1;p1 = &i1;
    int i2 = 2;p2 = &i2;
    int i3 = 3;p3 = &i3;
    
    dqueue_head_enqueue(queue,(void*)p1);
    dqueue_head_enqueue(queue,(void*)p2);
    dqueue_head_enqueue(queue,(void*)p3);
    
    dqueue_head_enqueue(queue2,(void*)p1);
    dqueue_head_enqueue(queue2,(void*)p2);
    dqueue_head_enqueue(queue2,(void*)p3);
    
    printf("queue_size=%d\n",dqueue_size(queue));
    p_queue(queue);
    p_queue(queue2);
    int *data1 = (int*)malloc(sizeof(int));
    dqueue_head_dequeue(queue, (void**)&data1);
    printf("dequeue=%d\n",*data1);
    dqueue_head_dequeue(queue2, (void**)&data1);
    printf("dequeue=%d\n",*data1);
    
    if(dqueue_size(queue)){
        printf("top=%d\n",*(int*)dqueue_head_peek(queue));
    }
    p_queue(queue);
    p_queue(queue2);
    
    dqueue_destroy(queue2);
    dqueue_destroy(queue);
}

void p_queue(Dqueue *queue){
    if(dqueue_size(queue) == 0)return;
    DListElmt *head = queue->head;
    while(head != NULL){
        printf("%d,",*(int*)(head->data));
        head = head->next;
    }
    printf("\n");
}
