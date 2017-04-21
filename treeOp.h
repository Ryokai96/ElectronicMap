#ifndef TREEOP_H
#define TREEOP_H

#include "header.h"

typedef struct treenode {
    mapd_t data;
    struct treenode* parent;
    struct treenode* lchild;
    struct treenode* rchile;
}treen_t, *tn_t;


tn_t treeInit();    //��ʼ�����������
void createTree(FILE* fl, tn_t top);    //�������������
bool insert_to_tree(tn_t top, mapd_t data); //����ڵ㵽���������
void tree_num(tn_t top, int* num);  //��ö���������Ľڵ���

#endif
