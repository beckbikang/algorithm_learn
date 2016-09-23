//
//  main.c
//  set
//
//  Created by bikang on 16/9/18.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>
#include "set.h"

int match_data(const void *d1 ,const void *d2);


void t_match();
void tset();//测试set
void print_set(Set *set);//打印set

int main(int argc, const char * argv[]) {
    //t_match();
    tset();
    return 0;
}
void tset(){
    //初始化set1
    Set *set1 = (Set*)malloc(sizeof(Set));
    set_init(set1, match_data, NULL);
    //插入
    int i = 1; int *pi = &i;
    int i2 = 2;int *pi2 = &i2;
    int i3 = 3; int *pi3 = &i3;
    int i4 = 4;int *pi4 = &i4;
    int i5 = 5; int *pi5 = &i5;
    int i6 = 6;int *pi6 = &i6;
    int i7 = 2;int *pi7 = &i7;
    set_insert(set1, pi);
    set_insert(set1, pi2);
    set_insert(set1, pi3);
    set_insert(set1, pi4);
    set_insert(set1, pi5);
    set_insert(set1, pi6);
    set_insert(set1, pi7);
    print_set(set1);
    //集合大小
    printf("set_size=%d\n",set_size(set1));
    //删除
    set_remove(set1, (void**)&pi5);
    print_set(set1);
    //初始化set2
    Set *set2 = (Set*)malloc(sizeof(Set));
    set_init(set2, match_data, NULL);
    int i8 = 6; int *pi8 = &i8;
    int i9 = 7;int *pi9 = &i9;
    int i10 = 8;int *pi10 = &i10;
    set_insert(set2, pi8);
    set_insert(set2, pi9);
    set_insert(set2, pi10);
    print_set(set2);
    //并集
    Set *setu = (Set*)malloc(sizeof(Set));
    set_init(setu, match_data, NULL);
    set_union(setu, set1, set2);
     print_set(setu);
    //交集
    Set *seti = (Set*)malloc(sizeof(Set));
    set_init(seti, match_data, NULL);
    set_intersection(seti, set1, set2);
    print_set(seti);
    //差集
    Set *setd = (Set*)malloc(sizeof(Set));
    set_init(setd, match_data, NULL);
    set_difference(setd, set1, set2);
    print_set(setd);
    //是否是子集
    printf("set_is_sub=%d\n",set_is_subset(setd, set1));
    
    //摧毁集合
    set_destroy(set1);
    set_destroy(set2);
    
}
int match_data(const void *d1 ,const void *d2){
    if(*(int*)d1 == *(int*)d2) return 1;
    return 0;
}
void t_match(){
    int i = 1; int *pi = &i;
    int i2 = 2;int *pi2 = &i2;
    printf("match_result:%d",match_data(pi, pi2));
}

void print_set(Set *set){
    ListElmt *item;
    if(set_size(set) == 0) {
        puts("set is empty\n");
        return;
    }
    
    for(item = list_head(set);item != NULL;item = list_next(item)){
        printf("%d,",*(int*)list_data(item));
    }
    printf("\n");
    return;
}









