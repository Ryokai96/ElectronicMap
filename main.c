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
    int i = 0;
    ln_t node;

    while(!feof(fl_GTBL))
    {
        if(feof(fl_GTBL))
            break;
        node = (ln_t)malloc(sizeof(linkn_t));
        readFile(&node->data, fl_GTBL);
        node->prior = tail_l;
        tail_l->next = node;
        tail_l = node;
        tail_l->next = NULL;
        i++;
    }
    //writeFile(&n, fl_SOURCELINK);
    printf("\n%d", i);
    fclose(fl_GTBL);
//    fclose(fl_SOURCELINK);
    getchar();
    return 0;
}
