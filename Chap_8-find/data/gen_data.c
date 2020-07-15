#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>   //用了uint16_t
#include <time.h>

#include "keytype.h"
/***********************************************************
 * 随机产生len个数据，并写入文件
 * 文件开头的size个长度里，先写入有多少个数据，然后才是数据
 * 
 * 使用：
 * $ gcc gen_data.c -o gen_data
 * $ gen_data 数字n（产生n个数据）
 * *********************************************************/
const KeyType limit = 65535u;
const unsigned maxn = 20480u;
const unsigned size = sizeof(KeyType);
const char *datafile = "benchmark.data";

int main(int argc, char *argv[])
{
    FILE *fp;
    KeyType len, d;
    
    if (argc < 2)
    {
        printf("Usage: gen_data <number of data>\n");
        exit(0);
    }

    len = atoi(argv[1]);
    if (len > maxn)
    {
        printf("The number of data(%u) is too large, please choose one less than %u\n", len, maxn);
        exit(0);
    }

    srand(time(NULL));

    fp = fopen(datafile, "wb"); //"wt"
        /**************************************************
     * wb：二进制模式
     * wt：文本模式
     * 区别：换行时，文本模式在windows、unix等字符不同，
     *      而二进制是数据流，没有该差异
     * ************************************************/

    fwrite(&len, size, 1, fp); //byte stream    //把位于缓冲区的数据len（2字节）写入，其中len是数据个数
    for (int i = 0; i < len; ++i)
    {
        d = rand() % limit;
        fwrite(&d, size, 1, fp);
    }
    fclose(fp);

    printf("All data was written into file %s\n"
    "*** Note: the value of the first %u bytes is the count of data\n", datafile, size);

    return 0;
}