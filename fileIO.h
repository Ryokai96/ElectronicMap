#ifndef FILEIO_H
#define FILEIO_H

#include "header.h"

void readFile(md_t n, FILE* fl);    //从文件中读取一条数据
void printfFile(md_t n, FILE* fl);   //将一条数据按一定格式打印到文件中

#endif // FILEIO_H
