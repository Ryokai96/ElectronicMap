/*
    文件名：menu.c
    描述：程序使用菜单的生成，程序功能选择
*/

#include "menu.h"
/*
    函数名：primary_menu
    函数功能：程序主菜单
    参数：无
    返回值：无
*/
void primary_menu()
{
    printf("/*************************************************************************/\n");
    printf("/***                       电子地图信息统计系统                        ***/\n");
    printf("/*************************************************************************/\n");
    printf("\n");

    NFILE = 0;  //初始化NFILE
    int n = 5;  //用于记录用户选择的服务种类
    int m = 0;  //用于记录用户选择的读取文件方式

    while(n != 0)
    {
        printf("请选择服务的种类：\n");
        printf("\t1.读取文件(\"GTBL.dat\")\n");
        printf("\t2.排序并输出排序结果(\"SortGTBL.dat\")\n");
        printf("\t3.检索\n");
        printf("\t4.更新\n");
        printf("\t0.退出\n");
        printf("\t请选择：");

        fflush(stdin);
        scanf("%d", &n);    //输入选择的服务种类
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //读取文件的方式
            select_menu(m);    //转到相应的数据结构对应的菜单
            break;
        case 2:
            printf("please read file first\n\n");
            break;
        case 3:
            printf("please read file first\n\n");
            break;
        case 4:
            printf("please read file first\n\n");
            break;
        case 0:
            removeAllFile();
            exit(0);
        default:
            printf("\t请输入正确的选项\n");
        }
    }
}

/*
    函数名：readfile_menu
    函数功能：读取文件菜单
    参数：无
    返回值：返回以何种形式读取文件(1 代表链表，2 代表二叉查找树，0 代表未选择)
*/
int readfile_menu()
{
    printf("\t请选择读取文件的方式：\n");
    printf("\t\t1.链表\n");
    printf("\t\t2.二叉查找树\n");
    printf("\t\t3.红黑树\n");
    printf("\t\t0.返回\n");
    printf("\t请选择：");

    int n = -1;

    while(n == -1)
    {
        fflush(stdin);
        scanf("%d", &n);    //输入选择的排序方式
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 0:
            return 0;
        default:
            printf("\t请输入正确的选项\n");
            n = -1;
        }
    }

    return 0;
}

/*
    函数名：select_menu
    函数功能：进入与选择的数据结构对应的菜单
    参数：选择的数据结构(1 代表链表，2 代表二叉查找树)
    返回值：无
*/
void select_menu(int n)
{
    switch(n) {
    case 1:
        linklist_menu();
        break;
    case 2:
        tree_menu();
        break;
    case 3:
        rbtree_menu();
    default:
        return ;
    }
}

/*
    函数名：linklist_menu
    函数功能：链表存储格式对应菜单
    参数：无
    返回值：无
*/
void linklist_menu()
{
    printf("读取文件...\n");
    FILE* fl;
    if((fl = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        return ;
    }
    ln_t head = listInit();
    ln_t tail = head;
    printf("读取中...\n");
    createLinklist(fl, &head, &tail);
    fclose(fl);
    fl = NULL;
    printf("文件读取成功!\n");

    int n = 5;  //用于记录用户选择的服务种类
    int m = 0;  //用于记录用户选择的读取文件方式

    while(n != 0)
    {
        printf("\n");
        printf("请选择服务的种类：\n");
        printf("\t1.读取文件(\"GTBL.dat\")\n");
        printf("\t2.排序并输出排序结果(\"SortGTBL.dat\")\n");
        printf("\t3.检索\n");
        printf("\t4.删除\n");
        printf("\t5.插入\n");
        printf("\t6.更新\n");
        printf("\t0.退出\n");
        printf("\t请选择：");

        fflush(stdin);
        scanf("%d", &n);    //输入选择的服务种类
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //读取文件的方式
            select_menu(m);    //转到相应的数据结构对应的菜单
            break;
        case 2:
            link_sortSelect(head, tail);
            break;
        case 3:
            link_searchSelect(head);
            break;
        case 4:
            link_deleteSelect(head);
            break;
        case 5:
            link_insertMenu(&tail);
            break;
        case 6:
            if(remove(GTBL_PATH) == -1)
            {
                printf("remove GTBL.dat error\n");
            }
            else if(rename(SORTGTBL_PATH, GTBL_PATH) == -1)
            {
                printf("rename SortGTBL.dat error, is SortGTBL.dat exist?\n");
            }
            break;
        case 0:
            removeAllFile();
            exit(0);
        default:
            printf("\t请输入正确的选项\n");
        }
    }
}

