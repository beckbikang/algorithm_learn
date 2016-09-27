//
//  traverse.c
//  tree
//
//  Created by bikang on 16/9/26.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "traverse.h"

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
//后续遍历
int postorder_tree(const BitTreeNode *node,List *list){
    if(!bitree_is_eob(node)){
        if(!bitree_is_eob(bitree_left(node))){
            if(postorder_tree(bitree_left(node),list) != 0){
                return -1;
            }
        }
        if(!bitree_is_eob(bitree_right(node))){
            if(postorder_tree(bitree_right(node),list) != 0){
                return -1;
            }
        }
        if(list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
    }
    return 0;
}