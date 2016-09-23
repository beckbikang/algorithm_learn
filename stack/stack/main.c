//
//  main.c
//  stack
//
//  Created by bikang on 16/9/9.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>

//#include "list.h"
#include "stack.h"

//测试栈
void testStack();

int main(int argc, const char * argv[]) {
    testStack();
    return 0;
}


void testStack(){
    printf("#####test stack\n");
    

    Stack *pstack;
    pstack = malloc(sizeof(Stack));
    stack_init(pstack,NULL);
   
    int *p1 = (int *)malloc(sizeof(int));
    int *p2 = (int *)malloc(sizeof(int));
    int *p3 = (int *)malloc(sizeof(int));
    int i1 = 1;p1 = &i1;
    int i2 = 2;p2 = &i2;
    int i3 = 3;p3 = &i3;
    
    stack_push(pstack,(void*)p1);
    stack_push(pstack,(void*)p2);
    stack_push(pstack,(void*)p3);
    printf("stack_size=%d\n",stack_size(pstack));
    int *data1 = (int*)malloc(sizeof(int));
    stack_pop(pstack, (void**)&data1);
    printf("pop=%d\n", *data1);
    
    if(stack_peek(pstack)){
        printf("print top\n");
        printf("top=%d\n",*(int*)stack_peek(pstack));
    }
    stack_destroy(pstack);

}
