//
//  stack.c
//  stack
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdlib.h>
#include "stack.h"

//入栈
int stack_push(Stack *stack,const void* data){
    return list_ins_next(stack,NULL,data);
}
//出栈
int stack_pop(Stack *stack,void** data){
    return list_rem_next(stack,NULL,data);
}




