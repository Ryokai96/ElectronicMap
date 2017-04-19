#include "header.h"
#include "fileIO.h"
#include "linkOp.h"


int main(void)
{
    FILE* fl_GTBL;
//    FILE* fl_SOURCELINK;
    if((fl_GTBL = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        exit(1);
    }
//    if((fl_SOURCELINK = fopen(SOURCELINK_PATH,"at+")) == NULL)
//    {
//        printf("SOURCELINK open error!\n");
//        exit(1);
//    }
    ln_t tail_l;
    ln_t head_l = listInit();
    tail_l = head_l;
    ln_t node;

//    FILE* fp;   //用于记录文件尾部的位置
//    fseek(fl_GTBL, 0, 2);   //把文件内部指针移动到文件尾部
//    fp = (FILE*)ftell(fl_GTBL);    //记录文件尾部的位置，ftell返回值类型为long，进行强制类型转换避免产生警告
//    fseek(fl_GTBL, 0, 0);   //把文件内部指针移动到文件头部

//    int i = 0;  //用于记录链表长度
//    while(fp != (FILE*)ftell(fl_GTBL)) //当文件内部指针到了文件尾部，则结束循环
//    {
//        node = (ln_t)malloc(sizeof(linkn_t));
//        readFile(&node->data, fl_GTBL);
//        tail_l->next = node;
//        tail_l = node;
//        tail_l->next = NULL;
//        i++;
//    }

    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++)
    {
        node = (ln_t)malloc(sizeof(linkn_t));
        readFile(&node->data, fl_GTBL);
        tail_l->next = node;
        tail_l = tail_l->next;
        tail_l->next = NULL;
        j++;
    }


//    tail_l = link_insert_sort(head_l);
//    tail_l = link_bubble_sort(head_l);
//    tail_l = link_select_sort(head_l);
//    tail_l = tail_l->next;
    link_fast_sort(head_l->next, tail_l);
    tail_l = head_l->next;
    if(tail_l == NULL)
    {
        printf("sort error\n");
        exit(0);
    }
    while (tail_l != NULL)
    {
        printf("%ld\n", tail_l->data.linkid);
        tail_l = tail_l->next;
    }
    //writeFile(&n, fl_SOURCELINK);
    fclose(fl_GTBL);
    //fclose(fl_SOURCELINK);

    getchar();
    return 0;
}
