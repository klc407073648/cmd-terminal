#!/bin/bash

yum install -y libuuid-devel
yum install -y openssl-devel
yum install -y zlib-devel

# 2. 虚机上拷贝文件
cp /home/klc/auto_job/build_lib/StiBel_V2.1.1.tar.gz /home/stibel/

# 3. 进入容器，解压依赖
docker exec -it cmdterm-backend bash
cd /home/stibel/cpp-backend/build/

tar -zxf StiBel_V2.1.1.tar.gz