## 查找

- benchmark--进去make就行，会比较三种查找的效率
- data---生成/查看生成的数据
- hash--哈希查找，但是没有main函数，应该去benchmark里make
- lead_in--引入，顺序查找和折半查找
- list-based--基于线性表的比较查找法
- tree-based--基于树的

//下面的东西是乱的，**直接看源码**<br>
.
├── 07.10
│   ├── 1.c
│   ├── 2.c
│   ├── 3.c
│   └── hash.h
├── Chap-8内容简介.md
├── benchmark
│   ├── Makefile
│   └── main.cpp
├── data
│   ├── benchmark.data
│   ├── gen_data
│   ├── gen_data.c
│   ├── keytype.h
│   ├── peep
│   └── peep.c
├── find.pptx
├── hash
│   ├── hash.cpp
│   └── hash.h
├── lead_in
│   └── afind.c
├── list-based
│   ├── Makefile
│   ├── main.c
│   ├── seq.c
│   ├── seq.cpp
│   └── seq.h
├── recordtype.h
├── tree-based
│   ├── Makefile
│   ├── bstree.c
│   ├── bstree.cpp
│   ├── bstree.h
│   └── main.c
└── 查找的基础知识.md

7 directories, 29 files