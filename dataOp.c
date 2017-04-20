#include "header.h"
#include "fileIO.h"

/*
    ��������mapDataInit
    �������ܣ���ʼ��mapData�ṹ��
    ������mapData�ṹ��ָ��temp
    ����ֵ����
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
    ��������getMapDate
    �������ܣ����һ��mapdata�ṹ�����͵�����
    ���������ڴ洢���ݵĽṹ��ָ�� n���ļ�ָ��fl
    ����ֵ����
*/
void getMapData(md_t n, FILE* fl)
{
    readFile(n, fl);
}

/*
    ��������get_roadnameflag
    �������ܣ��ӽṹ���node�л�ȡroadnameflag����
    ������node
    ����ֵ��roadnameflag
*/
UINT get_roadnameflag(ULONG node)
{
    return (((node)>>7) & 0x1);
}

/*
    ��������get_brunch
    �������ܣ��ӽṹ���node�л�ȡbrunch����
    ������node
    ����ֵ��brunch
*/
UINT get_brunch(ULONG node)
{
    return (((node)>>4) & 0x7);
}

/*
    ��������get_dispclass
    �������ܣ��ӽṹ���node�л�ȡdispclass����
    ������node
    ����ֵ��dispclass
*/
UINT get_dispclass(ULONG node)
{
    return ((node) & 0x7);
}
