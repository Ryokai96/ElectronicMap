#include "linkOp.h"

/*
    函数名：create_list
    函数功能：初始化双向链表
    参数：无
    返回值：头结点指针
*/
ln_t listInit()
{
    ln_t head = (ln_t)malloc(sizeof(linkn_t));
    head->next = NULL;
    head->prior = NULL;
    return head;
}

/*
    函数名：insertToList
    函数功能：插入链表
    参数：要插入的位置的前一个节点pnode,要插入的节点n
    返回值：无
*/
void insertToList(ln_t pnode, ln_t n)
{
    ln_t node;
    node = (ln_t)malloc(sizeof(linkn_t));
    if(pnode->next = NULL)
    {
        pnode->next = node;
        node->prior = pnode;
        node->next = NULL;
    }
    else
    {
        node->next = pnode->next;
        node->prior = pnode;
        pnode->next = node;
        pnode->next->prior = node;
    }
}
