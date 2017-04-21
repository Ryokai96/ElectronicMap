/*
    文件名：linksearch.c
    描述：用于对单向链表的查找操作，可对linkid、dispclass、brunch、roadname进行查找，对查找结果进行相应操作的函数也包括在内
*/

#include "linkOp.h"

/*
    函数名：link_search_linkID
    函数功能：按linkid查找数据，并将找到的数据保存到查找结果链表中
    参数：查找数据的链表的头结点 head，要查找的linkid linkID
    返回值：查找结果链表的头结点
*/
ln_t link_search_linkID(ln_t head, UINT linkID)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //用于保存找到的节点
    ln_t ptail = phead; //ptail用于保存phead链表的末尾的节点
    ln_t pnode = NULL;  //pnode用于新生成节点

    while(node != NULL)
    {
        if(node->data.linkid == linkID)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //将node的data拷贝给pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        printf("对查找到的结果快速排序中...\n");
        link_fast_sort(phead->next, ptail);   //对找到的节点进行快速排序
        printf("排序完成\n");
    }

    return phead;
}

/*
    函数名：link_search_dispclass
    函数功能：按交叉link列表示class番号查找数据，并将找到的数据保存到查找结果链表中
    参数：查找数据的链表的头结点 head，要查找的交叉link列表示class番号 dispclass
    返回值：查找结果链表的头结点
*/
ln_t link_search_dispclass(ln_t head, UINT dispclass)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //用于保存找到的节点
    ln_t ptail = phead; //ptail用于保存phead链表的末尾的节点
    ln_t pnode = NULL;  //pnode用于新生成节点

    while(node != NULL)
    {
        if(get_dispclass(node->data.node) == dispclass)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //将node的data拷贝给pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        printf("对查找到的结果快速排序中...\n");
        link_fast_sort(phead->next, ptail);   //对找到的节点进行快速排序
        printf("排序完成\n");
    }

    return phead;
}

/*
    函数名：link_search_linkID
    函数功能：按岔路数brunch查找数据，并将找到的数据保存到查找结果链表中
    参数：查找数据的链表的头结点 head，要查找的岔路数 brunch
    返回值：查找结果链表的头结点
*/
ln_t link_search_brunch(ln_t head, UINT brunch)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //用于保存找到的节点
    ln_t ptail = phead; //ptail用于保存phead链表的末尾的节点
    ln_t pnode = NULL;  //pnode用于新生成节点

    while(node != NULL)
    {
        if(get_brunch(node->data.node) == brunch)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //将node的data拷贝给pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        printf("对查找到的结果快速排序中...\n");
        link_fast_sort(phead->next, ptail);   //对找到的节点进行快速排序
        printf("排序完成\n");
    }

    return phead;
}

/*
    函数名：link_search_roadname
    函数功能：按道路名称查找数据，并将找到的数据保存到查找结果链表中
    参数：查找数据的链表的头结点 head，要查找的道路名称 roadname
    返回值：查找结果链表的头结点
*/
ln_t link_search_roadname(ln_t head, char* roadname)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //用于保存找到的节点
    ln_t ptail = phead; //ptail用于保存phead链表的末尾的节点
    ln_t pnode = NULL;  //pnode用于新生成节点

    while(node != NULL)
    {
        if(strcmp((char*)(node->data.roadname), roadname) == 0)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //将node的data拷贝给pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        printf("对查找到的结果快速排序中...\n");
        link_fast_sort(phead->next, ptail);   //对找到的节点进行快速排序
        printf("排序完成\n");
    }

    return phead;
}

/*
    函数名：exp_search_result
    函数功能：输出检索的结果
    参数：查找结果链表的头结点 head
    返回值：无
*/
void exp_search_result(ln_t head)
{
    if(link_num(head) == 0)
    {
        printf("the data is non-existent\n");
        return ;
    }
    else if(link_num(head) <= 5)
    {
        printLink(head);
    }
    else
    {
        FILE* fl;
        char fileNameLen[4] = "";   //文件名形式：searchresult001.txt
        sprintf(fileNameLen, "%03d", ++NFILE);  //NFILE记录创建了几次searchresult.txt
        char filename[20] = "searchresult"; //文件名
        strcat(filename, fileNameLen);
        strcat(filename, ".txt");
        char* filePath = (char*)malloc(strlen(FILE_PATH) + strlen(filename) + 1);   //文件路径
        memset(filePath, 0, strlen(FILE_PATH) + strlen(filename) + 1);  //清空字符串
        strcat(filePath, FILE_PATH);
        strcat(filePath, filename);

        printf("***************************************************************************\n");
        printf("\b\b结果大于5条，将其转存到文本文件%s\n", filename);
        printf("***************************************************************************\n");

        if((fl = fopen(filePath,"wt+")) == NULL)
        {
            printf("searchresult.txt open error!\n");
            exit(1);
        }
        showLink(head, fl);
        free(filePath);
        fclose(fl);
        fl = NULL;
    }
}
