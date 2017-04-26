/*
    �ļ�����menu.c
    ����������ʹ�ò˵������ɣ�������ѡ��
*/

#include "menu.h"
/*
    ��������primary_menu
    �������ܣ��������˵�
    ��������
    ����ֵ����
*/
void primary_menu()
{
    printf("/*************************************************************************/\n");
    printf("/***                       ���ӵ�ͼ��Ϣͳ��ϵͳ                        ***/\n");
    printf("/*************************************************************************/\n");
    printf("\n");

    NFILE = 0;  //��ʼ��NFILE
    int n = 5;  //���ڼ�¼�û�ѡ��ķ�������
    int m = 0;  //���ڼ�¼�û�ѡ��Ķ�ȡ�ļ���ʽ

    while(n != 0)
    {
        printf("��ѡ���������ࣺ\n");
        printf("\t1.��ȡ�ļ�(\"GTBL.dat\")\n");
        printf("\t2.�������������(\"SortGTBL.dat\")\n");
        printf("\t3.����\n");
        printf("\t4.����\n");
        printf("\t0.�˳�\n");
        printf("\t��ѡ��");

        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ķ�������
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //��ȡ�ļ��ķ�ʽ
            select_menu(m);    //ת����Ӧ�����ݽṹ��Ӧ�Ĳ˵�
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
            printf("\t��������ȷ��ѡ��\n");
        }
    }
}

/*
    ��������readfile_menu
    �������ܣ���ȡ�ļ��˵�
    ��������
    ����ֵ�������Ժ�����ʽ��ȡ�ļ�(1 ��������2 ��������������0 ����δѡ��)
*/
int readfile_menu()
{
    printf("\t��ѡ���ȡ�ļ��ķ�ʽ��\n");
    printf("\t\t1.����\n");
    printf("\t\t2.���������\n");
    printf("\t\t3.�����\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = -1;

    while(n == -1)
    {
        fflush(stdin);
        scanf("%d", &n);    //����ѡ�������ʽ
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
            printf("\t��������ȷ��ѡ��\n");
            n = -1;
        }
    }

    return 0;
}

/*
    ��������select_menu
    �������ܣ�������ѡ������ݽṹ��Ӧ�Ĳ˵�
    ������ѡ������ݽṹ(1 ��������2 ������������)
    ����ֵ����
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
    ��������linklist_menu
    �������ܣ�����洢��ʽ��Ӧ�˵�
    ��������
    ����ֵ����
*/
void linklist_menu()
{
    printf("��ȡ�ļ�...\n");
    FILE* fl;
    if((fl = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        return ;
    }
    ln_t head = listInit();
    ln_t tail = head;
    printf("��ȡ��...\n");
    createLinklist(fl, &head, &tail);
    fclose(fl);
    fl = NULL;
    printf("�ļ���ȡ�ɹ�!\n");

    int n = 5;  //���ڼ�¼�û�ѡ��ķ�������
    int m = 0;  //���ڼ�¼�û�ѡ��Ķ�ȡ�ļ���ʽ

    while(n != 0)
    {
        printf("\n");
        printf("��ѡ���������ࣺ\n");
        printf("\t1.��ȡ�ļ�(\"GTBL.dat\")\n");
        printf("\t2.�������������(\"SortGTBL.dat\")\n");
        printf("\t3.����\n");
        printf("\t4.ɾ��\n");
        printf("\t5.����\n");
        printf("\t6.����\n");
        printf("\t0.�˳�\n");
        printf("\t��ѡ��");

        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ķ�������
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //��ȡ�ļ��ķ�ʽ
            select_menu(m);    //ת����Ӧ�����ݽṹ��Ӧ�Ĳ˵�
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
            printf("\t��������ȷ��ѡ��\n");
        }
    }
}