/*
    函数名：link_sortSelect
    函数功能：链表排序方式的选择
    参数：需排序的链表的头节点 head，尾节点 tail
    返回值：无
*/
void link_sortSelect(ln_t head, ln_t tail)
{
    printf("\t请选择排序的方式：\n");
    printf("\t\t1.插入排序\n");
    printf("\t\t2.冒泡排序\n");
    printf("\t\t3.选择排序\n");
    printf("\t\t4.快速排序\n");
    printf("\t\t0.返回\n");
    printf("\t请选择：");

    int n = -1;
    ln_t phead = head;  //用于保存排序好的链表的头节点
    time_t start, end;  //记录排序函数运行开始时间和结束时间

    while (n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //输入选择的排序方式
        fflush(stdin);
        printf("\n");

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
            link_fast_sort(head->next, tail);   //0s
            end = time(NULL);
            break;
        case 0:
            phead = NULL;
            return ;
        default:
            printf("\t请输入正确的选项\n");
            n = -1;
        }
    }

    printf("***************************************************************************\n");
    printf("\b\bthe sort method have spend %d s\n", (int)difftime(end,start)); //打印排序函数运行时间
    printf("\b\b将其转存到二进制文件SortGTBL.dat\n");
    printf("***************************************************************************\n");

    exp_link_seq_result(phead);  //输出排序结果到二进制文件SortGTBL.dat

    phead = NULL;
}

/*
    函数名：link_searchSelect
    函数功能：链表查找方式的选择，输出查找结果
    参数：进行查找的链表的头节点 head
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

    int n = -1;
    ln_t phead = NULL;  //用于保存查找结果链表的头节点

    while(n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //输入选择的检索方式
        fflush(stdin);
        printf("\n");

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
            printf("\t请输入 交叉Link列表示Class番号 ：");
            UINT dispclass = 0;
            fflush(stdin);
            scanf("%hd", &dispclass);    //输入dispclass
            fflush(stdin);
            printf("\n");
            phead = link_search_dispclass(head, dispclass);
            break;
        case 3:
            printf("\t请输入 Link的Brunch(岔道数)数量 ：");
            UINT brunch = 0;
            fflush(stdin);
            scanf("%hd", &brunch);    //输入brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_brunch(head, brunch);
            break;
        case 4:
            printf("\t请输入 道路名称 ：");
            char roadname[30] = "";
            fflush(stdin);
            scanf("%s", roadname);    //输入brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_roadname(head, roadname);
            break;
        case 0:
            phead = NULL;
            return ;
        default:
            printf("\t请输入正确的选项\n");
            n = -1;
        }
    }

    exp_link_search_result(phead);   //输出查找结果

    phead = NULL;
}

/*
    函数名：link_deleteSelect
    函数功能：链表节点删除的菜单
    参数：链表的头节点 head
    返回值：无
*/
void link_deleteSelect(ln_t head)
{
    printf("\t你需要先检索出你需要删除的数据\n");
    printf("\t请选择检索的方式：\n");
    printf("\t\t1.指定 linkID 检索\n");
    printf("\t\t2.指定 交叉Link列表示Class番号 检索\n");
    printf("\t\t3.指定 查找岔路数 检索\n");
    printf("\t\t4.指定 道路名称 检索\n");
    printf("\t\t0.返回\n");
    printf("\t请选择：");

    int n = -1;
    ln_t phead = NULL;  //用于保存查找结果链表的头节点

    while(n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //输入选择的检索方式
        fflush(stdin);
        printf("\n");

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
            printf("\t请输入 交叉Link列表示Class番号 ：");
            UINT dispclass = 0;
            fflush(stdin);
            scanf("%hd", &dispclass);    //输入dispclass
            fflush(stdin);
            printf("\n");
            phead = link_search_dispclass(head, dispclass);
            break;
        case 3:
            printf("\t请输入 Link的Brunch(岔道数)数量 ：");
            UINT brunch = 0;
            fflush(stdin);
            scanf("%hd", &brunch);    //输入brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_brunch(head, brunch);
            break;
        case 4:
            printf("\t请输入 道路名称 ：");
            char roadname[30] = "";
            fflush(stdin);
            scanf("%s", roadname);    //输入brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_roadname(head, roadname);
            break;
        case 0:
            phead = NULL;
            return ;
        default:
            printf("\t请输入正确的选项\n");
            n = -1;
        }
    }

    exp_link_search_result(phead);   //输出查找结果

    printf("\n是否删除?\n");
    char reply[2] = "";
    do{
        printf("请选择 (y 删除，n 不删除)：");
        fflush(stdin);
        scanf("%s", reply);
        fflush(stdin);
        printf("\n");
        if(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0)
        {
            printf("请输入正确选项\n");
        }
    }while(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0);

    if(strcmp(reply, "y") == 0)
    {
        printf("删除中...\n");
        link_deleteSomeNode(head, phead);
        printf("删除成功\n");
    }

    phead = NULL;

}

