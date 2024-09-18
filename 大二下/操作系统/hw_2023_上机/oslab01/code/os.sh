#!/bin/bash

mkdir -p osdir
cd osdir

# 创建文件
touch f1
# 以兆字节为单位显示内存使用情况
free -m > f1

touch f2
pwd > f2

touch f3
ls -l > f3