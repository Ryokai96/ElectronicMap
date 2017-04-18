#ifndef LINKOP_H
#define LINKOP_H

#include "header.h"

typedef struct linknode {
    mapd_t data;
    struct linknode* next;
} linkn_t, *ln_t;

ln_t listInit();         //初始化链表
void insertToList(ln_t pnode, ln_t n);  //插入链表
void unloadNode(ln_t pnode, ln_t n);	//将链表指定节点从其当前位置移除，但不释放该节点

ln_t insert_sort(ln_t head);	//单向链表的插入排序(从小到大)

#endif // LINKOP_H
