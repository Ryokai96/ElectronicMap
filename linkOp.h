#ifndef LINKOP_H
#define LINKOP_H

#include "header.h"

typedef struct linknode {
    mapd_t data;
    struct linknode* next;
} linkn_t, *ln_t;

ln_t listInit();    //初始化链表
void insertToList(ln_t pnode, ln_t n);          //插入链表
void unloadNode(ln_t pnode, ln_t n);            //将链表指定节点从其当前位置移除，但不释放该节点
void link_copy_data(ln_t tag, ln_t src);        //复制一个节点的data到另一个节点的data
void link_swap_node(ln_t fnode, ln_t snode);    //交换两个节点的data
int link_empty(ln_t head);  //判读链表是否为空

ln_t link_insert_sort(ln_t head);	//单向链表的插入排序(从小到大)
ln_t link_bubble_sort(ln_t head);   //单向链表的冒泡排序(从小到大)
ln_t link_select_sort(ln_t head);   //单向链表的选择排序(从小到大)
ln_t link_getComVal(ln_t head, ln_t tail);  //获得用于快速排序的基准数位置
void link_fast_sort(ln_t head, ln_t tail);  //单向链表的快速排序(从小到大)

#endif // LINKOP_H
