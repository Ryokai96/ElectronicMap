/*
    �ļ�����treesearch.c
    ���������ڶԶ���������Ĳ��Ҳ������ɶ�linkid��dispclass��brunch��roadname���в��ң��Բ��ҽ��������Ӧ�����ĺ���Ҳ��������
*/

#include "treeOp.h"

/*
    ��������tree_search_linkID
    �������ܣ���linkid��������
    �������������ݵĶ������Ķ��˽ڵ� top��Ҫ���ҵ�linkid linkID
    ����ֵ�����ҽ��
*/
tn_t tree_search_linkID(tn_t top, ULONG linkID)
{
    bool solve = false; //��־�Ƿ��ҵ�ָ��linkid
    while(top && (!solve))
    {
        if(linkID == top->data.linkid)
        {
            solve = true;
        }
        else if(linkID < top->data.linkid)
        {
            top = top->lchild;
        }
        else
        {
            top = top->rchild;
        }
    }

    return top;
}

/*
    ��������exp_tree_search_result
    �������ܣ���������Ľ��
    ���������˽ڵ� top
    ����ֵ����
*/
void exp_tree_search_result(tn_t top)
{
    int num = 0;
    tree_num(top, &num);
    if(num == 0)
    {
        printf("the data is non-existent\n");
        return ;
    }
    printMapData(&(top->data));
}
