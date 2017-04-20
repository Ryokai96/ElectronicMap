/*
    文件名：menu.c
    描述：程序使用菜单的生成，程序功能选择
*/

#include "linkOp.h"


/*
    函数名：link_sortSelect
    函数功能：链表排序方式的选择
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
    printf("\t\t0.返回\n");
    printf("\t请选择：");

    int n = 0;
    fflush(stdin);
    scanf("%d", &n);    //输入选择的排序方式
    fflush(stdin);

    printf("\n");


    ln_t phead = head;  //用于保存排序好的链表的头节点
    time_t start, end;  //记录排序函数运行开始时间和结束时间
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

    printf("the sort method have spend %d s\n", (int)difftime(end,start)); //打印排序函数运行时间

    return phead;
}

/*
    函数名：link_searchSelect
    函数功能：链表排序方式的选择，输出排序结果
    参数：需排序的链表的头节点 head，尾节点 tail
    返回值：无
*/
void link_searchSelect(ln_t head)
{
    printf("\t请选择检索的方式：\n");
    printf("\t\t1.指定 linkID 检索\n");
    printf("\t\t2.指定 交叉Link列表示Class番号 检索\n");
    printf("\t\t3.指定 查找岔路数 检索\n");
    printf("\t\t4.指定 道路名称 检索\n");
    printf("\t\t0.返回\n");
    printf("\t请选择：");

    int n = 0;
    fflush(stdin);
    scanf("%d", &n);    //输入选择的检索方式
    fflush(stdin);
    printf("\n");

    ln_t phead = NULL;  //用于保存查找结果链表的头节点
    switch(n) {
    case 1:
        printf("\t请输入 linkID ：");
        ULONG linkID = 0;
        fflush(stdin);
        scanf("%ld", &linkID);    //输入linkID
        fflush(stdin);
        printf("\n");
        phead = link_search_linkID(head, linkID);
        break;
    case 2:
        printf("\t请输入 交叉Link列表示Class番号 ：\n");
        UINT dispclass = 0;
        fflush(stdin);
        scanf("%hd", &dispclass);    //输入dispclass
        fflush(stdin);
        printf("\n");
        phead = link_search_dispclass(head, dispclass);
        break;
    case 3:
        printf("\t请输入 Link的Brunch(岔道数)数量 ：\n");
        UINT brunch = 0;
        fflush(stdin);
        scanf("%hd", &brunch);    //输入brunch
        fflush(stdin);
        printf("\n");
        phead = link_search_brunch(head, brunch);
        break;
    case 4:
        printf("\t请输入 道路名称 ：\n");
        char roadname[30] = "";
        fflush(stdin);
        scanf("%s", roadname);    //输入brunch
        fflush(stdin);
        printf("\n");
        phead = link_search_roadname(head, roadname);
        break;
    default:
        phead = NULL;
        return ;
    }

    exp_search_result(phead);   //输出排序结果

    phead = NULL;
}

