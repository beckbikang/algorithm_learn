//
//  c_double_list.h
//  cycle_doublelist
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __cycle_doublelist__c_double_list__
#define __cycle_doublelist__c_double_list__

#include <stdio.h>
#include <stdlib.h>

//定义基础的结构
typedef struct CDListElmt_{
    void *data;
    struct CDListElmt_ *next;
    struct CDListElmt_ *pre;
}CDListElmt;


//定义列表
typedef struct CDlist_{
    int size;//大小
    int (*match)(const void *key1,const void *key2);//比较,匹配
    void (*destroy)(void *data);//内存释放函数
    CDListElmt *head;//头
}CDList;


//初始化
void list_init(CDList *list,void(*destroy)(void *data));
//在element元素后插入一个元素，element不允许为空
int list_ins_next(CDList *list, CDListElmt *element,const void *data);
//在element元素前面插入一个元素,element不允许为空
int list_ins_pre(CDList *list, CDListElmt *element,const void *data);

//删除一个元素
int list_rem(CDList *list,CDListElmt *element, void **data);

//删除一个列表，删除列表里面存储的data
void list_destroy(CDList *list);


//定义基础的宏，获取各种基础的数据：获取大小，头，尾部，判断是头，是尾，数据，下一个元素
#define cdlist_size(list) ((list)->size)
#define cdlist_head(list) ((list)->head)
#define cdlist_is_head(list,element) ((element) == (list)->head?1:0)
#define cdlist_data(element)((element)->data)
#define cdlist_next(element)((element)->next)
#define cdlist_pre(element)((element)->pre)


#endif /* defined(__cycle_doublelist__c_double_list__) */
