/**
 循环列表
 **/


#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

typedef struct Info_{
    int id;
    long phone;
}Info;

void print_list_info(CList *clist);

int main(int argc, const char * argv[]) {
    printf("test clist\n");
    CList *plist;
    plist = (CList *)malloc(sizeof(CList));
    clist_init(plist,free);
    printf("plist->size:%d\n", plist->size );
    
    Info *pi2 = (Info*)malloc(sizeof(Info));
    pi2->id = 123131;
    pi2->phone = 13012131231;
    clist_ins_next(plist,NULL,(void*)pi2);
    
    Info *pi3 = (Info*)malloc(sizeof(Info));
    pi3->id = 5370569;
    pi3->phone = 18611080217;
    clist_ins_next(plist,NULL,(void*)pi3);
    
    Info *pi4 = (Info*)malloc(sizeof(Info));
    pi4->id = 2231313;
    pi4->phone = 18643521217;
    clist_ins_next(plist,NULL,(void*)pi4);
    
    //print list
    printf("plist->size:%d\n", plist->size);
    print_list_info(plist);
    
    void **ppi = (void**)malloc(sizeof(Info));
    clist_rem_next(plist,NULL,ppi);
    //print list
    printf("plist->size:%d\n", plist->size );
    print_list_info(plist);

    clist_destroy(plist);
    printf("plist->size:%d\n", plist->size );
    
    
    
    return 0;
}

//打印一个列表
void print_list_info(CList *clist){
    if(clist_size(clist) == 0){
        printf("empty list\n");
        return;
    }
    
    CListElmt *pl;
    pl = clist_head(clist);
    int i;
    printf("#########start#############\n");
    for(i=0;i<clist_size(clist);i++){
        printf("id=%d,phone=%ld\n",((Info*)clist_data(pl))->id,((Info*)clist_data(pl))->phone);
        pl = pl->next;
    }
    printf("#########end#############\n");
}

