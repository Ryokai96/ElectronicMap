/*
    �ļ�����menu.c
    ����������ʹ�ò˵������ɣ�������ѡ��
*/

#include "linkOp.h"


/*
    ��������link_sortSelect
    �������ܣ���������ʽ��ѡ��
    ������������������ͷ�ڵ� head��β�ڵ� tail
    ����ֵ���ź��������ͷ�ڵ㣬���ѡ�񷵻��򷵻�ֵΪNULL
*/
ln_t link_sortSelect(ln_t head, ln_t tail)
{
    printf("\t��ѡ������ķ�ʽ��\n");
    printf("\t\t1.��������\n");
    printf("\t\t2.ð������\n");
    printf("\t\t3.ѡ������\n");
    printf("\t\t4.��������\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = 0;
    fflush(stdin);
    scanf("%d", &n);    //����ѡ�������ʽ
    fflush(stdin);

    printf("\n");


    ln_t phead = head;  //���ڱ�������õ������ͷ�ڵ�
    time_t start, end;  //��¼���������п�ʼʱ��ͽ���ʱ��
    switch(n) {
    case 1:
        start = time(NULL);
        phead = link_insert_sort(head); //14s
        end = time(NULL);
        break;
    case 2:
        start = time(NULL);
        phead = link_bubble_sort(head); //311s
        end = time(NULL);
        break;
    case 3:
        start = time(NULL);
        phead = link_select_sort(head); //24s
        end = time(NULL);
        break;
    case 4:
        start = time(NULL);
        link_fast_sort(head->next, tail);
        end = time(NULL);
        break;
    default:
        phead = NULL;
        return NULL;
    }

    printf("the sort method have spend %d s\n", (int)difftime(end,start)); //��ӡ����������ʱ��

    return phead;
}

/*
    ��������link_searchSelect
    �������ܣ���������ʽ��ѡ�����������
    ������������������ͷ�ڵ� head��β�ڵ� tail
    ����ֵ����
*/
void link_searchSelect(ln_t head)
{
    printf("\t��ѡ������ķ�ʽ��\n");
    printf("\t\t1.ָ�� linkID ����\n");
    printf("\t\t2.ָ�� ����Link�б�ʾClass���� ����\n");
    printf("\t\t3.ָ�� ���Ҳ�·�� ����\n");
    printf("\t\t4.ָ�� ��·���� ����\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = 0;
    fflush(stdin);
    scanf("%d", &n);    //����ѡ��ļ�����ʽ
    fflush(stdin);
    printf("\n");

    ln_t phead = NULL;  //���ڱ�����ҽ�������ͷ�ڵ�
    switch(n) {
    case 1:
        printf("\t������ linkID ��");
        ULONG linkID = 0;
        fflush(stdin);
        scanf("%ld", &linkID);    //����linkID
        fflush(stdin);
        printf("\n");
        phead = link_search_linkID(head, linkID);
        break;
    case 2:
        printf("\t������ ����Link�б�ʾClass���� ��\n");
        UINT dispclass = 0;
        fflush(stdin);
        scanf("%hd", &dispclass);    //����dispclass
        fflush(stdin);
        printf("\n");
        phead = link_search_dispclass(head, dispclass);
        break;
    case 3:
        printf("\t������ Link��Brunch(�����)���� ��\n");
        UINT brunch = 0;
        fflush(stdin);
        scanf("%hd", &brunch);    //����brunch
        fflush(stdin);
        printf("\n");
        phead = link_search_brunch(head, brunch);
        break;
    case 4:
        printf("\t������ ��·���� ��\n");
        char roadname[30] = "";
        fflush(stdin);
        scanf("%s", roadname);    //����brunch
        fflush(stdin);
        printf("\n");
        phead = link_search_roadname(head, roadname);
        break;
    default:
        phead = NULL;
        return ;
    }

    exp_search_result(phead);   //���������

    phead = NULL;
}

