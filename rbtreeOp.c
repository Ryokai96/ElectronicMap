/*
    文件名：rbtreeOp.c
    描述：用于对红黑树的操作，包括初始化红黑树节点，红黑树的左旋、右旋，插入节点，红黑树的插入修复，创建红黑树，中序遍历输出红黑树到二进制文件、文本文件、控制台
*/

#include "rbtreeOp.h"

/*
    函数名：rbtreeInit
    函数功能：初始化红黑树节点
    参数：无
    返回值：初始化完成的节点
*/
rbtn_t rbtreeInit()
{
    rbtn_t node = (rbtn_t)malloc(sizeof(rbreeenode_t));
    memset(node, 0, sizeof(rbreeenode_t));  //清除数据
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = red;
    mapDataInit(&(node->data)); //初始化node->data的值

    return node;
}

/*
    函数名：rbtree_left_rotate
    函数功能：红黑树左旋，当前节点的右孩子的左孩子成为其右孩子，其原右孩子成为其父节点
    参数：当前节点 node，根节点 root
    返回值：初始化完成的节点
*/
void rbtree_left_rotate(rbtn_t node, rbr_t root)
{
    //判断node的右孩子是否存在，不存在不能左旋
    if(node->right == NULL)
    {
        printf("node's right node isn't exist, can't left rotate\n");
        return ;
    }

    rbtn_t rnode = node->right; //保存node的原右孩子

    node->right = rnode->left;  //将rnode的左孩子作为node的右孩子
    //如果rnode左孩子非空，将rnode的左孩子的父亲设为node
    if(rnode->left != NULL)
    {
        rnode->left->parent = node;
    }
    node->parent = rnode->parent;   //将node的父节点作为rnode的父节点

    if(node->parent == NULL)   //判段pnode是否为空(即判断node原来是否是根节点)
    {
        root->node = rnode; //若node原来是否是根节点，则设置rnode为根节点
    }
    else
    {
        //如果node是其pnode的左孩子，将rnode作为pnode的左孩子
        if(node->parent->left == node)
        {
            node->parent->left = rnode;
        }
        //如果node是其pnode的右孩子，将rnode作为pnode的右孩子
        if(node->parent->right == node)
        {
            node->parent->right = rnode;
        }
    }

    rnode->left = node; //把rnode的左孩子设为node
    node->parent = rnode;   //把node的父节点设为rnode

    rnode = NULL;
}

/*
    函数名：rbtree_right_rotate
    函数功能：红黑树右旋，当前节点的左孩子的右孩子成为其左孩子，其原左孩子成为其父节点
    参数：当前节点 node，根节点 root
    返回值：无
*/
void rbtree_right_rotate(rbtn_t node, rbr_t root)
{
    //判断node的左孩子是否存在，不存在不能右旋
    if(node->left == NULL)
    {
        printf("node's left node isn't exist, can't right rotate\n");
        return ;
    }

    rbtn_t lnode = node->left; //保存node的原左孩子

    node->left = lnode->right;  //将lnode的右孩子作为node的左孩子
    //如果lnode右孩子非空，将lnode的右孩子的父亲设为node
    if(lnode->right != NULL)
    {
        lnode->right->parent = node;
    }

    lnode->parent = node->parent;   //把node的parent设为lnode的parent

    if(node->parent == NULL)   //判段pnode是否为空(即判断node原来是否是根节点)
    {
        root->node = lnode; //若node原来是否是根节点，则设置lnode为根节点
    }
    else
    {
        //如果node是其pnode的左孩子，将lnode作为pnode的左孩子
        if(node->parent->left == node)
        {
            node->parent->left = lnode;
        }
        //如果node是其pnode的右孩子，将lnode作为pnode的右孩子
        if(node->parent->right == node)
        {
            node->parent->right = lnode;
        }
    }

    lnode->right = node;    //将node设为lnode的右孩子
    node->parent = lnode;   //将node的父节点设为lnode

    lnode = NULL;
}

/*
    函数名：insert_to_rbtree
    函数功能：插入节点到红黑树
    参数：要插入的数据 data， 红黑树根节点 root
    返回值：无
*/
void insert_to_rbtree(md_t data, rbr_t root)
{
    rbtn_t node = NULL;
    node = rbtreeInit();    //初始化节点
    copyMapData(&(node->data), data);   //将data值拷贝给node->data

    rbtn_t tail = NULL; //用于保存插入位置的上个节点
    rbtn_t location = root->node;  //用于标记插入位置

    //按照查找二叉树的原理，找到插入位置
    while(location != NULL)
    {
        tail = location;

        if(node->data.linkid < location->data.linkid)
        {
            location = location->left;
        }
        else if(node->data.linkid > location->data.linkid)
        {
            location = location->right;
        }
    }

    node->parent = tail;    //设置node的父节点为插入位置的上个节点

    if(tail == NULL)
    {
        root->node = node;  //若tail是空节点，则node为根节点
    }
    else
    {
        //根据node->data.linkid的大小，将node作为tail的左孩子或右孩子
        if(node->data.linkid < tail->data.linkid)
        {
            tail->left = node;
        }
        else if(node->data.linkid > tail->data.linkid)
        {
            tail->right = node;
        }
    }

    node->color = red;

    rbtree_insert_fixup(node, root);    //将其重新修正为一棵红黑树
}

