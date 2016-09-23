//
//  main.c
//  queue
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

void tqueue();

int main(int argc, const char * argv[]) {
    tqueue();
    
    
    return 0;
}

void tqueue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue_init(queue,NULL);
    
    int *p1,*p2,*p3;
    int i1 = 1;p1 = &i1;
    int i2 = 2;p2 = &i2;
    int i3 = 3;p3 = &i3;
    
    queue_enqueue(queue,(void*)p1);
    queue_enqueue(queue,(void*)p2);
    queue_enqueue(queue,(void*)p3);
    
    printf("queue_size=%d\n",queue_size(queue));
    
    int *data1 = (int*)malloc(sizeof(int));
    queue_dequeue(queue, (void**)&data1);
    printf("dequeue=%d\n",*data1);
    
    if(queue_peek(queue)){
        printf("top=%d\n",*(int*)queue_peek(queue));
    }
    
    queue_destroy(queue);
    
    
}
