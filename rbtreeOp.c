/*
    �ļ�����rbtreeOp.c
    ���������ڶԺ�����Ĳ�����������ʼ��������ڵ㣬�����������������������ڵ㣬������Ĳ����޸��������������������������������������ļ����ı��ļ�������̨
*/

#include "rbtreeOp.h"

/*
    ��������rbtreeInit
    �������ܣ���ʼ��������ڵ�
    ��������
    ����ֵ����ʼ����ɵĽڵ�
*/
rbtn_t rbtreeInit()
{
    rbtn_t node = (rbtn_t)malloc(sizeof(rbreeenode_t));
    memset(node, 0, sizeof(rbreeenode_t));  //�������
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = red;
    mapDataInit(&(node->data)); //��ʼ��node->data��ֵ

    return node;
}

/*
    ��������rbtree_left_rotate
    �������ܣ��������������ǰ�ڵ���Һ��ӵ����ӳ�Ϊ���Һ��ӣ���ԭ�Һ��ӳ�Ϊ�丸�ڵ�
    ��������ǰ�ڵ� node�����ڵ� root
    ����ֵ����ʼ����ɵĽڵ�
*/
void rbtree_left_rotate(rbtn_t node, rbr_t root)
{
    //�ж�node���Һ����Ƿ���ڣ������ڲ�������
    if(node->right == NULL)
    {
        printf("node's right node isn't exist, can't left rotate\n");
        return ;
    }

    rbtn_t rnode = node->right; //����node��ԭ�Һ���

    node->right = rnode->left;  //��rnode��������Ϊnode���Һ���
    //���rnode���ӷǿգ���rnode�����ӵĸ�����Ϊnode
    if(rnode->left != NULL)
    {
        rnode->left->parent = node;
    }
    node->parent = rnode->parent;   //��node�ĸ��ڵ���Ϊrnode�ĸ��ڵ�

    if(node->parent == NULL)   //�ж�pnode�Ƿ�Ϊ��(���ж�nodeԭ���Ƿ��Ǹ��ڵ�)
    {
        root->node = rnode; //��nodeԭ���Ƿ��Ǹ��ڵ㣬������rnodeΪ���ڵ�
    }
    else
    {
        //���node����pnode�����ӣ���rnode��Ϊpnode������
        if(node->parent->left == node)
        {
            node->parent->left = rnode;
        }
        //���node����pnode���Һ��ӣ���rnode��Ϊpnode���Һ���
        if(node->parent->right == node)
        {
            node->parent->right = rnode;
        }
    }

    rnode->left = node; //��rnode��������Ϊnode
    node->parent = rnode;   //��node�ĸ��ڵ���Ϊrnode

    rnode = NULL;
}

/*
    ��������rbtree_right_rotate
    �������ܣ��������������ǰ�ڵ�����ӵ��Һ��ӳ�Ϊ�����ӣ���ԭ���ӳ�Ϊ�丸�ڵ�
    ��������ǰ�ڵ� node�����ڵ� root
    ����ֵ����
*/
void rbtree_right_rotate(rbtn_t node, rbr_t root)
{
    //�ж�node�������Ƿ���ڣ������ڲ�������
    if(node->left == NULL)
    {
        printf("node's left node isn't exist, can't right rotate\n");
        return ;
    }

    rbtn_t lnode = node->left; //����node��ԭ����

    node->left = lnode->right;  //��lnode���Һ�����Ϊnode������
    //���lnode�Һ��ӷǿգ���lnode���Һ��ӵĸ�����Ϊnode
    if(lnode->right != NULL)
    {
        lnode->right->parent = node;
    }

    lnode->parent = node->parent;   //��node��parent��Ϊlnode��parent

    if(node->parent == NULL)   //�ж�pnode�Ƿ�Ϊ��(���ж�nodeԭ���Ƿ��Ǹ��ڵ�)
    {
        root->node = lnode; //��nodeԭ���Ƿ��Ǹ��ڵ㣬������lnodeΪ���ڵ�
    }
    else
    {
        //���node����pnode�����ӣ���lnode��Ϊpnode������
        if(node->parent->left == node)
        {
            node->parent->left = lnode;
        }
        //���node����pnode���Һ��ӣ���lnode��Ϊpnode���Һ���
        if(node->parent->right == node)
        {
            node->parent->right = lnode;
        }
    }

    lnode->right = node;    //��node��Ϊlnode���Һ���
    node->parent = lnode;   //��node�ĸ��ڵ���Ϊlnode

    lnode = NULL;
}