/*
    函数名：rbtree_insert_fixup
    函数功能：红黑树的插入修正
    参数：插入节点 node， 红黑树根节点 root
    返回值：无
*/
void rbtree_insert_fixup(rbtn_t node, rbr_t root)
{
    rbtn_t parent, gparent;

    while(((parent = node->parent)) && (parent->color == red))  //循环条件：父节点存在，且父节点颜色是红色
    {
        gparent = parent->parent;
        if(parent == gparent->left) //若node的父节点是其祖父节点的左孩子
        {
            {
                rbtn_t uncle = gparent->right; //叔叔节点为祖父节点的右孩子

                if(uncle && (uncle->color == red)) //如果叔叔节点是红色
                {
                    parent->color = black;  //父节点设为黑色
                    uncle->color = black;   //叔叔节点设为黑色
                    gparent->color = red;   //祖父节点设为红色

                    node = gparent; //将祖父节点设为当前节点
                    continue;   //停止本次循环
                }

                uncle = NULL;
            }

            //如果叔叔节点是黑色
            if(node == parent->right)   //如果node是parent的右孩子
            {
                rbtn_t tmp;
                rbtree_left_rotate(parent,  root);   //以父节点为支点进行左旋
                tmp = parent;
                parent = node;
                node = tmp;
            }

            //如果叔叔节点是黑色，node是parent的左孩子
            parent->color = black;  //父节点设为黑色
            gparent->color = red;   //祖父节点设为红色
            rbtree_right_rotate(gparent, root); //以祖父节点为支点进行右旋

        }
        else    //若node的父节点是其祖父节点的右孩子
        {
            {
                rbtn_t uncle = gparent->right; //叔叔节点为祖父节点的右孩子

                if((uncle!=NULL) && (uncle->color == red)) //如果叔叔节点是红色
                {
                    parent->color = black;  //父节点设为黑色
                    uncle->color = black;   //叔叔节点设为黑色
                    gparent->color = red;   //祖父节点设为红色

                    node = gparent; //将祖父节点设为当前节点

                    continue;   //停止本次循环
                }

                uncle = NULL;
            }

            //如果叔叔节点是黑色
            if(node == parent->left)   //如果node是parent的左孩子
            {
                rbtn_t tmp;
                rbtree_right_rotate(parent,  root);   //以父节点为支点进行右旋
                tmp = parent;
                parent = node;
                node = tmp;
            }

            //如果node是parent的右孩子
            parent->color = black;  //父节点设为黑色
            gparent->color = red;   //祖父节点设为红色
            rbtree_left_rotate(gparent, root); //以祖父节点为支点进行右旋
        }
    }

    root->node->color = black;  //将根节点设为黑色
}

/*
    函数名：createRBTree
    函数功能：创建红黑树
    参数：需读取文件的文件指针 fl， 红黑树根节点 root
    返回值：无
*/
void createRBTree(FILE* fl, rbr_t root)
{
    FILE* fp;   //用于记录文件尾部的位置
    fseek(fl, 0, 2);   //把文件内部指针移动到文件尾部
    fp = (FILE*)ftell(fl);    //记录文件尾部的位置，ftell返回值类型为long，进行强制类型转换避免产生警告
    fseek(fl, 0, 0);   //把文件内部指针移动到文件头部

    mapd_t data;
    mapDataInit(&data);  //初始化data的值

    while(fp != (FILE*)ftell(fl))
    {
        getMapData(&data, fl);  //获得一条数据
        insert_to_rbtree(&data, root);  //插入到红黑树中
    }

    fp = NULL;
}


/*
    函数名：expRBTree
    函数功能：中序遍历，按linkid从小到大把树的内容写入到二进制文件SortGTBL.dat
    参数：红黑根节点 node，文件指针 fl
    返回值：无
*/
void expRBTree(rbtn_t node, FILE* fl)
{
    if(node != NULL)
    {
        expRBTree(node->left, fl);
        writeMapData(&(node->data), fl);
        expRBTree(node->right, fl);
    }
}

/*
    函数名：showRBTree
    函数功能：中序遍历，按linkid从小到大把红黑树的内容写入到文本文件sourcelink.txt中
    参数：红黑根节点 node，文件指针 fl
    返回值：无
*/
void showRBTree(rbtn_t node, FILE* fl)
{
    if(node != NULL)
    {
        showRBTree(node->left, fl);
        showMapData(&(node->data), fl);
        showRBTree(node->right, fl);
    }
}

/*
    函数名：printRBTree
    函数功能：中序遍历红黑树，从小到大输出到控制台
    参数：红黑根节点 node
    返回值：无
*/
void printRBTree(rbtn_t node)
{
    if(node != NULL)
    {
        printRBTree(node->left);
        printMapData(&(node->data));
        printRBTree(node->right);
    }
}

/*
    函数名：detroyRBTree
    函数功能：删除红黑树
    参数：红黑树的根节点top
    返回值：无
*/
void destroyRBTree(rbtn_t top)
{
    if(top != NULL)
    {
        destroyRBTree(top->left);
        destroyRBTree(top->right);
        free(top);
    }
}

/*
    函数名：exp_rbtree_seq_result
    函数功能：输出排序的结果到二进制文件 SortGTBL.dat和文本文件 sourcelink.txt
    参数：排序结果红黑树的根节点root
    返回值：无
*/
void exp_rbtree_seq_result(rbr_t root)
{
    FILE* fl = NULL;
    if((fl = fopen(SORTGTBL_PATH, "wb+")) == NULL)
    {
        printf("SortGTBL.dat open error!\n");
        return ;
    }
    expRBTree(root->node, fl);
    fclose(fl);
    fl = NULL;

    FILE* fp;   //sourcelink.txt的文件指针
    if((fp = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("sourcelink.txt open error!\n");
        return ;
    }
    showRBTree(root->node, fp);
    fclose(fp);
    fp = NULL;
}

