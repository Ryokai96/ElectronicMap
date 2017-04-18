/*
	文件名：linkOp.c
	描述：用于对单向链表的操作，包括单向链表的初始化、插入
*/

#include "linkOp.h"

/*
    函数名：listInit
    函数功能：初始化链表
    参数：无
    返回值：头结点指针
*/
ln_t listInit()
{
    ln_t head = (ln_t)malloc(sizeof(linkn_t));
    head->next = NULL;
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
        node->next = NULL;
    }
    else
    {
        node->next = pnode->next;
        pnode->next = node;
    }
}

/*
	函数名：unloadNode
	函数功能：将链表指定节点从其当前位置移除，但不释放该节点
	参数：要移除的节点的位置的前一个节点 pnode，要移除的节点 n
	返回值：无
*/
void unloadNode(ln_t pnode, ln_t n)
{
	pnode->next = pnode->next->next;
	n->next = NULL;
}
