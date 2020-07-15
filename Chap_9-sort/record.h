#pragma once

#include <cinttypes>
#include <bits/stdc++.h>

typedef uint16_t KeyType;
//typedef int OtherType;

typedef struct
{
	KeyType key;
	//OtherType other_data;
} RecordType;

#define RADIX 10
#define KEY_SIZE 5

typedef struct
{
	KeyType key[KEY_SIZE]; /* 子关键字数组 */
	//OtherType other_data;  /* 其它数据项 */

	int next; /* 静态链域 */
} RecordType1;

typedef int PVector[RADIX];