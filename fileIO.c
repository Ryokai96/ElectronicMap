/*
	文件名：fileIO.c
	描述：用于对文件的操作，包括读取、写入
*/

#include "fileIO.h"

/*
    函数名：readFile
    函数功能：从二进制文件中读取一条数据
    参数：要读入的对象 n，要读取的文件指针 fl
    返回值：无
*/
void readFile(md_t n, FILE* fl)
{
    //保存读取的指定数据长度的数据的个数
    int readbuf = 0;

    //临时保存读取到的数据
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
    函数名：readFile
    函数功能：往文件中写入一条二进制数据
    参数：要读入的对象 n，要读取的文件指针 fl
    返回值：无
*/
void writeFile(md_t n, FILE* fl)
{

}

/*
    函数名：printfFile
    函数功能：将一条数据按一定格式打印到文件中
    参数：要写出的对象 n，要写入的文件指针 fl
    返回值：无
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
