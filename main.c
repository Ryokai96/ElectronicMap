#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Macro.h"

typedef struct {
    UINT size;
    ULONG linkid;
    UINT roadnamesize;
    ULONG node;
    UCHAR* roadname;
} MAPD, *MD;

typedef struct linknode {
	MAPD data;
    MD next;
	MD prior;
} LINKN, *LN;

/*
	函数名：readFile
	参数：要读入的对象 n，要读取的文件指针 fl
	返回值：无
*/
void readFile(MD n, FILE* fl)
{
    int readbuf;
    int i;
    UINT size;
    ULONG linkid;
    UINT roadnamesize;
    ULONG node;
    UCHAR roadname[20] = "";
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
    printf("%ld", n->linkid);
    if((readbuf = fread(&roadnamesize, sizeof(UINT), 1, fl)) != 1)
    {
        printf("read roadnamesize error!\n");
        exit(0);
    }
    n->roadnamesize = MC_GET_SHORT(&roadnamesize);
    printf("%d", n->roadnamesize);
    if((readbuf = fread(&node, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("read node error!\n");
        exit(0);
    }
    n->node = MC_GET_LONG(&node);
    printf("%ld", n->node);
    if((readbuf = fread(&roadname, sizeof(UCHAR), n->roadnamesize, fl)) != n->roadnamesize)
    {
        printf("read roadname error!\n");
        exit(0);
    }
    for(i = 0; i < n->roadnamesize; i++)
    {
        roadname[i] = MC_GET_CHAR(&roadname[i]);
    }
	n->roadname = (char *)malloc(sizeof(roadname)-4);
	strcpy(n->roadname, &roadname[4]);
    printf("%s", n->roadname);
}

/*
	函数名：writeFile
	参数：要写出的对象 n，要写入的文件指针 fl
	返回值：无
*/
void writeFile(MD n, FILE* fl)
{
    fprintf(fl,"#linkid=%ld;",n->linkid);
    fprintf(fl,"roadnameflag=%ld;",((n->node)>>7) & 0x1);
    fprintf(fl,"brunch=%ld;",((n->node)>>4) & 0x7);
    fprintf(fl,"dispclass=%ld;",(n->node) & 0x7);
	fprintf(fl, "roadname=%s", n->roadname);
    fprintf(fl,"\n");
}

LN create_list()
{

}

int main(void)
{
    MAPD n;
    FILE* fl_GTBL;
    FILE* fl_SOURCELINK;
    if((fl_GTBL = fopen("C:/Users/Ryoukai/Documents/Visual Studio 2017/Projects/ElectronicMap/ElectronicMap/Date/GTBL.dat","rb+")) == NULL)
    {
        printf("GTBL open error!\n");
        exit(1);
    }
    if((fl_SOURCELINK = fopen("C:/Users/Ryoukai/Documents/Visual Studio 2017/Projects/ElectronicMap/ElectronicMap/Date/sourcelink.txt","at+")) == NULL)
    {
        printf("SOURCELINK open error!\n");
        exit(1);
    }
    readFile(&n, fl_GTBL);
    writeFile(&n, fl_SOURCELINK);
    fclose(fl_GTBL);
    fclose(fl_SOURCELINK);
	getchar();
    return 0;
}