/*
    ��������link_sortSelect
    �������ܣ���������ʽ��ѡ��
    ������������������ͷ�ڵ� head��β�ڵ� tail
    ����ֵ����
*/
void link_sortSelect(ln_t head, ln_t tail)
{
    printf("\t��ѡ������ķ�ʽ��\n");
    printf("\t\t1.��������\n");
    printf("\t\t2.ð������\n");
    printf("\t\t3.ѡ������\n");
    printf("\t\t4.��������\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = -1;
    ln_t phead = head;  //���ڱ�������õ������ͷ�ڵ�
    time_t start, end;  //��¼���������п�ʼʱ��ͽ���ʱ��

    while (n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //����ѡ�������ʽ
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
            printf("\t��������ȷ��ѡ��\n");
            n = -1;
        }
    }

    printf("***************************************************************************\n");
    printf("\b\bthe sort method have spend %d s\n", (int)difftime(end,start)); //��ӡ����������ʱ��
    printf("\b\b����ת�浽�������ļ�SortGTBL.dat\n");
    printf("***************************************************************************\n");

    exp_link_seq_result(phead);  //������������������ļ�SortGTBL.dat

    phead = NULL;
}

/*
    ��������link_searchSelect
    �������ܣ�������ҷ�ʽ��ѡ��������ҽ��
    ���������в��ҵ������ͷ�ڵ� head
    ����ֵ����
*/
void link_searchSelect(ln_t head)
{
    printf("\t��ѡ������ķ�ʽ��\n");
    printf("\t\t1.ָ�� linkID ����\n");
    printf("\t\t2.ָ�� ����Link�б�ʾClass���� ����\n");
    printf("\t\t3.ָ�� ���Ҳ�·�� ����\n");
    printf("\t\t4.ָ�� ��·���� ����\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = -1;
    ln_t phead = NULL;  //���ڱ�����ҽ�������ͷ�ڵ�

    while(n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ļ�����ʽ
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            printf("\t������ linkID ��");
            ULONG linkID = 0;
            fflush(stdin);
            scanf("%ld", &linkID);    //����linkID
            fflush(stdin);
            printf("\n");
            phead = link_search_linkID(head, linkID);
            break;
        case 2:
            printf("\t������ ����Link�б�ʾClass���� ��");
            UINT dispclass = 0;
            fflush(stdin);
            scanf("%hd", &dispclass);    //����dispclass
            fflush(stdin);
            printf("\n");
            phead = link_search_dispclass(head, dispclass);
            break;
        case 3:
            printf("\t������ Link��Brunch(�����)���� ��");
            UINT brunch = 0;
            fflush(stdin);
            scanf("%hd", &brunch);    //����brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_brunch(head, brunch);
            break;
        case 4:
            printf("\t������ ��·���� ��");
            char roadname[30] = "";
            fflush(stdin);
            scanf("%s", roadname);    //����brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_roadname(head, roadname);
            break;
        case 0:
            phead = NULL;
            return ;
        default:
            printf("\t��������ȷ��ѡ��\n");
            n = -1;
        }
    }

    exp_link_search_result(phead);   //������ҽ��

    phead = NULL;
}

/*
    ��������link_deleteSelect
    �������ܣ�����ڵ�ɾ���Ĳ˵�
    �����������ͷ�ڵ� head
    ����ֵ����
*/
void link_deleteSelect(ln_t head)
{
    printf("\t����Ҫ�ȼ���������Ҫɾ��������\n");
    printf("\t��ѡ������ķ�ʽ��\n");
    printf("\t\t1.ָ�� linkID ����\n");
    printf("\t\t2.ָ�� ����Link�б�ʾClass���� ����\n");
    printf("\t\t3.ָ�� ���Ҳ�·�� ����\n");
    printf("\t\t4.ָ�� ��·���� ����\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = -1;
    ln_t phead = NULL;  //���ڱ�����ҽ�������ͷ�ڵ�

    while(n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ļ�����ʽ
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            printf("\t������ linkID ��");
            ULONG linkID = 0;
            fflush(stdin);
            scanf("%ld", &linkID);    //����linkID
            fflush(stdin);
            printf("\n");
            phead = link_search_linkID(head, linkID);
            break;
        case 2:
            printf("\t������ ����Link�б�ʾClass���� ��");
            UINT dispclass = 0;
            fflush(stdin);
            scanf("%hd", &dispclass);    //����dispclass
            fflush(stdin);
            printf("\n");
            phead = link_search_dispclass(head, dispclass);
            break;
        case 3:
            printf("\t������ Link��Brunch(�����)���� ��");
            UINT brunch = 0;
            fflush(stdin);
            scanf("%hd", &brunch);    //����brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_brunch(head, brunch);
            break;
        case 4:
            printf("\t������ ��·���� ��");
            char roadname[30] = "";
            fflush(stdin);
            scanf("%s", roadname);    //����brunch
            fflush(stdin);
            printf("\n");
            phead = link_search_roadname(head, roadname);
            break;
        case 0:
            phead = NULL;
            return ;
        default:
            printf("\t��������ȷ��ѡ��\n");
            n = -1;
        }
    }

    exp_link_search_result(phead);   //������ҽ��

    printf("\n�Ƿ�ɾ��?\n");
    char reply[2] = "";
    do{
        printf("��ѡ�� (y ɾ����n ��ɾ��)��");
        fflush(stdin);
        scanf("%s", reply);
        fflush(stdin);
        printf("\n");
        if(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0)
        {
            printf("��������ȷѡ��\n");
        }
    }while(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0);

    if(strcmp(reply, "y") == 0)
    {
        printf("ɾ����...\n");
        link_deleteSomeNode(head, phead);
        printf("ɾ���ɹ�\n");
    }

    phead = NULL;

}

