#ifndef RBTREEOP_H
#define RBTREEOP_H

#include "header.h"

typedef enum COLOR {
    red = 1,
    black = 0
}color_e;

//红黑树节点
typedef struct RBTreeNode {
    color_e color;  //节点颜色(red或black)
    mapd_t data;    //节点保存的内容，以data.linkid作为键值
    struct RBTreeNode* left;    //左孩子
    struct RBTreeNode* right;   //右孩子
    struct RBTreeNode* parent;  //父节点
}rbreeenode_t, *rbtn_t;

//红黑树根节点
typedef struct rb_root {
    rbtn_t node;
}rbroot_t, *rbr_t;

//rbtreeOp.c中函数
rbtn_t rbtreeInit();    //初始化红黑树节点
void rbtree_left_rotate(rbtn_t node, rbr_t root);   //红黑树左旋，当前节点的右孩子的左孩子成为其右孩子，其原右孩子成为其父节点
void rbtree_right_rotate(rbtn_t node, rbr_t root);  //红黑树右旋，当前节点的左孩子的右孩子成为其左孩子，其原左孩子成为其父节点
void insert_to_rbtree(md_t data, rbr_t root);   //插入节点到红黑树
void rbtree_insert_fixup(rbtn_t node, rbr_t root);  //红黑树的插入修正
void createRBTree(FILE* fl, rbr_t root);    //创建红黑树
void expRBTree(rbtn_t node, FILE* fl);  //中序遍历，按linkid从小到大把树的内容写入到二进制文件SortGTBL.dat
void showRBTree(rbtn_t node, FILE* fl); //中序遍历，按linkid从小到大把红黑树的内容写入到文本文件sourcelink.txt中
void printRBTree(rbtn_t node);  //中序遍历红黑树，从小到大输出到控制台
void exp_rbtree_seq_result(rbr_t root); //输出排序的结果到二进制文件 SortGTBL.dat

#endif // RBTREEOP_H
