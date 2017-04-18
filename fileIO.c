#include "fileIO.h"

/*
    函数名：readFile
    函数功能：从文件中读取一条数据
    参数：要读入的对象 n，要读取的文件指针 fl
    返回值：无
*/
void readFile(md_t n, FILE* fl)
{
    int readbuf;
    int i;
    UINT size;
    ULONG linkid;
    UINT roadnamesize;
    ULONG node;
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

    printf("%ld\t", n->linkid);
    printf("%d\t", n->roadnamesize);
    printf("%ld\t", n->node);
    printf("%s", n->roadname);
    printf("\n");
}

/*
    函数名：writeFile
    函数功能：写入一条数据到文件中
    参数：要写出的对象 n，要写入的文件指针 fl
    返回值：无
*/
void writeFile(md_t n, FILE* fl)
{
    fprintf(fl,"#linkid=%ld;",n->linkid);
    fprintf(fl,"roadnameflag=%ld;",((n->node)>>7) & 0x1);
    fprintf(fl,"brunch=%ld;",((n->node)>>4) & 0x7);
    fprintf(fl,"dispclass=%ld;",(n->node) & 0x7);
    fprintf(fl, "roadname=%s", n->roadname);
    fprintf(fl,"\n");
}
