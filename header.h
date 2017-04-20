#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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

#define FILE_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/"
#define GTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/GTBL.dat"
#define SOURCELINK_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/sourcelink.txt"
#define SOURCERESULT_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/searchresult.txt"

//dataOp�к�������
void mapDataInit(md_t temp);    //��ʼ��mapData�ṹ��
void getMapData(md_t n, FILE* fl);  //���һ��mapdata�ṹ�����͵�����
UINT get_roadnameflag(ULONG node);  //�ӽṹ���node�л�ȡroadnameflag����
UINT get_brunch(ULONG node);    //�ӽṹ���node�л�ȡbrunch����
UINT get_dispclass(ULONG node); //�ӽṹ���node�л�ȡdispclass����

#endif // HEADER_H
