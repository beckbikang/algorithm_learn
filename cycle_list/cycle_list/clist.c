//
//  clist.c
//  cycle_list
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "clist.h"
#include <stdlib.h>
#include <string.h>

//cinit
void clist_init(CList *clist,void(*destroy)(void *data)){
    clist->size = 0;
    clist->destroy = destroy;
    clist->head = NULL;
    return;
}
//在element元素后插入一个元素，
//如果element为空，则插入链表头部
//需要考虑链表为空的情况
int clist_ins_next(CList *clist, CListElmt *element,const void *data){
    CListElmt* newElement;
    
    newElement = malloc(sizeof(CListElmt));
    if(newElement == NULL) return -1;
    newElement->data = (void*)data;
    newElement->next = NULL;
    
    if(clist_size(clist) == 0){
        newElement->next = newElement;
        clist->head = newElement;
    }else{
        if(element == NULL){
            element = clist->head;
        }
        newElement->next = element->next;
        element->next = newElement;
    }
    clist->size++;
    return 0;
}
//删除element后面的那个元素，如果element为空,则删除链表头元素
int clist_rem_next(CList *clist,CListElmt *element,void **data)
{
    CListElmt *oldElement;
    if(clist_size(clist) == 0)return  -1;
    if(element == NULL) element = clist->head;
    
    
    if(element->next == element){
        oldElement = element->next;
        *data = oldElement->data;
        clist->head = NULL;
    }else{
        oldElement = element->next;
        *data = oldElement->data;
        element->next = element->next->next;
        if(oldElement == clist->head){
            clist->head = oldElement->next;
        }
    }
    free(oldElement);

    clist->size--;
    return 0;
}

void clist_destroy(CList *clist){
    void *data;
    while(clist_size(clist) > 0){
        if(clist_rem_next(clist,NULL,(void**)&data) == 0 && clist->destroy != NULL ){
            clist->destroy(data);
        }
    }
    memset(clist,0,sizeof(CList));
    return;
}