/*
    ��������link_insertMenu
    �������ܣ�����ڵ����Ĳ˵�
    �����������βָ�� tail
    ����ֵ����
*/
void link_insertMenu(ln_t* tail)
{
    char reply[2] = "";
    mapd_t n;
    mapDataInit(&n);

    do{
        printf("\t������linkid��");
        fflush(stdin);
        scanf("%lu", &(n.linkid));
        fflush(stdin);
        n.node &= 0;
        UINT dispclass = 0;
        printf("\t�����뽻��link�б�ʾclass���ţ�");
        fflush(stdin);
        scanf("%hu", &dispclass);
        fflush(stdin);
        n.node |= dispclass;
        printf("\t�������·����");
        UINT brunch = 0;
        fflush(stdin);
        scanf("%hu", &brunch);
        fflush(stdin);
        n.node |= (brunch<<4);
        printf("\t�Ƿ������·���ƣ�");
        do{
            printf("\t��ѡ�� (y ���룬n ������)��");
            fflush(stdin);
            scanf("%s", reply);
            fflush(stdin);
            printf("\n");
            if(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0)
            {
                printf("\t��������ȷѡ��\n");
            }
        }while(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0);
        if(strcmp(reply, "y") == 0)
        {
            n.node |= (1 << 7);
            char roadname[30] = "";
            printf("\t�������·���ƣ�");
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
        printf("\t�Ƿ�������룿\n");
        do{
            printf("\t��ѡ�� (y ������n ������)��");
            fflush(stdin);
            scanf("%s", reply);
            fflush(stdin);
            printf("\n");
            if(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0)
            {
                printf("\t��������ȷѡ��\n");
            }
        }while(strcmp(reply, "y") != 0 && strcmp(reply, "n") != 0);
    }while(strcmp(reply, "y") == 0);
}

/*
    ��������tree_menu
    �������ܣ�����������洢��ʽ��Ӧ�˵�
    ��������
    ����ֵ����
*/
void tree_menu()
{
    printf("��ȡ�ļ�...\n");
    FILE* fl;
    if((fl = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        return ;
    }
    tn_t top = NULL;
    printf("��ȡ��...\n");
    createTree(fl, &top);
    fclose(fl);
    fl = NULL;
    printf("�ļ���ȡ�ɹ�!\n");

    int n = 5;  //���ڼ�¼�û�ѡ��ķ�������
    int m = 0;  //���ڼ�¼�û�ѡ��Ķ�ȡ�ļ���ʽ

    while(n != 0)
    {
        printf("\n");
        printf("��ѡ���������ࣺ\n");
        printf("\t1.��ȡ�ļ�(\"GTBL.dat\")\n");
        printf("\t2.����������������������(��linkid��С����)��(\"SortGTBL.dat\")\n");
        printf("\t3.����\n");
        printf("\t4.����\n");
        printf("\t0.�˳�\n");
        printf("\t��ѡ��");

        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ķ�������
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //��ȡ�ļ��ķ�ʽ
            select_menu(m);    //ת����Ӧ�����ݽṹ��Ӧ�Ĳ˵�
            break;
        case 2:
            printf("***************************************************************************\n");
            printf("\b\b����ת�浽�������ļ�SortGTBL.dat\n");
            printf("***************************************************************************\n");
            exp_tree_seq_result(top);  //������������������ļ�SortGTBL.dat
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
            printf("\t��������ȷ��ѡ��\n");
        }
    }
}

/*
    ��������tree_searchSelect
    �������ܣ�����������������������룬������ҽ��
    ���������в��ҵ����Ķ��˽ڵ� top
    ����ֵ����
*/
void tree_searchSelect(tn_t top)
{
    printf("\t��ѡ������ķ�ʽ��\n");
    printf("\t\t1.ָ�� linkID ����\n");
    printf("\t\t2.ָ�� ����Link�б�ʾClass���� ����\n");
    printf("\t\t3.ָ�� ���Ҳ�·�� ����\n");
    printf("\t\t4.ָ�� ��·���� ����\n");
    printf("\t\t0.����\n");
    printf("\t��ѡ��");

    int n = -1;
    tn_t ptop = NULL;  //���ڱ�����ҽ��

    while(n == -1) {
        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ļ�����ʽ
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            printf("\t������ linkID ��");
            ULONG linkID = 0;
            fflush(stdin);
            scanf("%ld", &linkID);    //����linkID
            fflush(stdin);
            printf("\n");
            ptop = tree_search_linkID(top, linkID);
            break;
        case 2:
            printf("\t������ ����Link�б�ʾClass���� ��");
            UINT dispclass = 0;
            fflush(stdin);
            scanf("%hd", &dispclass);    //����dispclass
            fflush(stdin);
            printf("\n");
            tree_search_dispclass(top, dispclass, &ptop);
            break;
        case 3:
            printf("\t������ Link��Brunch(�����)���� ��");
            UINT brunch = 0;
            fflush(stdin);
            scanf("%hd", &brunch);    //����brunch
            fflush(stdin);
            printf("\n");
            tree_search_brunch(top, brunch, &ptop);
            break;
        case 4:
            printf("\t������ ��·���� ��");
            char roadname[30] = "";
            fflush(stdin);
            scanf("%s", roadname);    //����brunch
            fflush(stdin);
            printf("\n");
            tree_search_roadname(top, roadname, &ptop);
            break;
        case 0:
            ptop = NULL;
            return ;
        default:
            printf("\t��������ȷ��ѡ��\n");
            n = -1;
        }
    }

    exp_tree_search_result(ptop);   //������ҽ��

    ptop = NULL;
}

