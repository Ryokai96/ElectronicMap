/*
	文件名：treeOp.c
    描述：用于对查找树的操作，包括节点的初始化，创建树，插入节点到二叉查找树，返回树的节点数，在控制台打印出树，将数输出到文本文件
*/

#include "treeOp.h"

/*
    函数名：treeInit
    函数功能：初始化二叉查找树
    参数：无
    返回值：初始化完成的节点
*/
tn_t treeInit()
{
    static int n = 0;
    n++;
   // int size = sizeof(treen_t);
    tn_t tTreeNode = (tn_t) malloc(sizeof(treen_t));
    if(tTreeNode == NULL)
        printf("malloc error\n");
    memset(tTreeNode, 0, sizeof(treen_t));  //清空数据
    mapDataInit(&(tTreeNode->data));    //初始化tTreeNode的data
    tTreeNode->lchild = NULL;
    tTreeNode->rchild = NULL;

    return tTreeNode;
}

/*
    函数名：createTree
    函数功能：创建二叉查找树
    参数：需读取文件的文件指针 fl， 二叉树顶部节点 top
    返回值：无
*/
void createTree(FILE* fl, tn_t* top)
{
    FILE* fp;   //用于记录文件尾部的位置
    fseek(fl, 0, 2);   //把文件内部指针移动到文件尾部
    fp = (FILE*)ftell(fl);    //记录文件尾部的位置，ftell返回值类型为long，进行强制类型转换避免产生警告
    fseek(fl, 0, 0);   //把文件内部指针移动到文件头部

    mapd_t data;
    mapDataInit(&data);  //初始化data的值

    while(fp != (FILE*)ftell(fl))
    {
        getMapData(&data, fl);
        insert_to_tree(top, data);
    }

    fp = NULL;
}

/*
    函数名：insert_to_tree
    函数功能：插入节点到二叉查找树
    参数：顶端节点 top， 数据 data
    返回值：data中linkid和当前节点中的data中的linkid的大小比较的结果
*/
bool insert_to_tree(tn_t* top, mapd_t data)
{
    tn_t* node = top;
    if((*node) == NULL)
    {
        (*node) = treeInit();
        copyMapData(&((*node)->data), &data); //将data拷贝给top->data
        node = NULL;
        return true;    //c99中true的值其实就是1
    }

    if((*node)->data.linkid == data.linkid) //二叉查找树不能用相同的值
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
    函数名：tree_num
    函数功能：先序遍历获得二叉查找树的节点数
    参数：顶端节点 top， 用于保存节点数的 num
    返回值：该分支是否遍历结束，true代表结束，false代表未结束
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
    函数名：expLink
    函数功能：中序遍历，按linkid从小到大把树的内容写入到二进制文件SortGTBL.dat
    参数：顶端节点 top，文件指针fl
    返回值：该分支是否遍历结束，true代表结束，false代表未结束
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
    函数名：showTree
    函数功能：中序遍历，按linkid从小到大把树的内容写入到文本文件sourcelink.txt中
    参数：顶端节点 top，文件指针fl
    返回值：该分支是否遍历结束，true代表结束，false代表未结束
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
    函数名：print_tree
    函数功能：中序遍历，在控制台打印出二叉查找树的所有节点
    参数：顶端节点 top
    返回值：该分支是否遍历结束，true代表结束，false代表未结束
*/
bool print_tree(tn_t top)
{
    if(top != NULL)
    {
        if(print_tree(top->lchild) == true)
        {
            printMapData(&(top->data));    //将一条mapdata结构体类型数据打印到控制台
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
