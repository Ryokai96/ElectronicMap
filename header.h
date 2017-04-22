#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>    //c99֧��

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

//#define FILE_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/"  //�ļ���·��
//#define GTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/GTBL.dat"  //GTBL.dat�ļ�·��
//#define LINKGTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/LinkGTBL.dat"  //��ȡ������󱣴���ļ��ļ�·��
//#define SORTGTBL_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/SortGTBL.dat"  //����󱣴�Ķ������ļ����ļ�·��
//#define SOURCELINK_PATH "D:/Qt/Qt5.2.1/Tools/QtCreator/bin/Electronic_map/Date/sourcelink.txt"  //����󱣴���ı��ļ����ļ�·��

#define FILE_PATH "C:/Users/Ryoukai/Documents/QT_Project/ElectronicMap/DATA/"   //�ļ���·��
#define GTBL_PATH "C:/Users/Ryoukai/Documents/QT_Project/ElectronicMap/DATA/GTBL.dat"  //GTBL.dat�ļ�·��
#define LINKGTBL_PATH "C:/Users/Ryoukai/Documents/QT_Project/ElectronicMap/DATA/LinkGTBL.dat"  //��ȡ������󱣴���ļ��ļ�·��
#define SORTGTBL_PATH "C:/Users/Ryoukai/Documents/QT_Project/ElectronicMap/DATA/SortGTBL.dat"  //����󱣴�Ķ������ļ����ļ�·��
#define SOURCELINK_PATH "C:/Users/Ryoukai/Documents/QT_Project/ElectronicMap/DATA/sourcelink.txt"  //����󱣴���ı��ļ����ļ�·��

//dataOp�к�������
void mapDataInit(md_t temp);    //��ʼ��mapData�ṹ��
void getMapData(md_t n, FILE* fl);  //���һ��mapdata�ṹ�����͵�����
void writeMapData(md_t n, FILE* fl);    //��һ��mapdata�ṹ�����������Զ�������ʽд���ļ�
void copyMapData(md_t dec, md_t src);   //����src��ֵ��dec
void showMapData(md_t n, FILE* fl);    //��һ��mapdata�ṹ�������������ı���ʽд���ļ�
void printMapData(md_t n);  //�����������ӡ������̨
UINT get_roadnameflag(ULONG node);  //�ӽṹ���node�л�ȡroadnameflag����
UINT get_brunch(ULONG node);    //�ӽṹ���node�л�ȡbrunch����
UINT get_dispclass(ULONG node); //�ӽṹ���node�л�ȡdispclass����

int NFILE;  //���ڼ�¼�����˼���searchresult.txt

#endif // HEADER_H