/*
    ��������insert_to_rbtree
    �������ܣ�����ڵ㵽�����
    ������Ҫ��������� data�� ��������ڵ� root
    ����ֵ����
*/
void insert_to_rbtree(md_t data, rbr_t root)
{
    rbtn_t node = NULL;
    node = rbtreeInit();    //��ʼ���ڵ�
    copyMapData(&(node->data), data);   //��dataֵ������node->data

    rbtn_t tail = NULL; //���ڱ������λ�õ��ϸ��ڵ�
    rbtn_t location = root->node;  //���ڱ�ǲ���λ��

    //���ղ��Ҷ�������ԭ���ҵ�����λ��
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

    node->parent = tail;    //����node�ĸ��ڵ�Ϊ����λ�õ��ϸ��ڵ�

    if(tail == NULL)
    {
        root->node = node;  //��tail�ǿսڵ㣬��nodeΪ���ڵ�
    }
    else
    {
        //����node->data.linkid�Ĵ�С����node��Ϊtail�����ӻ��Һ���
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

    rbtree_insert_fixup(node, root);    //������������Ϊһ�ú����
}

/*
    ��������rbtree_insert_fixup
    �������ܣ�������Ĳ�������
    ����������ڵ� node�� ��������ڵ� root
    ����ֵ����
*/
void rbtree_insert_fixup(rbtn_t node, rbr_t root)
{
    rbtn_t parent, gparent;

    while(((parent = node->parent)) && (parent->color == red))  //ѭ�����������ڵ���ڣ��Ҹ��ڵ���ɫ�Ǻ�ɫ
    {
        gparent = parent->parent;
        if(parent == gparent->left) //��node�ĸ��ڵ������游�ڵ������
        {
            {
                rbtn_t uncle = gparent->right; //����ڵ�Ϊ�游�ڵ���Һ���

                if(uncle && (uncle->color == red)) //�������ڵ��Ǻ�ɫ
                {
                    parent->color = black;  //���ڵ���Ϊ��ɫ
                    uncle->color = black;   //����ڵ���Ϊ��ɫ
                    gparent->color = red;   //�游�ڵ���Ϊ��ɫ

                    node = gparent; //���游�ڵ���Ϊ��ǰ�ڵ�
                    continue;   //ֹͣ����ѭ��
                }

                uncle = NULL;
            }

            //�������ڵ��Ǻ�ɫ
            if(node == parent->right)   //���node��parent���Һ���
            {
                rbtn_t tmp;
                rbtree_left_rotate(parent,  root);   //�Ը��ڵ�Ϊ֧���������
                tmp = parent;
                parent = node;
                node = tmp;
            }

            //�������ڵ��Ǻ�ɫ��node��parent������
            parent->color = black;  //���ڵ���Ϊ��ɫ
            gparent->color = red;   //�游�ڵ���Ϊ��ɫ
            rbtree_right_rotate(gparent, root); //���游�ڵ�Ϊ֧���������

        }
        else    //��node�ĸ��ڵ������游�ڵ���Һ���
        {
            {
                rbtn_t uncle = gparent->right; //����ڵ�Ϊ�游�ڵ���Һ���

                if((uncle!=NULL) && (uncle->color == red)) //�������ڵ��Ǻ�ɫ
                {
                    parent->color = black;  //���ڵ���Ϊ��ɫ
                    uncle->color = black;   //����ڵ���Ϊ��ɫ
                    gparent->color = red;   //�游�ڵ���Ϊ��ɫ

                    node = gparent; //���游�ڵ���Ϊ��ǰ�ڵ�

                    continue;   //ֹͣ����ѭ��
                }

                uncle = NULL;
            }

            //�������ڵ��Ǻ�ɫ
            if(node == parent->left)   //���node��parent������
            {
                rbtn_t tmp;
                rbtree_right_rotate(parent,  root);   //�Ը��ڵ�Ϊ֧���������
                tmp = parent;
                parent = node;
                node = tmp;
            }

            //���node��parent���Һ���
            parent->color = black;  //���ڵ���Ϊ��ɫ
            gparent->color = red;   //�游�ڵ���Ϊ��ɫ
            rbtree_left_rotate(gparent, root); //���游�ڵ�Ϊ֧���������
        }
    }

    root->node->color = black;  //�����ڵ���Ϊ��ɫ
}

/*
    ��������createRBTree
    �������ܣ����������
    ���������ȡ�ļ����ļ�ָ�� fl�� ��������ڵ� root
    ����ֵ����
*/
void createRBTree(FILE* fl, rbr_t root)
{
    FILE* fp;   //���ڼ�¼�ļ�β����λ��
    fseek(fl, 0, 2);   //���ļ��ڲ�ָ���ƶ����ļ�β��
    fp = (FILE*)ftell(fl);    //��¼�ļ�β����λ�ã�ftell����ֵ����Ϊlong������ǿ������ת�������������
    fseek(fl, 0, 0);   //���ļ��ڲ�ָ���ƶ����ļ�ͷ��

    mapd_t data;
    mapDataInit(&data);  //��ʼ��data��ֵ

    while(fp != (FILE*)ftell(fl))
    {
        getMapData(&data, fl);  //���һ������
        insert_to_rbtree(&data, root);  //���뵽�������
    }

    fp = NULL;
}


/*
    ��������expRBTree
    �������ܣ������������linkid��С�������������д�뵽�������ļ�SortGTBL.dat
    ��������ڸ��ڵ� node���ļ�ָ�� fl
    ����ֵ����
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
    ��������showRBTree
    �������ܣ������������linkid��С����Ѻ����������д�뵽�ı��ļ�sourcelink.txt��
    ��������ڸ��ڵ� node���ļ�ָ�� fl
    ����ֵ����
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
    ��������printRBTree
    �������ܣ�����������������С�������������̨
    ��������ڸ��ڵ� node
    ����ֵ����
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
    ��������detroyRBTree
    �������ܣ�ɾ�������
    ������������ĸ��ڵ�top
    ����ֵ����
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
    ��������exp_rbtree_seq_result
    �������ܣ��������Ľ�����������ļ� SortGTBL.dat���ı��ļ� sourcelink.txt
    ������������������ĸ��ڵ�root
    ����ֵ����
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

    FILE* fp;   //sourcelink.txt���ļ�ָ��
    if((fp = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("sourcelink.txt open error!\n");
        return ;
    }
    showRBTree(root->node, fp);
    fclose(fp);
    fp = NULL;
}

