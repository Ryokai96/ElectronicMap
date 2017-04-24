#ifndef LINKOP_H
#define LINKOP_H

#include "header.h"

typedef struct linknode {
    mapd_t data;
    struct linknode* next;
} linkn_t, *ln_t;

//linkOp.c�к���
ln_t listInit();    //��ʼ������
void createLinklist(FILE* fl, ln_t *head, ln_t *tail);    //��������
void insertToList(ln_t pnode, ln_t n);          //��������
void unloadNode(ln_t pnode, ln_t n);            //������ָ���ڵ���䵱ǰλ���Ƴ��������ͷŸýڵ�
void link_copy_data(ln_t tag, ln_t src);        //����һ���ڵ��data����һ���ڵ��data
void link_swap_node(ln_t fnode, ln_t snode);    //���������ڵ��data
int link_empty(ln_t head);  //�ж������Ƿ�Ϊ��
int link_num(ln_t head);    //��������Ľڵ�����(������ͷ���)
void expLink(ln_t head, FILE *fl);    //����������������������ļ�
void showLink(ln_t head, FILE* fl); //��������������ı��ļ�
void printLink(ln_t head);  //�����������ӡ������̨
void link_deleteSomeNode(ln_t head, ln_t phead);    //�������в��ֽڵ������ɾ��

//linkseq.c�к���
ln_t link_insert_sort(ln_t head);	//��������Ĳ�������(��С����)
ln_t link_bubble_sort(ln_t head);   //���������ð������(��С����)
ln_t link_select_sort(ln_t head);   //���������ѡ������(��С����)
ln_t link_getComVal(ln_t head, ln_t tail);  //������ڿ�������Ļ�׼��λ��
void link_fast_sort(ln_t head, ln_t tail);  //��������Ŀ�������(��С����)
void exp_link_seq_result(ln_t head); //�������Ľ�����������ļ� SortGTBL.dat

//linksearch.c�к���
ln_t link_search_linkID(ln_t head, ULONG linkID);    //��linkid�������ݣ������ҵ������ݱ��浽���ҽ��������
ln_t link_search_dispclass(ln_t head, UINT dispclass);  //������link�б�ʾclass���Ų������ݣ������ҵ������ݱ��浽���ҽ��������
ln_t link_search_brunch(ln_t head, UINT brunch);    //����·��brunch�������ݣ������ҵ������ݱ��浽���ҽ��������
ln_t link_search_roadname(ln_t head, char* roadname);  //����·���Ʋ������ݣ������ҵ������ݱ��浽���ҽ��������
void exp_link_search_result(ln_t head);  //��������Ľ��

#endif // LINKOP_H
