#ifndef FILEIO_H
#define FILEIO_H

#include "header.h"
#include <dirent.h> //����Ŀ¼������windows��û������⺯����ʹ��visual c++�Ļ���windows.h���ṩ�����ƵĲ�������

void readFile(md_t n, FILE* fl);    //���ļ��ж�ȡһ������
void writeFile(md_t n, FILE* fl);   //���ļ���д��һ������������
void printfFile(md_t n, FILE* fl);   //��һ�����ݰ�һ����ʽ��ӡ���ļ���
void removeAllFile();   //ɾ����GTBL�⵱ǰdataĿ¼�������ļ�

#endif // FILEIO_H
