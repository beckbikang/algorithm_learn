//
//  double_list.h
//  doublelist
//
//  Created by bikang on 16/8/29.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __doublelist__double_list__
#define __doublelist__double_list__

#include <stdlib.h>

//定义基础的结构
typedef struct DListElmt_{
    void *data;
    struct DListElmt_ *next;
    struct DListElmt_ *pre;
}DListElmt;


//定义列表
typedef struct Dlist_{
    int size;//大小
    int (*match)(const void *key1,const void *key2);//比较,匹配
    void (*destroy)(void *data);//内存释放函数
    DListElmt *head;//头
    DListElmt *tail;//尾部
}DList;


//初始化
void list_init(DList *list,void(*destroy)(void *data));
//在element元素后插入一个元素，element不允许为空
int list_ins_next(DList *list, DListElmt *element,const void *data);
//在element元素前面插入一个元素,element不允许为空
int list_ins_pre(DList *list, DListElmt *element,const void *data);

//删除一个元素
int list_rem(DList *list,DListElmt *element, void **data);

//删除一个列表，删除列表里面存储的data
void list_destroy(DList *list);


//定义基础的宏，获取各种基础的数据：获取大小，头，尾部，判断是头，是尾，数据，下一个元素
#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(list,element) ((element) == (list)->head?1:0)
#define dlist_is_tail(element) ((element)->next == NULL?1:0)
#define dlist_data(element)((element)->data)
#define dlist_next(element)((element)->next)
#define dlist_pre(element)((element)->pre)

#endif /* defined(__doublelist__double_list__) */
