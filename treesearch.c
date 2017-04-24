/*
    文件名：treesearch.c
    描述：用于对二叉查找树的查找操作，可对linkid、dispclass、brunch、roadname进行查找，对查找结果进行相应操作的函数也包括在内
*/

#include "treeOp.h"

/*
    函数名：tree_search_linkID
    函数功能：按linkid查找数据
    参数：查找数据的二叉树的顶端节点 top，要查找的linkid linkID
    返回值：查找结果
*/
tn_t tree_search_linkID(tn_t top, ULONG linkID)
{
    bool solve = false; //标志是否找到指定linkid
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
    函数名：exp_tree_search_result
    函数功能：输出检索的结果
    参数：顶端节点 top
    返回值：无
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
