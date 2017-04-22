#include "fileOp.h"
#include "linkOp.h"
#include "treeOp.h"
#include "menu.h"

int main(void)
{
//    primary_menu();
    FILE* fl = NULL;
    tn_t top = NULL;
    if((fl = fopen(GTBL_PATH, "rb+")) == NULL)
    {
        printf("can't open GTBL.dat\n");
        return 0;
    }
    createTree(fl, top);
    fclose(fl);
    int num = 0;
    tree_num(top, &num);
    printf("%d\n", num);
    print_tree(top);

    fl = NULL;
    getchar();
    return 0;
}
