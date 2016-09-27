//
//  tree.c
//  tree
//
//  Created by bikang on 16/9/26.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>
#include <string.h>

void bitree_init(BitTree *tree,void (*destroy)(void *data)){
    tree->size = 0;
    tree->destroy = destroy;
    tree->root = NULL;
    return;
}
void bitree_destroy(BitTree *tree){
    bitree_rm_left(tree, NULL);
    memset(tree, 0, sizeof(BitTree));
    return;
}
//在node的左边插入数据,确定在什么地方插入数据
int bitree_ins_left(BitTree *tree,BitTreeNode *node,const void*data){
    BitTreeNode *new_node,**position;
    if(node == NULL){
        if(bitree_size(tree) > 0) return -1;
        position = &(tree->root);
    }else{
        if(bitree_left(node) != NULL) return -1;
        position = &node->left;
    }
    
    if((new_node = (BitTreeNode *)malloc(sizeof(BitTreeNode))) == NULL)return -1;
    new_node->data = (void*)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;
    tree->size++;
    return 0;
}
int bitree_ins_right(BitTree *tree,BitTreeNode *node,const void*data){
    BitTreeNode *new_node,**position;
    if(node == NULL){
        if(bitree_size(tree) > 0) return -1;
        position = &(tree->root);
    }else{
        if(bitree_right(node) != NULL) return -1;
        position = &node->right;
    }
    
    if((new_node = (BitTreeNode *)malloc(sizeof(BitTreeNode))) == NULL)return -1;
    new_node->data = (void*)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;
    tree->size++;
    return 0;
}
//删除元素node的左边的树，如果node为空，删除整个树
void bitree_rm_left(BitTree *tree,BitTreeNode *node){
    BitTreeNode **position;
    if(bitree_size(tree) == 0) return;
    
    if(node == NULL){
        position = &tree->root;
    }else{
        position = &node->left;
    }
    if(*position != NULL){
        bitree_rm_left(tree,*position);
        bitree_rm_right(tree,*position);
        if(tree->destroy != NULL){
            tree->destroy((*position)->data);
        }
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return;
}
void bitree_rm_right(BitTree *tree,BitTreeNode *node){
    BitTreeNode **position;
    if(bitree_size(tree) == 0) return;
    
    if(node == NULL){
        position = &tree->root;
    }else{
        position = &node->right;
    }
    if(*position != NULL){
        bitree_rm_left(tree,*position);
        bitree_rm_right(tree,*position);
        if(tree->destroy != NULL){
            tree->destroy((*position)->data);
        }
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return;
}
//树的合并
int bitree_merge(BitTree *merge,BitTree *left,BitTree *right,const void *data){
    bitree_init(merge,left->destroy);
    if(bitree_ins_left(merge, NULL, data) != 0){
        bitree_destroy(merge);
        return -1;
    }
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right = bitree_root(right);
    merge->size = left->size+ right->size;
    
    //合并后禁止通过其他方式访问
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;
    
    return 0;
}