/*
    ��������rbtree_menu
    �������ܣ�������洢��ʽ��Ӧ�˵�
    ��������
    ����ֵ����
*/
void rbtree_menu()
{
    printf("��ȡ�ļ�...\n");
    FILE* fl;
    if((fl = fopen(GTBL_PATH,"rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        return ;
    }
    rbr_t root = (rbr_t)malloc(sizeof(rbroot_t));
    root->node = NULL;
    printf("��ȡ��...\n");
    createRBTree(fl, root);
    fclose(fl);
    fl = NULL;
    printf("�ļ���ȡ�ɹ�!\n");

    int n = 5;  //���ڼ�¼�û�ѡ��ķ�������
    int m = 0;  //���ڼ�¼�û�ѡ��Ķ�ȡ�ļ���ʽ

    while(n != 0)
    {
        printf("\n");
        printf("��ѡ���������ࣺ\n");
        printf("\t1.��ȡ�ļ�(\"GTBL.dat\")\n");
        printf("\t2.����������������������(��linkid��С����)��(\"SortGTBL.dat\")\n");
        printf("\t3.����\n");
        printf("\t0.�˳�\n");
        printf("\t��ѡ��");

        fflush(stdin);
        scanf("%d", &n);    //����ѡ��ķ�������
        fflush(stdin);
        printf("\n");

        switch(n) {
        case 1:
            m = readfile_menu();    //��ȡ�ļ��ķ�ʽ
            select_menu(m);    //ת����Ӧ�����ݽṹ��Ӧ�Ĳ˵�
            break;
        case 2:
            printf("***************************************************************************\n");
            printf("\b\b����ת�浽�������ļ�SortGTBL.dat\n");
            printf("***************************************************************************\n");
            exp_rbtree_seq_result(root);  //������������������ļ�SortGTBL.dat
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
            printf("\t��������ȷ��ѡ��\n");
        }
    }
}
