#ifndef TREEOP_H
#define TREEOP_H

#include "header.h"

typedef struct treenode {
    mapd_t data;
    struct treenode* parent;
    struct treenode* lchild;
    struct treenode* rchile;
}treen_t, *tn_t;


tn_t treeInit();    //初始化二叉查找树
void createTree(FILE* fl, tn_t top);    //创建二叉查找树
bool insert_to_tree(tn_t top, mapd_t data); //插入节点到二叉查找树
void tree_num(tn_t top, int* num);  //获得二叉查找树的节点数
void print_tree(tn_t top);  //在控制台打印出二叉查找树的所有节点

#endif
