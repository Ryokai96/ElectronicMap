/*
    �ļ�����linksearch.c
    ���������ڶԵ�������Ĳ��Ҳ������ɶ�linkid��dispclass��brunch��roadname���в���
*/

#include "linkOp.h"

/*
    ��������link_search_linkID
    �������ܣ���linkid�������ݣ������ҵ������ݱ��浽���ҽ��������
    �������������ݵ������ͷ��� head��Ҫ���ҵ�linkid linkID
    ����ֵ�����ҽ�������ͷ���
*/
ln_t link_search_linkID(ln_t head, UINT linkID)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //���ڱ����ҵ��Ľڵ�
    ln_t ptail = phead; //ptail���ڱ���phead�����ĩβ�Ľڵ�
    ln_t pnode = NULL;  //pnode���������ɽڵ�

    while(node != NULL)
    {
        if(node->data.linkid == linkID)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //��node��data������pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        link_fast_sort(phead->next, ptail);   //���ҵ��Ľڵ���п�������
    }

    return phead;
}

/*
    ��������link_search_dispclass
    �������ܣ�������link�б�ʾclass���Ų������ݣ������ҵ������ݱ��浽���ҽ��������
    �������������ݵ������ͷ��� head��Ҫ���ҵĽ���link�б�ʾclass���� dispclass
    ����ֵ�����ҽ�������ͷ���
*/
ln_t link_search_dispclass(ln_t head, UINT dispclass)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //���ڱ����ҵ��Ľڵ�
    ln_t ptail = phead; //ptail���ڱ���phead�����ĩβ�Ľڵ�
    ln_t pnode = NULL;  //pnode���������ɽڵ�

    while(node != NULL)
    {
        if(get_dispclass(node->data.node) == dispclass)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //��node��data������pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        link_fast_sort(phead->next, ptail);   //���ҵ��Ľڵ���п�������
    }

    return phead;
}

/*
    ��������link_search_linkID
    �������ܣ�����·��brunch�������ݣ������ҵ������ݱ��浽���ҽ��������
    �������������ݵ������ͷ��� head��Ҫ���ҵĲ�·�� brunch
    ����ֵ�����ҽ�������ͷ���
*/
ln_t link_search_brunch(ln_t head, UINT brunch)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //���ڱ����ҵ��Ľڵ�
    ln_t ptail = phead; //ptail���ڱ���phead�����ĩβ�Ľڵ�
    ln_t pnode = NULL;  //pnode���������ɽڵ�

    while(node != NULL)
    {
        if(get_brunch(node->data.node) == brunch)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //��node��data������pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        link_fast_sort(phead->next, ptail);   //���ҵ��Ľڵ���п�������
    }

    return phead;
}

/*
    ��������link_search_roadname
    �������ܣ�����·���Ʋ������ݣ������ҵ������ݱ��浽���ҽ��������
    �������������ݵ������ͷ��� head��Ҫ���ҵĵ�·���� roadname
    ����ֵ�����ҽ�������ͷ���
*/
ln_t link_search_roadname(ln_t head, char* roadname)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;

    ln_t phead = listInit();    //���ڱ����ҵ��Ľڵ�
    ln_t ptail = phead; //ptail���ڱ���phead�����ĩβ�Ľڵ�
    ln_t pnode = NULL;  //pnode���������ɽڵ�

    while(node != NULL)
    {
        if(strcmp((char*)(node->data.roadname), roadname) == 0)
        {
            pnode = listInit();
            link_copy_data(pnode, node);    //��node��data������pnode
            ptail->next = pnode;
            ptail = ptail->next;
            node = node->next;
        }
        else
        {
            node = node->next;
        }
    }

    if(link_num(head) == 0)
    {
        link_fast_sort(phead->next, ptail);   //���ҵ��Ľڵ���п�������
    }

    return phead;
}


int NFILE = 0;  //���ڼ�¼�����˼���searchresult.txt

/*
    ��������exp_search_result
    �������ܣ���������Ľ��
    ���������ҽ�������ͷ��� head
    ����ֵ����
*/
void exp_search_result(ln_t head)
{
    if(link_num(head) == 0)
    {
        printf("the data is non-existent\n");
        return ;
    }
    else if(link_num(head) <= 5)
    {
        printLink(head);
    }
    else
    {
        FILE* fl;
        char fileNameLen[4] = "";   //�ļ�����ʽ��searchresult001.txt
        sprintf(fileNameLen, "%03d", ++NFILE);  //NFILE��¼�����˼���searchresult.txt
        char filename[20] = "searchresult"; //�ļ���
        strcat(filename, fileNameLen);
        strcat(filename, ".txt");
        char* filePath = (char*)malloc(strlen(FILE_PATH) + strlen(filename) + 1);
        memset(filePath, 0, sizeof(filePath));
        strcat(filePath, FILE_PATH);
        strcat(filePath, filename);

        if((fl = fopen(filePath,"wt+")) == NULL)
        {
            printf("searchresult.txt open error!\n");
            exit(1);
        }
        showLink(head, fl);
        free(filePath);
        fclose(fl);
        fl = NULL;
    }
}
