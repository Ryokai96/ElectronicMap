/*
    文件名：treeseq.c
    描述：将排序二叉树中序遍历输出(从小到大)
*/

#include "treeOp.h"

/*
    函数名：exp_tree_seq_result
    函数功能：输出排序的结果到二进制文件 SortGTBL.dat和文本文件 sourcelink.txt
    参数：查找结果二叉树的顶端节点 top
    返回值：无
*/
void exp_tree_seq_result(tn_t top)
{
    int num = 0;
    tree_num(top, &num);
    if(num == 0)
    {
        printf("empty tree\n");
        return ;
    }

    FILE* fl = NULL;
    if((fl = fopen(SORTGTBL_PATH, "wb+")) == NULL)
    {
        printf("SortGTBL.dat open error!\n");
        return ;
    }
    expTree(top, fl);
    fclose(fl);
    fl = NULL;

    FILE* fp;   //sourcelink.txt的文件指针
    if((fp = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("sourcelink.txt open error!\n");
        return ;
    }
    showTree(top, fp);
    fclose(fp);
    fp = NULL;
}
