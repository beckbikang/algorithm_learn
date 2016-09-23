//
//  match.c
//  hash
//
//  Created by bikang on 16/9/22.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include "match.h"
#include <string.h>

int match_int(const void *k1,const void *k2){
    if(*(int*)k1 == *(int*)k2) {
        return 0;
    }else{
        return -1;
    }
}

int match_chars(const void *k1,const void *k2){
    
    if(strcmp((char*)k1,(char*)k2) == 0){
        return 0;
    }else{
        return -1;
    }
}