//
//  avltree.c
//  bsearchtree
//
//  Created by bikang on 16/9/27.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "avltree.h"

static void destroy_right(BisTree *tree,BitTreeNode *node);

//左边旋转-节点指针
static void rotate_left(BitTreeNode **node)
{
    BitTreeNode *left,*grandchild;
    left = bitree_left(*node);
    //左子树超重
    if((((AvlNode*)bitree_data(left))->factor) == AVL_LEFT_HEAVY){
        //处理Left left超重
        bitree_left(*node) = bitree_right(left);
        bitree_right(left) = *node;
        ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
        ((AvlNode*)bitree_data(left))->factor = AVL_BLANCED;
        *node = left;
    }else{
        //处理left right超重
        grandchild = bitree_right(left);
        bitree_right(left) = bitree_left(grandchild);//step 1
        bitree_left(grandchild) = left;//step 2
        bitree_left(*node) = bitree_right(grandchild);//step 3
        bitree_right(grandchild) = *node;//step4
         
        //调整平衡参数
        switch (((AvlNode*)bitree_data(grandchild))->factor) {
            case AVL_LEFT_HEAVY:
                ((AvlNode*)bitree_data(*node))->factor = AVL_RIGHT_HEAVY;
                ((AvlNode*)bitree_data(left))->factor = AVL_BLANCED;
                break;
            case AVL_BLANCED:
                ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
                ((AvlNode*)bitree_data(left))->factor = AVL_BLANCED;
                break;
            case AVL_RIGHT_HEAVY:
                ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
                ((AvlNode*)bitree_data(left))->factor = AVL_LEFT_HEAVY;
                break;
        }
        ((AvlNode*)bitree_data(grandchild))->factor  = AVL_BLANCED;
        *node = grandchild;
    }
    return;
}


//类似左旋转，只是方向不一样
static void rotate_right(BitTreeNode **node){
    BitTreeNode *right,*grandchild;
    right = bitree_right(*node);
    
    if((((AvlNode*)bitree_data(right))->factor) == AVL_RIGHT_HEAVY){
        //处理RR的情况
        bitree_right(*node) = bitree_left(right);
        bitree_left(right) = *node;
        ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
        ((AvlNode*)bitree_data(right))->factor = AVL_BLANCED;
        *node = right;
    }else{
        grandchild = bitree_left(right);
        bitree_left(right) = bitree_right(grandchild);//step1
        bitree_right(grandchild) = right;//step2
        bitree_right(*node) = bitree_left(grandchild);//step3
        bitree_left(grandchild) = *node;//step4
        
        //调整平衡参数
        switch (((AvlNode*)bitree_data(grandchild))->factor) {
            case AVL_LEFT_HEAVY:
                ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
                ((AvlNode*)bitree_data(right))->factor = AVL_RIGHT_HEAVY;
                break;
            case AVL_BLANCED:
                ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
                ((AvlNode*)bitree_data(right))->factor = AVL_BLANCED;
                break;
            case AVL_RIGHT_HEAVY:
                ((AvlNode*)bitree_data(*node))->factor = AVL_LEFT_HEAVY;
                ((AvlNode*)bitree_data(right))->factor = AVL_BLANCED;
                break;
        }
        
        ((AvlNode*)bitree_data(grandchild))->factor  = AVL_BLANCED;
        *node = grandchild;
    }
    return;
}


static void destroy_left(BisTree *tree, BitTreeNode *node){
    BitTreeNode **position;
    
    if(bitree_size(tree) == 0) return;
    
    if(node == NULL){
        position = &tree->root;
    }else{
        position = &node->left;
    }
    if (*position != NULL) {
        destroy_left(tree, *position);
        destroy_right(tree, *position);
        if(tree->destroy != NULL){
            tree->destroy((((AvlNode*)(*position)->data))->data);
        }
        free((*position)->data);
        free(*position);
        *position = NULL;
        tree->size--;
    }
    
    return;
}


