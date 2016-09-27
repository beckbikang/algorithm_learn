//
//  main.c
//  tree
//
//  Created by bikang on 16/9/26.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "traverse.h"

void ttree();
void print_list_info(List *list);

int main(int argc, const char * argv[]) {
    printf("test tree:\n");
    ttree();
    return 0;
}
void ttree(){
    BitTree *tree = (BitTree*)malloc(sizeof(BitTree));
    bitree_init(tree, NULL);
    
    //插入
    int i1 = 1;int *pi1 = &i1;
    int i2 = 2;int *pi2 = &i2;
    int i3 = 3;int *pi3 = &i3;
    int i4 = 4;int *pi4 = &i4;
    int i5 = 5;int *pi5 = &i5;
    bitree_ins_left(tree, NULL, pi1);
    bitree_ins_left(tree, bitree_root(tree), pi2);
    bitree_ins_right(tree,bitree_root(tree), pi3);
    bitree_ins_left(tree, bitree_root(tree)->left, pi4);
    bitree_ins_right(tree, bitree_root(tree)->right, pi5);
    printf("t1->size=%d\n",bitree_size(tree));
    //删除
    bitree_rm_left(tree,bitree_root(tree)->left);
    bitree_rm_right(tree,bitree_root(tree)->right);
    printf("t1->size=%d\n",bitree_size(tree));
    
    //合并
    BitTree *tree2 = (BitTree*)malloc(sizeof(BitTree));
    bitree_init(tree2, NULL);
    int i7 = 7;int *pi7 = &i7;
    int i8 = 8;int *pi8 = &i8;
    bitree_ins_left(tree2, NULL, pi7);
    
    BitTree *merge = (BitTree*)malloc(sizeof(BitTree));
    bitree_merge(merge, tree, tree2, pi8);
    printf("t1->size=%d\n",bitree_size(merge));
    
    

    
    //遍历
    List *list = (List *)malloc(sizeof(List));
    //preorder_tree(bitree_root(merge),list);
    //inorder_tree(bitree_root(merge), list);
    postorder_tree(bitree_root(merge), list);
    print_list_info(list);
    
    //摧毁
    bitree_destroy(merge);

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
    printf("#########start#############\n");
    for(i=0;i<list_size(list);i++){
        printf("data=%d,",*(int*)list_data(pl));
        pl = pl->next;
    }
    printf("#########end#############\n");
}