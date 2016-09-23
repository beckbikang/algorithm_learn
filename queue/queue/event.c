//
//  event.c
//  queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "event.h"
#include <stdlib.h>
#include <string.h>

//入队列
int receive_event(Queue *events,const Event *event){
    Event *new_event;
    if((new_event = (Event*)malloc(sizeof(Event))) == NULL) return -1;
    memcpy(new_event, event, sizeof(Event));
    
    if(queue_enqueue(events,new_event) != 0)
        return -1;
    return 0;
}
//出队列，处理数据
int process_event(Queue *events, int(*dispatch)(Event *event)){
    Event *event;
    if(queue_size(events) == 0) return -1;
    else{
        if(queue_dequeue(events,(void **) &event)){
            
        }else{
            dispatch(event);
            free(event);
        }
    }
    
    return 0;
}



