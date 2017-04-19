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
    if(pnode->next == NULL)
    {
        pnode->next = n;
        n->next = NULL;
    }
    else
    {
        n->next = pnode->next;
        pnode->next = n;
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

/*
    函数名：link_copy_data
    函数功能：复制一个节点的data到另一个节点的data
    参数：目标节点tag，拷贝节点src
    返回值：无
*/
void link_copy_data(ln_t tag, ln_t src)
{
    tag->data = src->data;
    free(tag->data.roadname);   //先free掉目标节点的data中roadname所指向内存
    tag->data.roadname = (UCHAR *)malloc(sizeof(UCHAR) * src->data.roadnamesize);
    strcpy((char*)tag->data.roadname, (char*)src->data.roadname);
}

/*
    函数名：link_swap_node
    函数功能：交换两个节点的data
    参数：需要交换data的两个节点 fnode 和 snode
    返回值：无
*/
void link_swap_node(ln_t fnode, ln_t snode)
{
    linkn_t temp;
    link_copy_data(&temp, fnode);
    link_copy_data(fnode, snode);
    link_copy_data(snode, &temp);
}

/*
    函数名：link_empty
    函数功能：判读链表是否为空
    参数：链表头结点 head
    返回值：1表示链表为空，0表示非空
*/
int link_empty(ln_t head)
{
    if(head == NULL)
    {
        printf("link do not init\n");
        return 1;
    }
    else if(head->next == NULL)
    {
        printf("empty link");
        return 1;
    }
    else
    {
        return 0;
    }
}


