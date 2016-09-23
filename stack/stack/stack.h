//
//  stack.h
//  stack
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __stack__stack__
#define __stack__stack__

#include <stdlib.h>
#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

int stack_push(Stack *stack,const void* data);
int stack_pop(Stack *stack,void** data);

#define stack_peek(stack)((stack)->head == NULL?NULL:((stack)->head->data))

#define stack_size list_size
#endif /* defined(__stack__stack__) */
