#ifndef MENU_H
#define MENU_H

#include "header.h"
#include "linkOp.h"
#include "fileOp.h"

void primary_menu();    //�������˵�
int readfile_menu();    //��ȡ�ļ��˵�
void select_menu(int n);    //������ѡ������ݽṹ��Ӧ�Ĳ˵�
void linklist_menu();   //����洢��ʽ��Ӧ�˵�
void link_sortSelect(ln_t head, ln_t tail); //����ʽ��ѡ��
void link_searchSelect(ln_t head);  //��������ʽ��ѡ�����������

#endif // MENU_H
