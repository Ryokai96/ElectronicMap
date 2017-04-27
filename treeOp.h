#ifndef TREEOP_H
#define TREEOP_H

#include "header.h"

typedef struct treenode {
    mapd_t data;
    struct treenode* lchild;
    struct treenode* rchild;
}treen_t, *tn_t;

//treeOp.c�к�������
tn_t treeInit();    //��ʼ�����������
void createTree(FILE* fl, tn_t *top);    //�������������
bool insert_to_tree(tn_t *top, mapd_t data); //����ڵ㵽���������
bool tree_num(tn_t top, int* num);  //���������ö���������Ľڵ���
bool expTree(tn_t top, FILE* fl);   //�����������linkid��С�������������д�뵽�������ļ�SortGTBL.dat
bool showTree(tn_t top, FILE* fl);  //�����������linkid��С�������������д�뵽�ı��ļ�sourcelink.txt��
bool print_tree(tn_t top);  //�����������linkid��С�����ڿ���̨��ӡ����������������нڵ�
void destroyTree(tn_t top); //ɾ�����������

//treeseq.c�к�������
void exp_tree_seq_result(tn_t top); //�������Ľ�����������ļ� SortGTBL.dat

//treesearch.c�к�������
tn_t tree_search_linkID(tn_t top, ULONG linkID);    //��linkid��������
void tree_search_dispclass(tn_t top, UINT dispclass, tn_t* ptop);   //��dispclass��������
void tree_search_brunch(tn_t top, UINT brunch, tn_t* ptop); //��brunch��������
void tree_search_roadname(tn_t top, char* roadname, tn_t* ptop); //��roadname��������
void exp_tree_search_result(tn_t top);  //��������Ľ��

#endif
