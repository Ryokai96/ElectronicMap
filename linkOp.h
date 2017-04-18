#ifndef LINKOP_H
#define LINKOP_H

#include "header.h"

typedef struct linknode {
    mapd_t data;
    struct linknode* next;  //指向下一个节点
    struct linknode* prior; //指向上一个节点
} linkn_t, *ln_t;

ln_t listInit();         //创建双向链表
void insertToList(ln_t pnode, ln_t n);  //插入链表

#endif // LINKOP_H
