#可执行文件输出目录
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${3PARTLIB_EXECUTABLE_OUTPUT_PATH}/googletest/test)

#头文件目录
INCLUDE_DIRECTORIES( ${GOOGLETEST_INCLUDE}  ../include /home/drogon/drogon/lib/inc ${STIBEL_COMMON_INCLUDE})

#目录源码路径
SET( GOOGLETEST_TEST_SRC_DIR ../source )

#代码列表
FILE (GLOB GOOGLETEST_TEST_FILES ${GOOGLETEST_TEST_SRC_DIR}/*.cpp)

#依赖的LIB
SET(GOOGLETEST_TEST_LIB  ${LIB_GOOGLETEST} ${LIB_STIBEL_COMMON})

#生成 
#ADD_EXECUTABLE( googletest_test ${GOOGLETEST_TEST_FILES})

#连接生成相关库
#TARGET_LINK_LIBRARIES( googletest_test ${GOOGLETEST_TEST_LIB} -lpthread)

################################

##############
# Unit Tests
##############
ADD_EXECUTABLE(runUnitTests test_project1.cpp)

# Standard linking to gtest stuff.
TARGET_LINK_LIBRARIES(runUnitTests gtest gtest_main -lpthread Drogon::Drogon ${LIB_STIBEL_COMMON})

# Extra linking for the project.
TARGET_LINK_LIBRARIES(runUnitTests project1_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(NAME that-test-I-made COMMAND runUnitTests)

# You can also omit NAME and COMMAND. The second argument could be some other
# test executable.
add_test(that-other-test-I-made runUnitTests)
