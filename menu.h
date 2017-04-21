#ifndef MENU_H
#define MENU_H

#include "header.h"
#include "linkOp.h"
#include "fileOp.h"

void primary_menu();    //程序主菜单
int readfile_menu();    //读取文件菜单
void select_menu(int n);    //进入与选择的数据结构对应的菜单
void linklist_menu();   //链表存储格式对应菜单
void link_sortSelect(ln_t head, ln_t tail); //排序方式的选择
void link_searchSelect(ln_t head);  //链表排序方式的选择，输出排序结果

#endif // MENU_H
