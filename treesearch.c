/*
    文件名：treesearch.c
    描述：用于对二叉查找树的查找操作，可对linkid、roadname进行查找，对查找结果进行相应操作的函数也包括在内
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
    函数名：tree_search_dispclass
    函数功能：按dispclass查找数据
    参数：查找数据的二叉树的顶端节点 top，要查找的 dispclass，用来保存查找到的数据的树根节点ptop
    返回值：无
*/
void tree_search_dispclass(tn_t top, UINT dispclass, tn_t* ptop)
{
    if(top != NULL)
    {
        if(get_dispclass(top->data.node) == dispclass)
        {
            mapd_t data;
            mapDataInit(&data);
            copyMapData(&data, &(top->data));
            insert_to_tree(ptop, data);
        }
        tree_search_dispclass(top->lchild, dispclass, ptop);
        tree_search_dispclass(top->rchild, dispclass, ptop);
    }
}

/*
    函数名：tree_search_brunch
    函数功能：按brunch查找数据
    参数：查找数据的二叉树的顶端节点 top，要查找的 brunch，用来保存查找到的数据的树根节点ptop
    返回值：无
*/
void tree_search_brunch(tn_t top, UINT brunch, tn_t* ptop)
{
    if(top != NULL)
    {
        if(get_brunch(top->data.node) == brunch)
        {
            mapd_t data;
            mapDataInit(&data);
            copyMapData(&data, &(top->data));
            insert_to_tree(ptop, data);
        }
        tree_search_brunch(top->lchild, brunch, ptop);
        tree_search_brunch(top->rchild, brunch, ptop);
    }
}

/*
    函数名：tree_search_linkID
    函数功能：按roadname查找数据
    参数：查找数据的二叉树的顶端节点 top，要查找的 roadname，用来保存查找到的数据的树根节点ptop
    返回值：无
*/
void tree_search_roadname(tn_t top, char* roadname, tn_t* ptop)
{
    if(top != NULL)
    {
        if(strcmp((char*)(top->data.roadname), roadname) == 0)
        {
            mapd_t data;
            mapDataInit(&data);
            copyMapData(&data, &(top->data));
            insert_to_tree(ptop, data);
        }
        tree_search_roadname(top->lchild, roadname, ptop);
        tree_search_roadname(top->rchild, roadname, ptop);
    }
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
    else if(num <= 5)
    {
        printMapData(&(top->data));
    }
    else{
        FILE* fl;
        char fileNameLen[4] = "";   //文件名形式：searchresult001.txt
        sprintf(fileNameLen, "%03d", ++NFILE);  //NFILE记录创建了几次searchresult.txt
        char filename[20] = "searchresult"; //文件名
        strcat(filename, fileNameLen);
        strcat(filename, ".txt");
        char* filePath = (char*)malloc(strlen(FILE_PATH) + strlen(filename) + 1);   //文件路径
        memset(filePath, 0, strlen(FILE_PATH) + strlen(filename) + 1);  //清空字符串
        strcat(filePath, FILE_PATH);
        strcat(filePath, filename);

        printf("***************************************************************************\n");
        printf("\b\b结果大于5条，将其转存到文本文件%s\n", filename);
        printf("***************************************************************************\n");

        if((fl = fopen(filePath,"wt+")) == NULL)
        {
            printf("searchresult.txt open error!\n");
            exit(1);
        }
        showTree(top, fl);
        free(filePath);
        fclose(fl);
        fl = NULL;
    }
}
