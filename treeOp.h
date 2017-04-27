#ifndef TREEOP_H
#define TREEOP_H

#include "header.h"

typedef struct treenode {
    mapd_t data;
    struct treenode* lchild;
    struct treenode* rchild;
}treen_t, *tn_t;

//treeOp.c中函数声明
tn_t treeInit();    //初始化二叉查找树
void createTree(FILE* fl, tn_t *top);    //创建二叉查找树
bool insert_to_tree(tn_t *top, mapd_t data); //插入节点到二叉查找树
bool tree_num(tn_t top, int* num);  //先序遍历获得二叉查找树的节点数
bool expTree(tn_t top, FILE* fl);   //中序遍历，按linkid从小到大把树的内容写入到二进制文件SortGTBL.dat
bool showTree(tn_t top, FILE* fl);  //中序遍历，按linkid从小到大把树的内容写入到文本文件sourcelink.txt中
bool print_tree(tn_t top);  //中序遍历，按linkid从小到大在控制台打印出二叉查找树的所有节点
void destroyTree(tn_t top); //删除二叉查找树

//treeseq.c中函数声明
void exp_tree_seq_result(tn_t top); //输出排序的结果到二进制文件 SortGTBL.dat

//treesearch.c中函数声明
tn_t tree_search_linkID(tn_t top, ULONG linkID);    //按linkid查找数据
void tree_search_dispclass(tn_t top, UINT dispclass, tn_t* ptop);   //按dispclass查找数据
void tree_search_brunch(tn_t top, UINT brunch, tn_t* ptop); //按brunch查找数据
void tree_search_roadname(tn_t top, char* roadname, tn_t* ptop); //按roadname查找数据
void exp_tree_search_result(tn_t top);  //输出检索的结果

#endif
