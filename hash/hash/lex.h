//
//  lex.h
//  hash
//
//  Created by bikang on 16/9/23.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#ifndef __hash__lex__
#define __hash__lex__

#include "cntbl.h"

typedef enum Token_{lexit,error,digit,other}Token;

Token lex(const char *istream,CHTbl *symtbl);

#endif /* defined(__hash__lex__) */
