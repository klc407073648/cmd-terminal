#基础镜像
FROM docker.io/klc407073648/centos_build_lib:v3.0

#创建路径
WORKDIR /home/stibel

#拷贝源文件
ADD ./cmd-terminal.tar.gz  /home/stibel

#添加动态搜索库路径
COPY ./conf/etc/ld.so.conf.d/stibel.conf  /etc/ld.so.conf.d
RUN chmod 777 /etc/ld.so.conf.d/stibel.conf 

#添加环境变量到 /etc/profile
RUN echo 'ldconfig'  >> /etc/profile

#source 使得环境变量生效
RUN source /etc/profile

#解决重启配置不生效（source /etc/profile）
RUN echo 'source /etc/profile'   >> ~/.bashrc

#配置环境变量
ENV project_name  StiBel

#执行命令
RUN chmod 777 /home/stibel/docker/run.sh
CMD ["/bin/bash","-c","/home/stibel/docker/run.sh"] 