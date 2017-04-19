/*
    �ļ�����menu.c
    ����������ʹ�ò˵������ɣ�������ѡ��
*/

#include "linkOp.h"

/*
    ��������link_sortSelect
    �������ܣ�����ʽ��ѡ��
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
    printf("\t\t5.����\n");
    int n = 0;
    scanf("%d", &n);    //����ѡ�������ʽ
    fflush(stdin);

    ln_t phead = head;
    time_t start, end;  //��¼���������п�ʼʱ��ͽ���ʱ��
    switch(n) {
    case 1:
        start = time(NULL);
        phead = link_insert_sort(head);
        end = time(NULL);
        break;
    case 2:
        start = time(NULL);
        phead = link_bubble_sort(head);
        end = time(NULL);
        break;
    case 3:
        start = time(NULL);
        phead = link_select_sort(head);
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
