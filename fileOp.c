/*
    文件名：fileOp.c
    描述：用于对文件的操作，包括读取、写入，删除文件
*/

#include "fileOp.h"

/*
    函数名：readFile
    函数功能：从二进制文件中读取一条数据
    参数：要读入的对象 n，要读取的文件指针 fl
    返回值：无
*/
void readFile(md_t n, FILE* fl)
{
    static int j = 0;
    j++;
    //临时保存读取到的数据
    UINT i = 0;
    UINT size = 0;
    ULONG linkid = 0;
    UINT roadnamesize = 0;
    ULONG node = 0;
    UCHAR roadname[30] = "";

    if((fread(&size, sizeof(UINT), 1, fl)) != 1)
    {
        printf("read size error!\n");
        return ;
    }
    n->size = MC_GET_SHORT(&size);

    if((fread(&linkid, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("read linkid error!\n");
        return ;
    }
    n->linkid = MC_GET_LONG(&linkid);

    if((fread(&roadnamesize, sizeof(UINT), 1, fl)) != 1)
    {
        printf("read roadnamesize error!\n");
        return ;
    }
    n->roadnamesize = n->size - 12;

    if((fread(&node, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("read node error!\n");
        return ;
    }
    n->node = MC_GET_LONG(&node);

    if((fread(roadname, sizeof(UCHAR), n->roadnamesize, fl)) != n->roadnamesize)
    {
        printf("read roadname error!\n");
        return ;
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
    函数名：writeFile
    函数功能：往文件中写入一条二进制数据
    参数：要读入的对象 n，要读取的文件指针 fl
    返回值：无
*/
void writeFile(md_t n, FILE* fl)
{
    UINT size = MC_GET_SHORT(&(n->size));
    ULONG linkid = MC_GET_LONG(&(n->linkid));
    UINT roadnamesize = MC_GET_SHORT(&(n->roadnamesize));
    ULONG node = MC_GET_LONG(&(n->node));

    if((fwrite(&size, sizeof(UINT), 1, fl)) != 1)
    {
        printf("write size error!\n");
        return ;
    }
    if((fwrite(&linkid, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("write linkid error!\n");
        return ;
    }
    if((fwrite(&roadnamesize, sizeof(UINT), 1, fl)) != 1)
    {
        printf("write roadnamesize error!\n");
        return ;
    }
    if((fwrite(&node, sizeof(ULONG), 1, fl)) != 1)
    {
        printf("write node error!\n");
        return ;
    }

    if(n->roadnamesize != 0)
    {
        UCHAR roadname[30] = "１＝";
        strcat((char*)roadname, (char*)n->roadname);
        int i = 0;
        for(i = 0; i < n->roadnamesize; i++)
        {
            roadname[i] = MC_GET_CHAR(&roadname[i]);
        }
        if((fwrite(roadname, sizeof(UCHAR), n->roadnamesize, fl)) != n->roadnamesize)
        {
            printf("write roadname error!\n");
            return ;
        }

    }
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

/*
    函数名：removeAllFile
    函数功能：删除除GTBL外当前data目录下所有文件
    参数：无
    返回值：无
*/
void removeAllFile()
{
    printf("delete scratch file...\n");
    DIR* dir;
    struct dirent* ptr;
    dir = opendir(FILE_PATH); //打开data目录

    char* dpath = (char*)malloc(strlen(FILE_PATH) + strlen(".") + 1);
    memset(dpath, 0, strlen(FILE_PATH) + strlen(".") + 1);  //清空字符串
    strcat(dpath, FILE_PATH);
    strcat(dpath, ".");

    char* ddpath = (char*)malloc(strlen(FILE_PATH) + strlen("..") + 1);
    memset(ddpath, 0, strlen(FILE_PATH) + strlen(".") + 1);  //清空字符串
    strcat(ddpath, FILE_PATH);
    strcat(ddpath, "..");

    char* file_list = NULL;

    while((ptr = readdir(dir)) != NULL) //循环读取目录
    {
        file_list = (char*)malloc(strlen(FILE_PATH) + strlen(ptr->d_name) + 1);
        memset(file_list, 0, strlen(FILE_PATH) + strlen(ptr->d_name) + 1);  //清空字符串
        strcat(file_list, FILE_PATH);
        strcat(file_list, ptr->d_name);

        if((strcmp(GTBL_PATH, file_list) != 0) && (strcmp(file_list, dpath) != 0) && (strcmp(file_list, ddpath) != 0))
        {
            if(remove(file_list) == -1)
            {
                printf("remove %s error\n", ptr->d_name);
            }
        }
    }

    closedir(dir);

    ptr = NULL;
    dpath = NULL;
    ddpath = NULL;
    file_list = NULL;

    printf("delete complete\n");
}
