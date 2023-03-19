#可执行文件输出目录
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${3PARTLIB_EXECUTABLE_OUTPUT_PATH}/googletest)

#头文件目录
INCLUDE_DIRECTORIES( ${GOOGLETEST_INCLUDE}  ./include ${POCO_INCLUDE} ${JSONCPP_INCLUDE})

#目录源码路径
SET( GOOGLETEST_TEST_SRC_DIR ./source )

#代码列表
FILE (GLOB GOOGLETEST_TEST_FILES ${GOOGLETEST_TEST_SRC_DIR}/*.cpp)

#依赖的LIB
SET(GOOGLETEST_TEST_LIB  ${LIB_GOOGLETEST} ${LIB_POCO} ${LIB_JSONCPP})

#生成动态库，供后续test文件里的用例调用
ADD_LIBRARY(project1_lib ${GOOGLETEST_TEST_SRC_DIR}/project1.cpp)

#生成 
ADD_EXECUTABLE( googletest_test ${GOOGLETEST_TEST_FILES})

#连接生成相关库
TARGET_LINK_LIBRARIES( googletest_test ${GOOGLETEST_TEST_LIB} -lpthread )

################################
add_subdirectory(test)
#if (BUILD_TESTS)
#    enable_testing()
#    add_subdirectory(test)
#endif()