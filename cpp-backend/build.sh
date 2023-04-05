#!/bin/bash

# TODO 后续在build_lib中解决
yum install -y libuuid-devel
yum install -y openssl-devel
yum install -y zlib-devel

# 2. 虚机上拷贝文件
#cp /home/klc/auto_job/build_lib/StiBel_V2.1.1.tar.gz /home/stibel/

# 3. 解压依赖
tar -zxf StiBel_V2.1.1.tar.gz

# 4.运行程序
cd ./build/
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_BUILD_VERSION=V2.1.1 ..
./cmdterminal &