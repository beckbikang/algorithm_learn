//
//  clist.h
//  cycle_list
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __cycle_list__clist__
#define __cycle_list__clist__
//定义基础的结构
typedef struct CListElmt_{
    void *data;
    struct CListElmt_ *next;
}CListElmt;

//定义列表
typedef struct clist_{
    int size;//大小
    int (*match)(const void *key1,const void *key2);//比较,匹配
    void (*destroy)(void *data);//内存释放函数
    CListElmt *head;//头
}CList;

//初始化
void clist_init(CList *clist,void(*destroy)(void *data));
//在element元素后插入一个元素，如果element为空，则插入链表头部
int clist_ins_next(CList *clist, CListElmt *element,const void *data);
//删除element后面的那个元素，如果element为空,则删除链表头元素
int clist_rem_next(CList *clist,CListElmt *element,void **data);
//删除一个列表，删除列表里面存储的data
void clist_destroy(CList *clist);


//定义基础的宏
#define clist_size(clist) ((clist)->size)
#define clist_head(clist) ((clist)->head)
#define clist_is_head(clist,element) ((element) == (clist)->head?1:0)
#define clist_data(element)((element)->data)
#define clist_next(element)((element)->next)


#endif /* defined(__cycle_list__clist__) */
