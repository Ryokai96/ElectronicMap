/*
	�ļ�����treeOp.c
    ���������ڶԲ������Ĳ����������ڵ�ĳ�ʼ��
*/

#include "treeOp.h"

/*
    ��������treeInit
    �������ܣ���ʼ�����������
    ��������
    ����ֵ����ʼ����ɵĽڵ�
*/
tn_t treeInit()
{
    tn_t tTreeNode = (tn_t) malloc(sizeof(treen_t));
    memset(tTreeNode, 0, sizeof(treen_t));  //�������
    mapDataInit(&(tTreeNode->data));    //��ʼ��tTreeNode��data
    tTreeNode->parent = NULL;
    tTreeNode->lchild = NULL;
    tTreeNode->rchile = NULL;

    return tTreeNode;
}

/*
    ��������createTree
    �������ܣ��������������
    ���������ȡ�ļ����ļ�ָ�� fl�� �����������ڵ� top
    ����ֵ����
*/
void createTree(FILE* fl, tn_t top)
{
    FILE* fp;   //���ڼ�¼�ļ�β����λ��
    fseek(fl, 0, 2);   //���ļ��ڲ�ָ���ƶ����ļ�β��
    fp = (FILE*)ftell(fl);    //��¼�ļ�β����λ�ã�ftell����ֵ����Ϊlong������ǿ������ת�������������
    fseek(fl, 0, 0);   //���ļ��ڲ�ָ���ƶ����ļ�ͷ��

    mapd_t data;
    mapDataInit(data);  //��ʼ��data��ֵ

    while(fp != (FILE*)ftell(fl))
    {
        getMapData(&data, fl);
        insert_to_tree(top);
    }

    fp = NULL;
}

/*
    ��������insert_to_tree
    �������ܣ�����ڵ㵽���������
    ���������˽ڵ� top�� ���� data
    ����ֵ��data��linkid�͵�ǰ�ڵ��е�data�е�linkid�Ĵ�С�ȽϵĽ��
*/
bool insert_to_tree(tn_t top, mapd_t data)
{
    tn_t node = top;
    if(node == NULL)
    {
        node = treeInit();
        copyMapData(&node->data, &data); //��data������top->data
        return true;    //c99��true��ֵ��ʵ����1
    }

    if(node->data.linkid == data.linkid) //�����������������ͬ��ֵ
    {
        return false;
    }

    if(node->data.linkid > data.linkid)
    {
        return insert_to_tree(node->lchild, data);
    }

    return insert_to_tree(node->rchile, data);
}

/*
    ��������tree_num
    �������ܣ���ö���������Ľڵ���
    ���������˽ڵ� top�� ���ڱ���ڵ����� num
    ����ֵ����
*/
void tree_num(tn_t top, int* num)
{
    if(top == NULL)
    {
        return ;
    }

    tn_t node = top;

    else
    {
        (*num)++;
        node = node->lchild;
        tree_num(node, num);
        node = node->rchile;
        tree_num(node, num);
    }
}
