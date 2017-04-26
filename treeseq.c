/*
    �ļ�����treeseq.c
    ���������������������������(��С����)
*/

#include "treeOp.h"

/*
    ��������exp_tree_seq_result
    �������ܣ��������Ľ�����������ļ� SortGTBL.dat���ı��ļ� sourcelink.txt
    ���������ҽ���������Ķ��˽ڵ� top
    ����ֵ����
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

    FILE* fp;   //sourcelink.txt���ļ�ָ��
    if((fp = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("sourcelink.txt open error!\n");
        return ;
    }
    showTree(top, fp);
    fclose(fp);
    fp = NULL;
}
