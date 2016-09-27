//
//  traverse.h
//  tree
//
//  Created by bikang on 16/9/26.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __tree__traverse__
#define __tree__traverse__

#include <stdio.h>
#include "list.h"
#include "tree.h"

int preorder_tree(const BitTreeNode *node,List *list);
int inorder_tree(const BitTreeNode *node,List *list);
int postorder_tree(const BitTreeNode *node,List *list);




#endif /* defined(__tree__traverse__) */
