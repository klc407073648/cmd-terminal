# 第三方库设置
## 设置第三方应用库的头文件
execute_process(COMMAND sh ${PROJECT_SOURCE_DIR}/cmake/drogon.sh 
${PROJECT_SOURCE_DIR}/lib/3partlib 
${PROJECT_SOURCE_DIR}/include/3partlib)
