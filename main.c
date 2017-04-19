#include "fileIO.h"
#include "linkOp.h"
#include "menu.h"

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

//    FILE* fp;   //���ڼ�¼�ļ�β����λ��
//    fseek(fl_GTBL, 0, 2);   //���ļ��ڲ�ָ���ƶ����ļ�β��
//    fp = (FILE*)ftell(fl_GTBL);    //��¼�ļ�β����λ�ã�ftell����ֵ����Ϊlong������ǿ������ת�������������
//    fseek(fl_GTBL, 0, 0);   //���ļ��ڲ�ָ���ƶ����ļ�ͷ��

//    int i = 0;  //���ڼ�¼������
//    while(fp != (FILE*)ftell(fl_GTBL)) //���ļ��ڲ�ָ�뵽���ļ�β���������ѭ��
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

    ln_t phead, pnode;
    phead = link_sortSelect(head_l, tail_l);
    if(phead == NULL)
    {
        printf("back success\n");
        exit(0);
    }
    pnode = phead->next;
    while (pnode != NULL)
    {
        printf("%ld\n", pnode->data.linkid);
        pnode = pnode->next;
    }
    //writeFile(&n, fl_SOURCELINK);
    fclose(fl_GTBL);
    //fclose(fl_SOURCELINK);

    getchar();
    return 0;
}
