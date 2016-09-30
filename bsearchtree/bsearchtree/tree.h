//
//  tree.h
//  tree
//
//  Created by bikang on 16/9/26.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __tree__tree__
#define __tree__tree__
#include <stdlib.h>
//#include <stdio.h>

typedef struct BitTreeNode_{
    void *data;
    struct BitTreeNode_ *left;
    struct BitTreeNode_ *right;
}BitTreeNode;

typedef struct BitTree_{
    int size;
    int (*compare)(const void *k1,const void *k2);
    void (*destroy)(void *data);
    BitTreeNode *root;
}BitTree;

void bitree_init(BitTree *tree,void (*destroy)(void *data));
void bitree_destroy(BitTree *tree);
//左边插入数据
int bitree_ins_left(BitTree *tree,BitTreeNode *node,const void*data);
//右边插入数据
int bitree_ins_right(BitTree *tree,BitTreeNode *node,const void*data);
//删除左树
void bitree_rm_left(BitTree *tree,BitTreeNode *node);
//删除右树
void bitree_rm_right(BitTree *tree,BitTreeNode *node);
//树合并,以data为root节点
int bitree_merge(BitTree *merge,BitTree *left,BitTree *right,const void *data);

#define bitree_size(tree) ((tree)->size)
#define bitree_root(tree) ((tree)->root)
#define bitree_is_eob(node) ((node) == NULL)

#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
#define bitree_data(node) ((node)->data)
#define bitree_left(node) ((node)->left)
#define bitree_right(node) ((node)->right)

#endif /* defined(__tree__tree__) */
