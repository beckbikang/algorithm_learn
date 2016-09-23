//
//  double_list.c
//  doublelist
//
//  Created by bikang on 16/8/29.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
#include <stdlib.h>
#include <string.h>

#include <stdio.h>


#include "double_list.h"

//初始化
void list_init(DList* list,void(*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = list->tail = NULL;
    return;
}

//插入数据,在element之后
int list_ins_next(DList *list, DListElmt *element,const void *data){
    DListElmt *new_element;
    
    if(dlist_size(list) != 0 && element == NULL ){
        return -1;
    }
    
    if((new_element = malloc(sizeof(DListElmt))) == NULL) return -1;
    
    new_element->next = NULL;
    new_element->pre = NULL;
    new_element->data = (void*)data;
    
    //error
    if(dlist_size(list) == 0){
        list->head = new_element;
        list->tail = new_element;
    }else {
        new_element->next = element->next;
        new_element->pre = element;
        if (element->next == NULL) {
            list->tail = new_element;
        }else{
            element->next->pre = element;
        }
        element->next = new_element;
    }
    list->size ++;
    return 0;
}


//插入在数据之后
int list_ins_pre(DList *list, DListElmt *element,const void *data){
    DListElmt *new_element;
    
    if(dlist_size(list) != 0 && element == NULL ){
        return -1;
    }
    
    if((new_element = malloc(sizeof(DListElmt))) == NULL) return -1;
    
    new_element->next = NULL;
    new_element->pre = NULL;
    new_element->data = (void*)data;
    
    //error
    if(dlist_size(list) == 0){
        list->head = new_element;
        list->tail = new_element;
    }else {
        new_element->next = element;
        new_element->pre = element->pre;
        
        if(element->pre == NULL){
            list->head = new_element;
        }else{
            element->pre->next = new_element;
        }
        element->pre = new_element;
    }
    list->size++;
    return 0;
}

//删除一个元素
int list_rem(DList *list,DListElmt *element, void **data){
    if(dlist_size(list) == 0 || element == NULL ){
        return -1;
    }
    *data = element->data;
    if(element == list->head){
        list->head = element->next;
        if(list->head == NULL){
            list->tail = NULL;
        }else{
            list->head->pre = NULL;
        }
    }else{
        element->pre->next = element->next;
        if(element->next == NULL){
            list->tail = element->pre;
        }else{
            element->next->pre = element->pre;
        }
    }
    free(element);
    list->size--;
    return 0;
}

/**
 destroy data;
 **/
void list_destroy(DList *list){
    void *data;
#ifdef DEBUG_FREE
    int i=0;
#endif
    while( dlist_size(list) > 0 ){
        
        if(list_rem(list,dlist_tail(list),(void**)&data) == 0 && list->destroy != NULL){
            list->destroy(data);
#ifdef DEBUG_FREE
            i++;
            printf("free-->%d\n",i);
#endif
        }
    }
    return;
}