static void destroy_right(BisTree *tree,BitTreeNode *node){
    BitTreeNode **position;
    
    if(bitree_size(tree) == 0) return;
    
    if(node == NULL){
        position = &tree->root;
    }else{
        position = &node->right;
    }
    if (*position != NULL) {
        destroy_left(tree, *position);
        destroy_right(tree, *position);
        if(tree->destroy != NULL){
            tree->destroy((((AvlNode*)(*position)->data))->data);
        }
        free((*position)->data);
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return;
}


//插入数据，也是最关键的部分，每次插入都得平衡
static int insert(BisTree *tree,BitTreeNode **node,const void*data,int *balanced ){
    AvlNode *avl_data;
    int cmpval,retval;
    //printf("*data=%d",*(int*)data);
    if(bitree_is_eob(*node)){
        if((avl_data =(AvlNode *)malloc(sizeof(AvlNode))) == NULL) return -1;
        avl_data->factor = AVL_BLANCED;
        avl_data->hidden = 0;
        avl_data->data = (void*)data;
        return bitree_ins_left(tree, *node, avl_data);
    }else{
        
        cmpval = tree->compare(data,((AvlNode *)(bitree_data(*node)))->data);
        //printf("###node=%d,%d\n",*(int*)(((AvlNode*)bitree_data(*node))->data),cmpval);
        if(cmpval < 0){
            if(bitree_is_eob(bitree_left(*node))){
                if((avl_data =(AvlNode *)malloc(sizeof(AvlNode))) == NULL) return -1;
            
                avl_data->factor = AVL_BLANCED;
                avl_data->hidden = 0;
                avl_data->data = (void*)data;
                if(bitree_ins_left(tree, *node, avl_data) != 0) return -1;
                *balanced = 0;
            }else{
                //继续往左边寻找
                if((retval = insert(tree,&bitree_left(*node),data,balanced)) !=0){
                    return retval;
                }
            }
            //左子树非平衡的
            if(!(*balanced)){
                switch (((AvlNode*)bitree_data(*node))->factor) {
                    case AVL_LEFT_HEAVY:
                        rotate_left(node);
                        *balanced = 1;
                        break;
                    case AVL_BLANCED:
                        //如果左子树平衡，左边会重因为新插入元素
                        ((AvlNode*)bitree_data(*node))->factor = AVL_LEFT_HEAVY;
                        break;
                    case AVL_RIGHT_HEAVY:
                        ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
                        *balanced = 1;
                        break;
                }
            }
        }else if (cmpval > 0){
            if(bitree_is_eob(bitree_right(*node))){
                
                if((avl_data =(AvlNode *)malloc(sizeof(AvlNode))) == NULL) return -1;
                
                avl_data->factor = AVL_BLANCED;
                avl_data->hidden = 0;
                avl_data->data = (void*)data;
                if(bitree_ins_right(tree, *node, avl_data) != 0) return -1;
                *balanced = 0;
            }else{
                if((retval = insert(tree,&bitree_right(*node),data,balanced)) !=0){
                    return retval;
                }
            }
            if(!(*balanced)){
                switch (((AvlNode*)bitree_data(*node))->factor)
                {
                    case AVL_LEFT_HEAVY:
                        ((AvlNode*)bitree_data(*node))->factor = AVL_BLANCED;
                        *balanced = 1;
                        break;
                    case AVL_BLANCED:
                        ((AvlNode*)bitree_data(*node))->factor = AVL_RIGHT_HEAVY;
                        break;
                    case AVL_RIGHT_HEAVY:
                        rotate_right(node);
                        *balanced = 1;
                        break;
                }
            }
        }else{
            //数据已经存在
            if(!((AvlNode*)bitree_data(*node))->hidden){
                return 1;
            }else{
                //插入新的数据
                if(tree->destroy!= NULL){
                    tree->destroy(((AvlNode*)bitree_data(*node))->data);
                }
                ((AvlNode*)bitree_data(*node))->data = (void*)data;
                ((AvlNode*)bitree_data(*node))->hidden = 0;
                *balanced = 1;
            }
        }
    }
    return 0;
}


static int hide(BisTree *tree,BitTreeNode *node,const void *data){
    int cmpval,retval;
    
    if(bitree_is_eob(node)) return -1;
    
    cmpval = tree->compare(data,((AvlNode*)bitree_data(node))->data);
    if(cmpval < 0){
        retval = hide(tree,bitree_left(node),data);
    }else if(cmpval > 0){
        retval = hide(tree,bitree_right(node),data);
    }else{
        ((AvlNode*)bitree_data(node))->hidden = 1;
        retval = 0;
    }
    return retval;
}

static int lookup(BisTree *tree,BitTreeNode *node,const void **data){
    int cmpval,retval;
    if(bitree_is_eob(node)) return -1;
    cmpval = tree->compare(*data,((AvlNode*)bitree_data(node))->data);
    //printf("%d,%d,cmp=%d\n",**(int**)data,*(int*)((AvlNode*)bitree_data(node))->data,cmpval);
    if(cmpval < 0){
        retval = lookup(tree,bitree_left(node),data);
    }else if(cmpval > 0){
        retval = lookup(tree,bitree_right(node),data);
    }else{
        
        if(!((AvlNode*)bitree_data(node))->hidden){
            *data =((AvlNode*)bitree_data(node))->data;
            retval = 0;
        }else{
            return -1;
        }
    }
    return retval;
}

void bistree_init(BisTree *tree,int (*compare)(const void *k1,const void *k2),void (*destroy)(void *data)){
    bitree_init(tree, destroy);
    tree->compare = compare;
    return;
}
void bistree_destroy(BisTree *tree){
    destroy_left(tree, NULL);
    memset(tree,0,sizeof(BitTree));
    return ;
}
int bistree_insert(BisTree *tree,const void *data){
    int balance = 0;
    return insert(tree,&bitree_root(tree),data,&balance);
}
int bistree_remove(BisTree *tree,const void *data){
    return hide(tree,bitree_root(tree),data);
}
int bistree_lookup(BisTree *tree,void **data){
    return lookup(tree, bitree_root(tree),(const void**)data);
}





























