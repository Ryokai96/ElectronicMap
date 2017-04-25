#ifndef MENU_H
#define MENU_H

#include "header.h"
#include "fileOp.h"
#include "linkOp.h"
#include "treeOp.h"
#include "rbtreeOp.h"

void primary_menu();    //�������˵�
int readfile_menu();    //��ȡ�ļ��˵�
void select_menu(int n);    //������ѡ������ݽṹ��Ӧ�Ĳ˵�

void linklist_menu();   //����洢��ʽ��Ӧ�˵�
void link_sortSelect(ln_t head, ln_t tail); //����ʽ��ѡ��
void link_searchSelect(ln_t head);  //������ҷ�ʽ��ѡ��������ҽ��
void link_deleteSelect(ln_t head);  //����ڵ�ɾ���Ĳ˵�
void link_insertMenu(ln_t *tail); //����ڵ����Ĳ˵�

void tree_menu();   //����������洢��ʽ��Ӧ�˵�
void tree_searchSelect(tn_t top);   //����������������������룬������ҽ��

void rbtree_menu(); //������洢��ʽ��Ӧ�˵�

#endif // MENU_H
