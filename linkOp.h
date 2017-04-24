#ifndef LINKOP_H
#define LINKOP_H

#include "header.h"

typedef struct linknode {
    mapd_t data;
    struct linknode* next;
} linkn_t, *ln_t;

//linkOp.c中函数
ln_t listInit();    //初始化链表
void createLinklist(FILE* fl, ln_t *head, ln_t *tail);    //创建链表
void insertToList(ln_t pnode, ln_t n);          //插入链表
void unloadNode(ln_t pnode, ln_t n);            //将链表指定节点从其当前位置移除，但不释放该节点
void link_copy_data(ln_t tag, ln_t src);        //复制一个节点的data到另一个节点的data
void link_swap_node(ln_t fnode, ln_t snode);    //交换两个节点的data
int link_empty(ln_t head);  //判读链表是否为空
int link_num(ln_t head);    //返回链表的节点总数(不包括头结点)
void expLink(ln_t head, FILE *fl);    //将整张链表输出到二进制文件
void showLink(ln_t head, FILE* fl); //将整张链表输出文本文件
void printLink(ln_t head);  //将整张链表打印到控制台
void link_deleteSomeNode(ln_t head, ln_t phead);    //将链表中部分节点从链表删除

//linkseq.c中函数
ln_t link_insert_sort(ln_t head);	//单向链表的插入排序(从小到大)
ln_t link_bubble_sort(ln_t head);   //单向链表的冒泡排序(从小到大)
ln_t link_select_sort(ln_t head);   //单向链表的选择排序(从小到大)
ln_t link_getComVal(ln_t head, ln_t tail);  //获得用于快速排序的基准数位置
void link_fast_sort(ln_t head, ln_t tail);  //单向链表的快速排序(从小到大)
void exp_link_seq_result(ln_t head); //输出排序的结果到二进制文件 SortGTBL.dat

//linksearch.c中函数
ln_t link_search_linkID(ln_t head, ULONG linkID);    //按linkid查找数据，并将找到的数据保存到查找结果链表中
ln_t link_search_dispclass(ln_t head, UINT dispclass);  //按交叉link列表示class番号查找数据，并将找到的数据保存到查找结果链表中
ln_t link_search_brunch(ln_t head, UINT brunch);    //按岔路数brunch查找数据，并将找到的数据保存到查找结果链表中
ln_t link_search_roadname(ln_t head, char* roadname);  //按道路名称查找数据，并将找到的数据保存到查找结果链表中
void exp_link_search_result(ln_t head);  //输出检索的结果

#endif // LINKOP_H
