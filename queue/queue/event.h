//
//  event.h
//  queue
//
//  Created by bikang on 16/9/12.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __queue__event__
#define __queue__event__

#include <stdio.h>
#include "queue.h"
typedef struct _Event{
    
}Event;
int receive_event(Queue *events,const Event *event);
int process_event(Queue *events, int(*dipatch)(Event *event));


#endif /* defined(__queue__event__) */
