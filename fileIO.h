#ifndef FILEIO_H
#define FILEIO_H

#include "header.h"

void readFile(md_t n, FILE* fl);    //从文件中读取一条数据
void writeFile(md_t n, FILE* fl);   //写入一条数据到文件中


#endif // FILEIO_H
