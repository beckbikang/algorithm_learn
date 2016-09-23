//
//  main.c
//  cycle_doublelist
//
//  Created by bikang on 16/9/1.
//  Copyright (c) 2016年 bikang. All rights reserved.
//

#include <stdio.h>

#include "c_double_list.h"

typedef struct Info_{
    int id;
    long phone;
}Info;
void print_list_info(CDList *list);


int main(int argc, const char * argv[]) {
    CDList *pdlist;
    pdlist = (CDList *)malloc(sizeof(CDList));
    list_init(pdlist,free);
    printf("pdlist->size:%d\n", pdlist->size );
    
    //insert
    Info *pi2 = (Info*)malloc(sizeof(Info));
    pi2->id = 123131;
    pi2->phone = 13012131231;
    list_ins_next(pdlist,NULL,(void*)pi2);
   
    Info *pi3 = (Info*)malloc(sizeof(Info));
    pi3->id = 5370569;
    pi3->phone = 18611080217;
    list_ins_pre(pdlist,pdlist->head,(void*)pi3);
    
    Info *pi4 = (Info*)malloc(sizeof(Info));
    pi4->id = 2231313;
    pi4->phone = 18643521217;
    list_ins_next(pdlist,cdlist_head(pdlist),(void*)pi4);
    
    printf("pdlist->size:%d\n", pdlist->size );
    print_list_info(pdlist);
    
    //delete
    void **ppi = (void**)malloc(sizeof(Info));
    list_rem(pdlist, cdlist_head(pdlist), ppi);
    print_list_info(pdlist);
    
    list_destroy(pdlist);
    printf("pdlist->size:%d\n", pdlist->size );
    
    
    return 0;
}


void print_list_info(CDList *list){
    if(cdlist_size(list) == 0){
        printf("empty list\n");
        return;
    }
    CDListElmt *pl;
    pl = cdlist_head(list);
    int i;
    printf("#########start#############\n");
    for(i=0;i<cdlist_size(list);i++){
        printf("id=%d,phone=%ld\n",((Info*)cdlist_data(pl))->id,((Info*)cdlist_data(pl))->phone);
        pl = pl->next;
    }
    printf("#########end#############\n");
}