/*
    函数名：link_insertMenu
    函数功能：链表节点插入的菜单
    参数：链表的尾指针 tail
    返回值：无
*/
void link_insertMenu(ln_t* tail)
{
    char reply[2] = "";
    mapd_t n;
    mapDataInit(&n);

    do{
        printf("\t请输入linkid：");
        fflush(stdin);
        scanf("%lu", &(n.linkid));
        fflush(stdin);
        n.node &= 0;
        UINT dispclass = 0;
        printf("\t请输入交叉link列表示class番号：");
        fflush(stdin);
        scanf("%hu", &dispclass);
        fflush(stdin);
        n.node |= dispclass;
        printf("\t请输入岔路数：");
        UINT brunch = 0;
        fflush(stdin);
        scanf("%hu", &brunch);
        fflush(stdin);
        n.node |= (brunch<<4);
        printf("\t是否输入道路名称：");
        do{
            printf("\t请选择 (y 输入，n 不输入)：");
            fflush(stdin);
            scanf("%s", reply);
            fflush(stdin);
            printf("\n");
            if(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0)
            {
                printf("\t请输入正确选项\n");
            }
        }while(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0);
        if(strcmp(reply, "y") == 0)
        {
            n.node |= (1 << 7);
            char roadname[30] = "";
            printf("\t请输入道路名称：");
            fflush(stdin);
            scanf("%s", roadname);
            fflush(stdin);
            n.roadname = (UCHAR *)malloc(strlen(roadname) + 1);
            memset(n.roadname, 0, strlen(roadname) + 1);
            strcpy((char *)n.roadname, roadname);
            n.roadnamesize = strlen(roadname) + 1;
        }
        else
        {
            n.roadnamesize = 0;
            n.node &= (~(1 << 7));
        }
        n.size = 12 + n.roadnamesize;

        ln_t node = (ln_t)malloc(sizeof(linkn_t));
        listInit(node);
        copyMapData(&(node->data), &n);
        insertToList((*tail), node);
        (*tail) = (*tail)->next;
        printf("\t是否继续插入？\n");
        do{
            printf("\t请选择 (y 继续，n 不继续)：");
            fflush(stdin);
            scanf("%s", reply);
            fflush(stdin);
            printf("\n");
            if(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0)
            {
                printf("\t请输入正确选项\n");
            }
        }while(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0);
    }while(strcmp(reply, "y") == 0);
}

/*
    函数名：tree_menu
    函数功能：二叉查找树存储格式对应菜单
    参数：无
    返回值：无
*/
void tree_menu()
{
    printf("读取文件...\n");
    FILE* fl;
    if((fl = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        return ;
    }
    tn_t top = NULL;
    printf("读取中...\n");
    createTree(fl, &top);
    fclose(fl);
    fl = NULL;
    printf("文件读取成功!\n");

    int n = 5;  //用于记录用户选择的服务种类
    int m = 0;  //用于记录用户选择的读取文件方式

    while(n != 0)
    {
        printf("\n");
        printf("请选择服务的种类：\n");
        printf("\t1.读取文件(\"GTBL.dat\")\n");
        printf("\t2.中序遍历并输出中序遍历结果(按linkid从小到大)到(\"SortGTBL.dat\")\n");
        printf("\t3.检索\n");
        printf("\t4.更新\n");
        printf("\t0.退出\n");
        printf("\t请选择：");

        fflush(stdin);
        scanf("%d", &n);    //输入选择的服务种类
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //读取文件的方式
            select_menu(m);    //转到相应的数据结构对应的菜单
            break;
        case 2:
            printf("***************************************************************************\n");
            printf("\b\b将其转存到二进制文件SortGTBL.dat\n");
            printf("***************************************************************************\n");
            exp_tree_seq_result(top);  //输出排序结果到二进制文件SortGTBL.dat
            break;
        case 3:
            tree_searchSelect(top);
            break;
        case 4:
            if(remove(GTBL_PATH) == -1)
            {
                printf("remove GTBL.dat error\n");
            }
            else if(rename(SORTGTBL_PATH, GTBL_PATH) == -1)
            {
                printf("rename SortGTBL.dat error, is SortGTBL.dat exist?\n");
            }
            break;
        case 0:
            removeAllFile();
            exit(0);
        default:
            printf("\t请输入正确的选项\n");
        }
    }
}

