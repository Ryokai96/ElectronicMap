/*
	文件名：linkOp.c
    描述：用于对单向链表的操作，包括单向链表的初始化、创建、判空、计算节点总数、输出，节点的插入、移除、复制、交换
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
    memset(head, 0, sizeof(linkn_t));  //清空数据
    mapDataInit(&head->data);   //初始化head->data的值
    head->next = NULL;
    return head;
}

/*
    函数名：createLinklist
    函数功能：创建链表
    参数：需读取文件的文件指针 fl， 链表头结点 head，尾指针 tail
    返回值：无
*/
void createLinklist(FILE* fl, ln_t* head, ln_t* tail)
{
    (*head) = listInit(); //链表初始化
    (*tail) = (*head);

    FILE* fp;   //用于记录文件尾部的位置
    fseek(fl, 0, 2);   //把文件内部指针移动到文件尾部
    fp = (FILE*)ftell(fl);    //记录文件尾部的位置，ftell返回值类型为long，进行强制类型转换避免产生警告
    fseek(fl, 0, 0);   //把文件内部指针移动到文件头部

    ln_t node;  //用于新建节点
    while(fp != (FILE*)ftell(fl)) //当文件内部指针到了文件尾部，则结束循环
    {
        node = (ln_t)malloc(sizeof(linkn_t));
        getMapData(&node->data, fl);
        (*tail)->next = node;
        (*tail) = (*tail)->next;
        (*tail)->next = NULL;
    }

//    int i = 0;
//    int j = 0;
//    for(i = 0; i < 6; i++)
//    {
//        node = (ln_t)malloc(sizeof(linkn_t));
//        getMapData(&node->data, fl);
//        (*tail)->next = node;
//        (*tail) = (*tail)->next;
//        (*tail)->next = NULL;
//        j++;
//    }

    fp = NULL;
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
    copyMapData(&tag->data, &src->data);
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
    mapDataInit(&(temp.data)); //初始化temp的data的值
    temp.next = NULL;

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

/*
    函数名：link_num
    函数功能：返回链表的节点总数(不包括头结点)
    参数：链表头结点 head
    返回值：链表的节点总数(不包括头结点)
*/
int link_num(ln_t head)
{
    if(head->next == NULL)
    {
        return 0;
    }

    int num = 0;
    ln_t node = head->next;
    while(node != NULL)
    {
        num++;
        node = node->next;
    }

    return num;
}

/*
    函数名：expLink
    函数功能：将整张链表输出到二进制文件
    参数：链表头结点 head, 文件指针 fl
    返回值：无
*/
void expLink(ln_t head, FILE* fl)
{
    if(link_empty(head))
    {
        printf("empty linklist, can't export to SortGTBL.dat\n");
        return ;
    }

    ln_t pnode = head->next;
    while (pnode != NULL)
    {
        writeMapData(&pnode->data, fl);
        pnode = pnode->next;
    }
}

/*
    函数名：showLink
    函数功能：将整张链表输出文本文件
    参数：链表头结点 head，文件指针 fl
    返回值：无
*/
void showLink(ln_t head, FILE* fl)
{
    if(link_empty(head))
    {
        printf("empty linklist, can't show to sourcelink.txt\n");
        return ;
    }

    ln_t pnode = head->next;
    while (pnode != NULL)
    {
        printMapData(&pnode->data, fl);
        pnode = pnode->next;
    }
}

/*
    函数名：printLink
    函数功能：将整张链表打印到控制台
    参数：链表头结点 head
    返回值：无
*/
void printLink(ln_t head)
{
    ln_t node = head->next;
    if(node == NULL)
    {
        printf("empty linklist can't print\n");
        return ;
    }
    while(node != NULL)
    {
        printf("#linkid=%ld;", node->data.linkid);
        printf("roadnameflag=%hd;", get_roadnameflag(node->data.node));
        printf("brunch=%hd;", get_brunch(node->data.node));
        printf("dispclass=%hd;", get_dispclass(node->data.node));
        printf("roadname=%s", node->data.roadname);
        printf("\n");
        node = node->next;
    }
}
