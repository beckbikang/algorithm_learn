//
//  main.c
//  bsearchtree
//
//  Created by bikang on 16/9/27.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
//AVL树 仍然是 左 子 结点 小于 父 结点， 父 结点 小于 右 子 结点
//AVL树 AVL 树（ Adel' son- Vel' skii and Landis） 是一 种 特殊 类型 的 二 叉 树， 它的 每个 结点 都 保存 一份 额外 的 信息： 结点 的 平衡 因子。
//时， AVL 树 需要 自我 调整， 使得 所有 结点 的 平衡 因子 保持 为+ 1、- 1 或 0。 当子 树 的 根 结点 平衡 因子 为+ 1 时， 它是 左 倾斜 的（ left- heavy）。 当子 树 的 根 结点 平衡 因子 为- 1 时， 它是 右 倾斜 的
//AVL 树（ Adel' son- Vel' skii and Landis） 是一 种 特殊 类型 的 二 叉 树， 它的 每个 结点 都 保存 一份 额外 的 信息： 结点 的 平衡 因子。



#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tree.h"
#include "avltree.h"
//打印链表
void print_list_info(List *list);
//先序
int preorder_tree(const BitTreeNode *node,List *list);
//中序排序
int inorder_tree(const BitTreeNode *node,List *list);
//比较数据
int compare_int(const void *a,const void *b){
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    //printf("compare a1=%d,b1=%d\n",a1,b1);
    if(a1 == b1){
       return 0;
    }else if(a1 > b1) {
        return 1;
    }else{
        return -1;
    }
}

void ttree();

int main(int argc, const char * argv[]) {
    ttree();
    return 0;
}
void ttree(){
    int ret_val;
    
    BisTree *tree = (BisTree*)malloc(sizeof(BisTree));
    bistree_init(tree, compare_int, free);
    
    List *list = (List *)malloc(sizeof(List));
    list_init(list, NULL);
    
    
    int bistree_insert(BisTree *tree,const void *data);
    int a1 = 46;int *p1 = (int *)malloc(sizeof(int));*p1 = a1;
    int a2 = 22;int *p2 = (int *)malloc(sizeof(int));*p2 = a2;
    int a3 = 15;int *p3 = (int *)malloc(sizeof(int));*p3 = a3;
    int a4 = 43;int *p4 = (int *)malloc(sizeof(int));*p4 = a4;
    int a5 = 75;int *p5 = (int *)malloc(sizeof(int));*p5 = a5;
    int a6 = 71;int *p6 = (int *)malloc(sizeof(int));*p6 = a6;
    int a7 = 48;int *p7 = (int *)malloc(sizeof(int));*p7 = a7;
    bistree_insert(tree, (void*)p1);
    
    //插入
    bistree_insert(tree, (void*)p2);
    bistree_insert(tree, (void*)p3);
    bistree_insert(tree, (void*)p4);
    bistree_insert(tree, (void*)p5);
    bistree_insert(tree, (void*)p6);
    bistree_insert(tree, (void*)p7);
    //查找
    void **data = (void**)malloc(sizeof(int));
    *data = p3;
    ret_val = bistree_lookup(tree, data);
    if(ret_val == 0){
        puts("find ok");
    }
    //删除
    bistree_remove(tree,p3);
    
    
    //inorder_tree(bitree_root(tree),list);
    //print_list_info(list);
    
    preorder_tree(bitree_root(tree),list);
    print_list_info(list);
    
    bistree_destroy(tree);
    list_destroy(list);
}

//中序遍历
int inorder_tree(const BitTreeNode *node,List *list){
    if(!bitree_is_eob(node)){
        if(!bitree_is_eob(bitree_left(node))){
            if(inorder_tree(bitree_left(node),list) != 0){
                return -1;
            }
        }
        if(list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
        if(!bitree_is_eob(bitree_right(node))){
            if(inorder_tree(bitree_right(node),list) != 0){
                return -1;
            }
        }
    }
    return 0;
}

//先序遍历
int preorder_tree(const BitTreeNode *node,List *list){
    if(!bitree_is_eob(node)){
        if(list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
        if(!bitree_is_eob(bitree_left(node))){
            if(preorder_tree(bitree_left(node),list) != 0){
                return -1;
            }
        }
        if(!bitree_is_eob(bitree_right(node))){
            if(preorder_tree(bitree_right(node),list) != 0){
                return -1;
            }
        }
    }
    return 0;
}

//打印一个列表
void print_list_info(List *list){
    if(list_size(list) == 0){
        printf("empty list\n");
        return;
    }
    
    ListElmt *pl;
    pl = list_head(list);
    int i;
    printf("\n#########start#############\n");
    for(i=0;i<list_size(list);i++){
        printf("data=%d ",*(int*)(((AvlNode*)list_data(pl))->data));
        printf("hiden=%d ",(((AvlNode*)list_data(pl))->hidden));
        printf("factor=%d ",(((AvlNode*)list_data(pl))->factor));
        printf("\n");
        pl = pl->next;
    }
    printf("\n#########end#############\n");
}