/*
    函数名：tree_searchSelect
    函数功能：二叉查找树查找条件的输入，输出查找结果
    参数：进行查找的树的顶端节点 top
    返回值：无
*/
void tree_searchSelect(tn_t top)
{
    printf("\t请选择检索的方式：\n");
    printf("\t\t1.指定 linkID 检索\n");
    printf("\t\t2.指定 交叉Link列表示Class番号 检索\n");
    printf("\t\t3.指定 查找岔路数 检索\n");
    printf("\t\t4.指定 道路名称 检索\n");
    printf("\t\t0.返回\n");
    printf("\t请选择：");

    int n = -1;
    tn_t ptop = NULL;  //用于保存查找结果

    while(n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //输入选择的检索方式
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            printf("\t请输入 linkID ：");
            ULONG linkID = 0;
            fflush(stdin);
            scanf("%ld", &linkID);    //输入linkID
            fflush(stdin);
            printf("\n");
            ptop = tree_search_linkID(top, linkID);
            break;
        case 2:
            printf("\t请输入 交叉Link列表示Class番号 ：");
            UINT dispclass = 0;
            fflush(stdin);
            scanf("%hd", &dispclass);    //输入dispclass
            fflush(stdin);
            printf("\n");
            tree_search_dispclass(top, dispclass, &ptop);
            break;
        case 3:
            printf("\t请输入 Link的Brunch(岔道数)数量 ：");
            UINT brunch = 0;
            fflush(stdin);
            scanf("%hd", &brunch);    //输入brunch
            fflush(stdin);
            printf("\n");
            tree_search_brunch(top, brunch, &ptop);
            break;
        case 4:
            printf("\t请输入 道路名称 ：");
            char roadname[30] = "";
            fflush(stdin);
            scanf("%s", roadname);    //输入brunch
            fflush(stdin);
            printf("\n");
            tree_search_roadname(top, roadname, &ptop);
            break;
        case 0:
            ptop = NULL;
            return ;
        default:
            printf("\t请输入正确的选项\n");
            n = -1;
        }
    }

    exp_tree_search_result(ptop);   //输出查找结果

    ptop = NULL;
}

/*
    函数名：rbtree_menu
    函数功能：红黑树存储格式对应菜单
    参数：无
    返回值：无
*/
void rbtree_menu()
{
    printf("读取文件...\n");
    FILE* fl;
    if((fl = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        return ;
    }
    rbr_t root = (rbr_t)malloc(sizeof(rbroot_t));
    root->node = NULL;
    printf("读取中...\n");
    createRBTree(fl, root);
    fclose(fl);
    fl = NULL;
    printf("文件读取成功!\n");

    int n = 5;  //用于记录用户选择的服务种类
    int m = 0;  //用于记录用户选择的读取文件方式

    while(n != 0)
    {
        printf("\n");
        printf("请选择服务的种类：\n");
        printf("\t1.读取文件(\"GTBL.dat\")\n");
        printf("\t2.中序遍历并输出中序遍历结果(按linkid从小到大)到(\"SortGTBL.dat\")\n");
        printf("\t3.更新\n");
        printf("\t0.退出\n");
        printf("\t请选择：");

        fflush(stdin);
        scanf("%d", &n);    //输入选择的服务种类
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //读取文件的方式
            select_menu(m);    //转到相应的数据结构对应的菜单
            break;
        case 2:
            printf("***************************************************************************\n");
            printf("\b\b将其转存到二进制文件SortGTBL.dat\n");
            printf("***************************************************************************\n");
            exp_rbtree_seq_result(root);  //输出排序结果到二进制文件SortGTBL.dat
            break;
        case 3:
            if(remove(GTBL_PATH) == -1)
            {
                printf("remove GTBL.dat error\n");
            }
            else if(rename(SORTGTBL_PATH, GTBL_PATH) == -1)
            {
                printf("rename SortGTBL.dat error, is SortGTBL.dat exist?\n");
            }
            break;
        case 0:
            removeAllFile();
            exit(0);
        default:
            printf("\t请输入正确的选项\n");
        }
    }
}
