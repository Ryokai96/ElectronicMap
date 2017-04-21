#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>    //c99支持

typedef char INT;
typedef unsigned char UCHAR;
typedef unsigned short UINT;
typedef unsigned long ULONG;

#define MC_GET_CHAR(__data__)  (*((char *)(__data__)))
#define MC_GET_SHORT(__data__)  ((UINT)(( ((UINT)(*((char *)(__data__))))<<8 )|( ((UINT)(*((char *)(__data__)+1)))&0x00ff )))
#define MC_GET_LONG(__data__)  ( ( ((ULONG)MC_GET_SHORT((__data__)))<<16 )|( ((ULONG)MC_GET_SHORT((char *)(__data__)+2))&0x0000ffff ) )
#define MC_GET_3BN(__data__)  ( ( ((ULONG)MC_GET_CHAR((__data__)))<<16 )|( ((ULONG)MC_GET_SHORT((char *)(__data__)+1))&0x0000ffff ) )

typedef struct mapData{
    UINT size;
    ULONG linkid;
    UINT roadnamesize;
    ULONG node;
    UCHAR* roadname;
} mapd_t, *md_t;

#define FILE_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/"  //文件夹路径
#define GTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/GTBL.dat"  //GTBL.dat文件路径
#define LINKGTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/LinkGTBL.dat"  //读取成链表后保存的文件文件路径
#define SORTGTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/SortGTBL.dat"  //排序后保存的二进制文件的文件路径
#define SOURCELINK_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/sourcelink.txt"  //排序后保存的文本文件的文件路径

//dataOp中函数声明
void mapDataInit(md_t temp);    //初始化mapData结构体
void getMapData(md_t n, FILE* fl);  //获得一条mapdata结构体类型的数据
void writeMapData(md_t n, FILE* fl);    //将一条mapdata结构体类型数据以二进制形式写入文件
void copyMapData(md_t dec, md_t src);   //
void printMapData(md_t n, FILE* fl);    //将一条mapdata结构体类型数据以文本形式写入文件
UINT get_roadnameflag(ULONG node);  //从结构体的node中获取roadnameflag数据
UINT get_brunch(ULONG node);    //从结构体的node中获取brunch数据
UINT get_dispclass(ULONG node); //从结构体的node中获取dispclass数据

int NFILE;  //用于记录创建了几次searchresult.txt

#endif // HEADER_H
