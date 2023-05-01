#基础镜像
#TODO 待改成普通centos镜像
FROM docker.io/klc407073648/centos_build_lib:v3.0

#创建路径
WORKDIR /home/stibel

#拷贝源文件
ADD ./cmd-terminal.tar.gz  /home/stibel

#添加动态搜索库路径; 替换宏定义; 修改权限
RUN  cp -rf /home/stibel/conf/etc/ld.so.conf.d/stibel.conf  /etc/ld.so.conf.d \
     && sed -i "s/\$PROJECT_WORK_PATH/\/home\/stibel/g"  /etc/ld.so.conf.d/stibel.conf  \
     && chmod 777 /etc/ld.so.conf.d/stibel.conf 

#添加ldconfig操作到 /etc/profile; source 使得动态库搜索的环境变量生效; 解决重启配置不生效（source /etc/profile）
RUN echo 'ldconfig'  >> /etc/profile \
    && source /etc/profile  \
    && echo 'source /etc/profile'   >> ~/.bashrc

#配置环境变量
ENV project_name  cmd-terminal

#脚本执行权限
RUN cd /home/stibel/docker \
    && chmod 777 *.sh && dos2unix *.sh

#执行命令 
CMD ["/bin/bash","-c","cd /home/stibel/docker && ./run.sh && tail -f /dev/null"] 