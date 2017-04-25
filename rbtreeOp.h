#ifndef RBTREEOP_H
#define RBTREEOP_H

#include "header.h"

typedef enum COLOR {
    red = 1,
    black = 0
}color_e;

//������ڵ�
typedef struct RBTreeNode {
    color_e color;  //�ڵ���ɫ(red��black)
    mapd_t data;    //�ڵ㱣������ݣ���data.linkid��Ϊ��ֵ
    struct RBTreeNode* left;    //����
    struct RBTreeNode* right;   //�Һ���
    struct RBTreeNode* parent;  //���ڵ�
}rbreeenode_t, *rbtn_t;

//��������ڵ�
typedef struct rb_root {
    rbtn_t node;
}rbroot_t, *rbr_t;

//rbtreeOp.c�к���
rbtn_t rbtreeInit();    //��ʼ��������ڵ�
void rbtree_left_rotate(rbtn_t node, rbr_t root);   //�������������ǰ�ڵ���Һ��ӵ����ӳ�Ϊ���Һ��ӣ���ԭ�Һ��ӳ�Ϊ�丸�ڵ�
void rbtree_right_rotate(rbtn_t node, rbr_t root);  //�������������ǰ�ڵ�����ӵ��Һ��ӳ�Ϊ�����ӣ���ԭ���ӳ�Ϊ�丸�ڵ�
void insert_to_rbtree(md_t data, rbr_t root);   //����ڵ㵽�����
void rbtree_insert_fixup(rbtn_t node, rbr_t root);  //������Ĳ�������
void createRBTree(FILE* fl, rbr_t root);    //���������
void expRBTree(rbtn_t node, FILE* fl);  //�����������linkid��С�������������д�뵽�������ļ�SortGTBL.dat
void showRBTree(rbtn_t node, FILE* fl); //�����������linkid��С����Ѻ����������д�뵽�ı��ļ�sourcelink.txt��
void printRBTree(rbtn_t node);  //����������������С�������������̨
void exp_rbtree_seq_result(rbr_t root); //�������Ľ�����������ļ� SortGTBL.dat

#endif // RBTREEOP_H
