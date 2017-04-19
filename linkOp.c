/*
	�ļ�����linkOp.c
	���������ڶԵ�������Ĳ�����������������ĳ�ʼ��������
*/

#include "linkOp.h"

/*
    ��������listInit
    �������ܣ���ʼ������
    ��������
    ����ֵ��ͷ���ָ��
*/
ln_t listInit()
{
    ln_t head = (ln_t)malloc(sizeof(linkn_t));
    head->next = NULL;
    return head;
}

/*
    ��������insertToList
    �������ܣ���������
    ������Ҫ�����λ�õ�ǰһ���ڵ�pnode,Ҫ����Ľڵ�n
    ����ֵ����
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
	��������unloadNode
	�������ܣ�������ָ���ڵ���䵱ǰλ���Ƴ��������ͷŸýڵ�
	������Ҫ�Ƴ��Ľڵ��λ�õ�ǰһ���ڵ� pnode��Ҫ�Ƴ��Ľڵ� n
	����ֵ����
*/
void unloadNode(ln_t pnode, ln_t n)
{
	pnode->next = pnode->next->next;
	n->next = NULL;
}

/*
    ��������link_copy_data
    �������ܣ�����һ���ڵ��data����һ���ڵ��data
    ������Ŀ��ڵ�tag�������ڵ�src
    ����ֵ����
*/
void link_copy_data(ln_t tag, ln_t src)
{
    tag->data = src->data;
    free(tag->data.roadname);   //��free��Ŀ��ڵ��data��roadname��ָ���ڴ�
    tag->data.roadname = (UCHAR *)malloc(sizeof(UCHAR) * src->data.roadnamesize);
    strcpy((char*)tag->data.roadname, (char*)src->data.roadname);
}

/*
    ��������link_swap_node
    �������ܣ����������ڵ��data
    ��������Ҫ����data�������ڵ� fnode �� snode
    ����ֵ����
*/
void link_swap_node(ln_t fnode, ln_t snode)
{
    linkn_t temp;
    link_copy_data(&temp, fnode);
    link_copy_data(fnode, snode);
    link_copy_data(snode, &temp);
}

/*
    ��������link_empty
    �������ܣ��ж������Ƿ�Ϊ��
    ����������ͷ��� head
    ����ֵ��1��ʾ����Ϊ�գ�0��ʾ�ǿ�
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


