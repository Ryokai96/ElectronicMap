/*
	�ļ�����linkOp.c
    ���������ڶԵ�������Ĳ�����������������ĳ�ʼ�����������пա�����ڵ�������������ڵ�Ĳ��롢�Ƴ������ơ�����
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
    memset(head, 0, sizeof(linkn_t));  //�������
    mapDataInit(&head->data);   //��ʼ��head->data��ֵ
    head->next = NULL;
    return head;
}

/*
    ��������createLinklist
    �������ܣ���������
    ���������ȡ�ļ����ļ�ָ�� fl�� ����ͷ��� head��βָ�� tail
    ����ֵ����
*/
void createLinklist(FILE* fl, ln_t* head, ln_t* tail)
{
    (*head) = listInit(); //�����ʼ��
    (*tail) = (*head);

    FILE* fp;   //���ڼ�¼�ļ�β����λ��
    fseek(fl, 0, 2);   //���ļ��ڲ�ָ���ƶ����ļ�β��
    fp = (FILE*)ftell(fl);    //��¼�ļ�β����λ�ã�ftell����ֵ����Ϊlong������ǿ������ת�������������
    fseek(fl, 0, 0);   //���ļ��ڲ�ָ���ƶ����ļ�ͷ��

    ln_t node;  //�����½��ڵ�
    while(fp != (FILE*)ftell(fl)) //���ļ��ڲ�ָ�뵽���ļ�β���������ѭ��
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
    copyMapData(&tag->data, &src->data);
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
    mapDataInit(&(temp.data)); //��ʼ��temp��data��ֵ
    temp.next = NULL;

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

/*
    ��������link_num
    �������ܣ���������Ľڵ�����(������ͷ���)
    ����������ͷ��� head
    ����ֵ������Ľڵ�����(������ͷ���)
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
    ��������expLink
    �������ܣ�����������������������ļ�
    ����������ͷ��� head, �ļ�ָ�� fl
    ����ֵ����
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
    ��������showLink
    �������ܣ���������������ı��ļ�
    ����������ͷ��� head���ļ�ָ�� fl
    ����ֵ����
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
    ��������printLink
    �������ܣ������������ӡ������̨
    ����������ͷ��� head
    ����ֵ����
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
