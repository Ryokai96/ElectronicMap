#ifndef FILEIO_H
#define FILEIO_H

#include "header.h"
#include <dirent.h> //用于目录操作，windows并没有这个库函数，使用visual c++的话，windows.h中提供了类似的操作函数

void readFile(md_t n, FILE* fl);    //从文件中读取一条数据
void writeFile(md_t n, FILE* fl);   //往文件中写入一条二进制数据
void printfFile(md_t n, FILE* fl);   //将一条数据按一定格式打印到文件中
void removeAllFile();   //删除除GTBL外当前data目录下所有文件

#endif // FILEIO_H
