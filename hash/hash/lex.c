//
//  lex.c
//  hash
//
//  Created by bikang on 16/9/23.
//  Copyright (c) 2016年 bikang. All rights reserved.
//
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "lex.h"
#include "cntbl.h"
//#include "symbol.h"

typedef struct Symbol_{
    char* lexeme;
    Token token;
}Symbol;

const char* next_token(const char *istream){
    return istream;
}

/**
 链式hash表实现语法分析器
 **/

Token lex(const char *istream,CHTbl *symtbl){
    Token token;
    Symbol *symbol;
    int length,retval,i;
    
    if((symbol = (Symbol *)malloc(sizeof(Symbol)))) return error;
    
    if((symbol->lexeme = next_token(istream)) == NULL){
        free(symbol);
        return  lexit;
    }else{
        symbol->token = digit;
        length = (int)strlen(symbol->lexeme);
        for(i=0;i<length;i++){
            if(!isdigit(symbol->lexeme[i])) symbol->token = other;
        }
        memcpy(&token, &symbol->token,sizeof(Token));
        
        if((retval == chtbl_insert(symtbl, symbol)) == -1){
            free(symbol);
            return error;
        }else if(retval == 1){
            free(symbol);
        }
    }
    return token;
}
