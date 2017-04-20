#include "header.h"
#include "fileIO.h"

/*
    函数名：mapDataInit
    函数功能：初始化mapData结构体
    参数：mapData结构体指针temp
    返回值：无
*/
void mapDataInit(md_t temp)
{
    temp->size = 0;
    temp->linkid = 0;
    temp->roadnamesize = 0;
    temp->node = 0;
    temp->roadname = NULL;
}

/*
    函数名：getMapDate
    函数功能：获得一条mapdata结构体类型的数据
    参数：用于存储数据的结构体指针 n，文件指针fl
    返回值：无
*/
void getMapData(md_t n, FILE* fl)
{
    readFile(n, fl);
}

/*
    函数名：get_roadnameflag
    函数功能：从结构体的node中获取roadnameflag数据
    参数：node
    返回值：roadnameflag
*/
UINT get_roadnameflag(ULONG node)
{
    return (((node)>>7) & 0x1);
}

/*
    函数名：get_brunch
    函数功能：从结构体的node中获取brunch数据
    参数：node
    返回值：brunch
*/
UINT get_brunch(ULONG node)
{
    return (((node)>>4) & 0x7);
}

/*
    函数名：get_dispclass
    函数功能：从结构体的node中获取dispclass数据
    参数：node
    返回值：dispclass
*/
UINT get_dispclass(ULONG node)
{
    return ((node) & 0x7);
}
