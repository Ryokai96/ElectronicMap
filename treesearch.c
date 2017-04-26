/*
    �ļ�����treesearch.c
    ���������ڶԶ���������Ĳ��Ҳ������ɶ�linkid��roadname���в��ң��Բ��ҽ��������Ӧ�����ĺ���Ҳ��������
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
    ��������tree_search_dispclass
    �������ܣ���dispclass��������
    �������������ݵĶ������Ķ��˽ڵ� top��Ҫ���ҵ� dispclass������������ҵ������ݵ������ڵ�ptop
    ����ֵ����
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
    ��������tree_search_brunch
    �������ܣ���brunch��������
    �������������ݵĶ������Ķ��˽ڵ� top��Ҫ���ҵ� brunch������������ҵ������ݵ������ڵ�ptop
    ����ֵ����
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
    ��������tree_search_linkID
    �������ܣ���roadname��������
    �������������ݵĶ������Ķ��˽ڵ� top��Ҫ���ҵ� roadname������������ҵ������ݵ������ڵ�ptop
    ����ֵ����
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
    else if(num <= 5)
    {
        printMapData(&(top->data));
    }
    else{
        FILE* fl;
        char fileNameLen[4] = "";   //�ļ�����ʽ��searchresult001.txt
        sprintf(fileNameLen, "%03d", ++NFILE);  //NFILE��¼�����˼���searchresult.txt
        char filename[20] = "searchresult"; //�ļ���
        strcat(filename, fileNameLen);
        strcat(filename, ".txt");
        char* filePath = (char*)malloc(strlen(FILE_PATH) + strlen(filename) + 1);   //�ļ�·��
        memset(filePath, 0, strlen(FILE_PATH) + strlen(filename) + 1);  //����ַ���
        strcat(filePath, FILE_PATH);
        strcat(filePath, filename);

        printf("***************************************************************************\n");
        printf("\b\b�������5��������ת�浽�ı��ļ�%s\n", filename);
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
