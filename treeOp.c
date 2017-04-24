/*
	�ļ�����treeOp.c
    ���������ڶԲ������Ĳ����������ڵ�ĳ�ʼ����������������ڵ㵽������������������Ľڵ������ڿ���̨��ӡ����������������ı��ļ�
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
    static int n = 0;
    n++;
   // int size = sizeof(treen_t);
    tn_t tTreeNode = (tn_t) malloc(sizeof(treen_t));
    if(tTreeNode == NULL)
        printf("malloc error\n");
    memset(tTreeNode, 0, sizeof(treen_t));  //�������
    mapDataInit(&(tTreeNode->data));    //��ʼ��tTreeNode��data
    tTreeNode->lchild = NULL;
    tTreeNode->rchild = NULL;

    return tTreeNode;
}

/*
    ��������createTree
    �������ܣ��������������
    ���������ȡ�ļ����ļ�ָ�� fl�� �����������ڵ� top
    ����ֵ����
*/
void createTree(FILE* fl, tn_t* top)
{
    FILE* fp;   //���ڼ�¼�ļ�β����λ��
    fseek(fl, 0, 2);   //���ļ��ڲ�ָ���ƶ����ļ�β��
    fp = (FILE*)ftell(fl);    //��¼�ļ�β����λ�ã�ftell����ֵ����Ϊlong������ǿ������ת�������������
    fseek(fl, 0, 0);   //���ļ��ڲ�ָ���ƶ����ļ�ͷ��

    mapd_t data;
    mapDataInit(&data);  //��ʼ��data��ֵ

    while(fp != (FILE*)ftell(fl))
    {
        getMapData(&data, fl);
        insert_to_tree(top, data);
    }

    fp = NULL;
}

/*
    ��������insert_to_tree
    �������ܣ�����ڵ㵽���������
    ���������˽ڵ� top�� ���� data
    ����ֵ��data��linkid�͵�ǰ�ڵ��е�data�е�linkid�Ĵ�С�ȽϵĽ��
*/
bool insert_to_tree(tn_t* top, mapd_t data)
{
    tn_t* node = top;
    if((*node) == NULL)
    {
        (*node) = treeInit();
        copyMapData(&((*node)->data), &data); //��data������top->data
        node = NULL;
        return true;    //c99��true��ֵ��ʵ����1
    }

    if((*node)->data.linkid == data.linkid) //�����������������ͬ��ֵ
    {
        node = NULL;
        return false;
    }

    if((*node)->data.linkid > data.linkid)
    {
        return insert_to_tree(&((*node)->lchild), data);
    }

    return insert_to_tree(&((*node)->rchild), data);
}

/*
    ��������tree_num
    �������ܣ����������ö���������Ľڵ���
    ���������˽ڵ� top�� ���ڱ���ڵ����� num
    ����ֵ���÷�֧�Ƿ����������true���������false����δ����
*/
bool tree_num(tn_t top, int* num)
{
    if(top != NULL)
    {
        (*num)++;
        if(tree_num(top->lchild, num) == true)
        {
            if(tree_num(top->rchild, num) == true)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}

/*
    ��������expLink
    �������ܣ������������linkid��С�������������д�뵽�������ļ�SortGTBL.dat
    ���������˽ڵ� top���ļ�ָ��fl
    ����ֵ���÷�֧�Ƿ����������true���������false����δ����
*/
bool expTree(tn_t top, FILE* fl)
{
    if(top != NULL)
    {
        if(expTree(top->lchild, fl) == true)
        {
            writeMapData(&(top->data), fl);
            if(expTree(top->rchild, fl) == true)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}

/*
    ��������showTree
    �������ܣ������������linkid��С�������������д�뵽�ı��ļ�sourcelink.txt��
    ���������˽ڵ� top���ļ�ָ��fl
    ����ֵ���÷�֧�Ƿ����������true���������false����δ����
*/
bool showTree(tn_t top, FILE* fl)
{
    if(top != NULL)
    {
        if(showTree(top->lchild, fl) == true)
        {
            showMapData(&(top->data), fl);
            if(showTree(top->rchild, fl) == true)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}

/*
    ��������print_tree
    �������ܣ�����������ڿ���̨��ӡ����������������нڵ�
    ���������˽ڵ� top
    ����ֵ���÷�֧�Ƿ����������true���������false����δ����
*/
bool print_tree(tn_t top)
{
    if(top != NULL)
    {
        if(print_tree(top->lchild) == true)
        {
            printMapData(&(top->data));    //��һ��mapdata�ṹ���������ݴ�ӡ������̨
            if(print_tree(top->rchild) == true)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}
