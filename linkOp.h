#ifndef LINKOP_H
#define LINKOP_H

#include "header.h"

typedef struct linknode {
    mapd_t data;
    struct linknode* next;
} linkn_t, *ln_t;

ln_t listInit();    //��ʼ������
void insertToList(ln_t pnode, ln_t n);          //��������
void unloadNode(ln_t pnode, ln_t n);            //������ָ���ڵ���䵱ǰλ���Ƴ��������ͷŸýڵ�
void link_copy_data(ln_t tag, ln_t src);        //����һ���ڵ��data����һ���ڵ��data
void link_swap_node(ln_t fnode, ln_t snode);    //���������ڵ��data
int link_empty(ln_t head);  //�ж������Ƿ�Ϊ��

ln_t link_insert_sort(ln_t head);	//��������Ĳ�������(��С����)
ln_t link_bubble_sort(ln_t head);   //���������ð������(��С����)
ln_t link_select_sort(ln_t head);   //���������ѡ������(��С����)
ln_t link_getComVal(ln_t head, ln_t tail);  //������ڿ�������Ļ�׼��λ��
void link_fast_sort(ln_t head, ln_t tail);  //��������Ŀ�������(��С����)

#endif // LINKOP_H
