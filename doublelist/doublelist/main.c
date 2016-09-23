#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ONE_MB (1024 * 1024)

#include "double_list.h"

typedef struct Info_{
    int id;
    long phone;
}Info;

//打印一个列表
void print_list_int(DList *list);
void print_list_info(DList *list);
void testFree();

int main(int argc, const char * argv[]) {
    DList *pdlist;
    pdlist = (DList *)malloc(sizeof(DList));
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
    list_ins_pre(pdlist,dlist_tail(pdlist),(void*)pi3);
    
    Info *pi4 = (Info*)malloc(sizeof(Info));
    pi4->id = 2231313;
    pi4->phone = 18643521217;
    list_ins_next(pdlist,dlist_tail(pdlist),(void*)pi4);
    
    printf("pdlist->size:%d\n", pdlist->size );
    print_list_info(pdlist);
    
    //delete
    void **ppi = (void**)malloc(sizeof(Info));
    list_rem(pdlist, dlist_tail(pdlist), ppi);
    print_list_info(pdlist);
    
    //destroy
    list_destroy(pdlist);
    return 0;
}
void print_list_info(DList *list){
    if(dlist_size(list) == 0){
        printf("empty list\n");
        return;
    }
    DListElmt *pl;
    pl = dlist_head(list);
    int i;
    printf("#########start#############\n");
    for(i=0;i<dlist_size(list);i++){
        printf("id=%d,phone=%ld\n",((Info*)dlist_data(pl))->id,((Info*)dlist_data(pl))->phone);
        pl = pl->next;
    }
    printf("#########end#############\n");
}
