#ifndef MENU_H
#define MENU_H

#include "header.h"
#include "fileOp.h"
#include "linkOp.h"
#include "treeOp.h"

void primary_menu();    //�������˵�
int readfile_menu();    //��ȡ�ļ��˵�
void select_menu(int n);    //������ѡ������ݽṹ��Ӧ�Ĳ˵�

void linklist_menu();   //����洢��ʽ��Ӧ�˵�
void link_sortSelect(ln_t head, ln_t tail); //����ʽ��ѡ��
void link_searchSelect(ln_t head);  //������ҷ�ʽ��ѡ��������ҽ��

void tree_menu();   //����������洢��ʽ��Ӧ�˵�
void tree_searchSelect(tn_t top);   //����������������������룬������ҽ��

#endif // MENU_H
