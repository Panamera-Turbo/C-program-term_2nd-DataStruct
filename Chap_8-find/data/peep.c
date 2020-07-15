#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "keytype.h"
/*******************************************
 * 偷看指定位置的数据
 * 在这里，指的是打开文件benchmark.data ， 然后
 * ********************************************/
const char *data_file = "benchmark.data";
const unsigned size = sizeof(KeyType);

int main(int argc, char *argv[])
{
    FILE *fp;
    KeyType v;
	KeyType len;
    int index;
    
    fp = fopen(data_file, "rb");
    fread(&len, sizeof(len), 1, fp);

    printf("There are %u data stored in this file.\nPlease type in an index(1~%u):", len, len);
    scanf("%u", &index);
    if (index > len)
    {
        printf("The index you typed in is greater than %u, please type in an lesser one.\n", len);
        exit(-1);
    }

    fseek(fp, index * size + size, SEEK_SET);
    fread(&v, size, 1, fp);
	fclose(fp);

    printf("The value @ %u is: %u\n", index, v);

    return 0;
}