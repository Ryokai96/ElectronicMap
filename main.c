#include "fileIO.h"
#include "linkOp.h"
#include "menu.h"

int main(void)
{
    FILE* fl_GTBL;

    FILE* fl_SOURCELINK;

    if((fl_GTBL = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        exit(1);
    }

    if((fl_SOURCELINK = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("SOURCELINK open error!\n");
        exit(1);
    }


    ln_t head = NULL;
    ln_t tail = NULL;
    createLinklist(fl_GTBL, &head, &tail);

    ln_t phead, pnode;
    phead = link_sortSelect(head, tail);
    if(phead == NULL)
    {
        printf("back success\n");
        exit(0);
    }
    pnode = phead->next;
    while (pnode != NULL)
    {
        printfFile(&pnode->data, fl_SOURCELINK);
        pnode = pnode->next;
    }
    //writeFile(&n, fl_SOURCELINK);
    link_searchSelect(head);
    fclose(fl_GTBL);
    fclose(fl_SOURCELINK);

    getchar();
    return 0;
}
