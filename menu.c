/*
    文件名：menu.c
    描述：程序使用菜单的生成，程序功能选择
*/

#include "linkOp.h"

/*
    函数名：link_sortSelect
    函数功能：排序方式的选择
    参数：需排序的链表的头节点 head，尾节点 tail
    返回值：排好序的链表头节点，如果选择返回则返回值为NULL
*/
ln_t link_sortSelect(ln_t head, ln_t tail)
{
    printf("\t请选择排序的方式：\n");
    printf("\t\t1.插入排序\n");
    printf("\t\t2.冒泡排序\n");
    printf("\t\t3.选择排序\n");
    printf("\t\t4.快速排序\n");
    printf("\t\t5.返回\n");
    int n = 0;
    scanf("%d", &n);    //输入选择的排序方式
    fflush(stdin);

    ln_t phead = head;
    time_t start, end;  //记录排序函数运行开始时间和结束时间
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

    printf("the sort method have spend %d s\n", (int)difftime(end,start)); //打印排序函数运行时间

    return phead;
}
