#include "header.h"
#include "fileIO.h"
#include "linkOp.h"

void delay(int ms)
{
	int i, j;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 535; j++);
}

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

    FILE* fp;   //用于记录文件尾部的位置
    fseek(fl_GTBL, 0, 2);   //把文件内部指针移动到文件尾部
    fp = ftell(fl_GTBL);    //记录文件尾部的位置
    fseek(fl_GTBL, 0, 0);   //把文件内部指针移动到文件头部

    while(fp != ftell(fl_GTBL)) //当文件内部指针到了文件尾部，则结束循环
    {
        node = (ln_t)malloc(sizeof(linkn_t));
        readFile(&node->data, fl_GTBL);
        tail_l->next = node;
        tail_l = node;
        tail_l->next = NULL;
    }
	delay(2000);
	head_l = insert_sort(head_l);
	tail_l = head_l->next;
	while (tail_l != NULL)
	{
		printf("%ld\n", tail_l->data.linkid);
	}
    //writeFile(&n, fl_SOURCELINK);
    fclose(fl_GTBL);
    //fclose(fl_SOURCELINK);
    free(fp);
    getchar();
    return 0;
}
