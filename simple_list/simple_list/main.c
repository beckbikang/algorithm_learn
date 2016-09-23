#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ONE_MB (1024 * 1024)

#include "list.h"

typedef struct Info_{
    int id;
    long phone;
}Info;

//打印一个列表
void print_list_int(List *list);
void print_list_info(List *list);
void show_memory();
void testFree();


void tlist();
void tlistArr();
void tlistArrPoint();

int main(int argc, char const *argv[])
{
    //tlistArr();
    //tlistArrPoint();
    tlist();
    return 0;
}
void tlistArrPoint(){
    List *listArr[3];
    List *plist;
    listArr[0] = (List *)malloc(sizeof(List));
    plist = listArr[0];
    list_init(plist,free);
    Info *pi2 = (Info*)malloc(sizeof(Info));
    pi2->id = 123131;
    pi2->phone = 13012131231;
    list_ins_next(plist,NULL,(void*)pi2);
    printf("plist->size:%d\n", plist->size);
    print_list_info(plist);
}

//测试list array
void tlistArr(){
    
    List listArr[3];
    List *plist;
    plist = &listArr[0];
    list_init(plist,free);
    Info *pi2 = (Info*)malloc(sizeof(Info));
    pi2->id = 123131;
    pi2->phone = 13012131231;
    list_ins_next(plist,NULL,(void*)pi2);
    printf("plist->size:%d\n", plist->size);
    print_list_info(plist);
    
}

void tlist(){
    printf("test list\n");
    List *plist;
    plist = (List *)malloc(sizeof(List));
    list_init(plist,free);
    printf("plist->size:%d\n", plist->size );
    
    
    Info *pi2 = (Info*)malloc(sizeof(Info));
    pi2->id = 123131;
    pi2->phone = 13012131231;
    list_ins_next(plist,NULL,(void*)pi2);
    
    Info *pi3 = (Info*)malloc(sizeof(Info));
    pi3->id = 5370569;
    pi3->phone = 18611080217;
    list_ins_next(plist,NULL,(void*)pi3);
    
    Info *pi4 = (Info*)malloc(sizeof(Info));
    pi4->id = 2231313;
    pi4->phone = 18643521217;
    list_ins_next(plist,NULL,(void*)pi4);
    
    //print list
    printf("plist->size:%d\n", plist->size);
    print_list_info(plist);
    
    //delete
    void **ppi = (void**)malloc(sizeof(Info));
    list_rem_next(plist,NULL,ppi);
    //print list
    printf("plist->size:%d\n", plist->size );
    print_list_info(plist);
    //show_memory();
    //destroy
    list_destroy(plist);
    //show_memory();
    //testFree();
}

//打印一个列表
void print_list_info(List *list){
    if(list_size(list) == 0){
        printf("empty list\n");
        return;
    }
    
    ListElmt *pl;
    pl = list_head(list);
    int i;
    printf("#########start#############\n");
    for(i=0;i<list_size(list);i++){
        printf("id=%d,phone=%ld\n",((Info*)list_data(pl))->id,((Info*)list_data(pl))->phone);
        pl = pl->next;
    }
    printf("#########end#############\n");
}

void testFree(){
    struct stu
    {
        int num;
        char *name;
        char sex;
        float score;
    }  *ps;
    
    ps=(struct stu*)malloc(sizeof(struct stu));
    ps->num=102;
    ps->name="Zhang ping";
    ps->sex='M';
    ps->score=62.5;
    printf("Number=%d Name=%s ",ps->num,ps->name);
    printf("sex=%c Score=%f ",ps->sex,ps->score);
    free(ps);
}


//打印一个列表
void print_list_int(List *list){
    if(list_size(list) == 0){
        printf("empty list\n");
        return;
    }
    
    ListElmt *pl;
    pl = list_head(list);
    int i;
    for(i=0;i<list_size(list);i++){
        printf("%d=>%d,",i+1,*(int*)pl->data);
        pl = pl->next;
    }
    printf("\n");
}