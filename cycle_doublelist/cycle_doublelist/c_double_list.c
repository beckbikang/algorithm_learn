//
//  c_double_list.c
//  cycle_doublelist
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "c_double_list.h"
#include <stdlib.h>
#include <string.h>

//初始化
void list_init(CDList* list,void(*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head= NULL;
    return;
}
int list_ins_next(CDList *list, CDListElmt *element,const void *data){
    CDListElmt *new_element;
    if(cdlist_size(list) != 0 && element == NULL ){
        return -1;
    }
    if((new_element = malloc(sizeof(CDListElmt))) == NULL) return -1;
    
    new_element->next = NULL;
    new_element->pre = NULL;
    new_element->data = (void*)data;
    if(cdlist_size(list) == 0){
        new_element->next = new_element;
        new_element->pre = new_element;
        list->head = new_element;
    }else{
            new_element->pre = element;
            new_element->next = element->next;
            element->next->pre = new_element;
            element->next = new_element;
    }
    list->size++;
    return 0;
}

//在element元素前面插入一个元素,element不允许为空
int list_ins_pre(CDList *list, CDListElmt *element,const void *data){
    CDListElmt *new_element;
    if(cdlist_size(list) != 0 && element == NULL ){
        return -1;
    }
    if((new_element = malloc(sizeof(CDListElmt))) == NULL) return -1;
    
    new_element->next = NULL;
    new_element->pre = NULL;
    new_element->data = (void*)data;
    if(cdlist_size(list) == 0){
        new_element->next = new_element;
        new_element->pre = new_element;
        list->head = new_element;
    }else{
        new_element->next = element;
        new_element->pre = element->pre;
        element->pre->next = new_element;
        element->pre = new_element;
    }
    list->size++;
    return 0;
}

//删除一个元素
int list_rem(CDList *list,CDListElmt *element, void **data){
    CDListElmt *oldElement;
    if(cdlist_size(list) == 0) return -1;
    
    oldElement = element;
     *data = oldElement->data;
    if(cdlist_size(list) == 1){
        list->head = NULL;
    }else{
        if(element == list->head){
            list->head = element->next;
        }
        element->pre->next = element->next;
        element->next->pre = element->pre;
    }
    free(oldElement);
    list->size--;
    return 0;
}

//delete
void list_destroy(CDList *list){
    void *data;
    while(cdlist_size(list) > 0){
        if(list->destroy != NULL  && list_rem(list,cdlist_head(list),(void**)&data)==0){
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(CDListElmt));
    return;
}



