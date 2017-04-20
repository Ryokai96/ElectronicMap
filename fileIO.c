/*
	�ļ�����fileIO.c
	���������ڶ��ļ��Ĳ�����������ȡ��д��
*/

#include "fileIO.h"

/*
    ��������readFile
    �������ܣ��Ӷ������ļ��ж�ȡһ������
    ������Ҫ����Ķ��� n��Ҫ��ȡ���ļ�ָ�� fl
    ����ֵ����
*/
void readFile(md_t n, FILE* fl)
{
    //�����ȡ��ָ�����ݳ��ȵ����ݵĸ���
    int readbuf = 0;

    //��ʱ�����ȡ��������
    UINT i = 0;
    UINT size = 0;
    ULONG linkid = 0;
    UINT roadnamesize = 0;
    ULONG node = 0;
    UCHAR roadname[30] = "";

    if((readbuf = fread(&size, sizeof(UINT), 1, fl)) != 1)
    {
        printf("read size error!\n");
        exit(0);
    }
    n->size = MC_GET_SHORT(&size);

    if((readbuf = fread(&linkid, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("read linkid error!\n");
        exit(0);
    }
    n->linkid = MC_GET_LONG(&linkid);

    if((readbuf = fread(&roadnamesize, sizeof(UINT), 1, fl)) != 1)
    {
        printf("read roadnamesize error!\n");
        exit(0);
    }
    n->roadnamesize = n->size - 12;

    if((readbuf = fread(&node, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("read node error!\n");
        exit(0);
    }
    n->node = MC_GET_LONG(&node);

    if((readbuf = fread(roadname, sizeof(UCHAR), n->roadnamesize, fl)) != n->roadnamesize)
    {
        printf("read roadname error!\n");
        exit(0);
    }
    for(i = 0; i < n->roadnamesize; i++)
    {
        roadname[i] = MC_GET_CHAR(&roadname[i]);
    }
    n->roadname = (UCHAR *)malloc(sizeof(roadname)-4);
    strcpy((char *)n->roadname, (char *)&roadname[4]);

//    printf("%ld\t", n->linkid);
//    printf("%d\t", n->roadnamesize);
//    printf("%ld\t", n->node);
//    printf("%s", n->roadname);
//    printf("\n");
}

/*
    ��������readFile
    �������ܣ����ļ���д��һ������������
    ������Ҫ����Ķ��� n��Ҫ��ȡ���ļ�ָ�� fl
    ����ֵ����
*/
void writeFile(md_t n, FILE* fl)
{

}

/*
    ��������printfFile
    �������ܣ���һ�����ݰ�һ����ʽ��ӡ���ļ���
    ������Ҫд���Ķ��� n��Ҫд����ļ�ָ�� fl
    ����ֵ����
*/
void printfFile(md_t n, FILE* fl)
{
    fprintf(fl, "#linkid=%ld;", n->linkid);
    fprintf(fl, "roadnameflag=%hd;", get_roadnameflag(n->node));
    fprintf(fl, "brunch=%hd;", get_brunch(n->node));
    fprintf(fl, "dispclass=%hd;", get_dispclass(n->node));
    fprintf(fl, "roadname=%s", n->roadname);
    fprintf(fl, "\n");
}
