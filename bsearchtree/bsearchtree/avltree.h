//
//  avltree.h
//  bsearchtree
//
//  Created by bikang on 16/9/27.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __bsearchtree__avltree__
#define __bsearchtree__avltree__

#include "tree.h"

#define  AVL_LEFT_HEAVY 1
#define AVL_BLANCED 0
#define  AVL_RIGHT_HEAVY -1

typedef struct AvlNode_{
    void *data;
    int hidden;
    int factor;
}AvlNode;

typedef BitTree BisTree;

void bistree_init(BisTree *tree,int (*compare)(const void *k1,const void *k2),void (*destroy)(void *data));
void bistree_destroy(BisTree *tree);
int bistree_insert(BisTree *tree,const void *data);
int bistree_remove(BisTree *tree,const void *data);
int bistree_lookup(BisTree *tree,void **data);



#define bistree_size(tree) ((tree)->size)

#endif /* defined(__bsearchtree__avltree__) */
