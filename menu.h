#ifndef MENU_H
#define MENU_H

#include "header.h"
#include "fileOp.h"
#include "linkOp.h"
#include "treeOp.h"
#include "rbtreeOp.h"

void primary_menu();    //程序主菜单
int readfile_menu();    //读取文件菜单
void select_menu(int n);    //进入与选择的数据结构对应的菜单

void linklist_menu();   //链表存储格式对应菜单
void link_sortSelect(ln_t head, ln_t tail); //排序方式的选择
void link_searchSelect(ln_t head);  //链表查找方式的选择，输出查找结果
void link_deleteSelect(ln_t head);  //链表节点删除的菜单
void link_insertMenu(ln_t *tail); //链表节点插入的菜单

void tree_menu();   //二叉查找树存储格式对应菜单
void tree_searchSelect(tn_t top);   //二叉查找树查找条件的输入，输出查找结果

void rbtree_menu(); //红黑树存储格式对应菜单

#endif // MENU_H
