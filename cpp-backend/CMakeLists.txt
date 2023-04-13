cmake_minimum_required(VERSION 3.5)
project(cmdterminal CXX)

# drogon的find_package特殊处理
set(CMAKE_PREFIX_PATH   "${PROJECT_SOURCE_DIR}/lib/3partlib/lib64/cmake")
include(${PROJECT_SOURCE_DIR}/cmake/SpecialDeal.cmake)
# drogon的find_package特殊处理

# 依赖StiBel库的内容
## 选项
include(${PROJECT_SOURCE_DIR}/cmake/options.cmake)

## 3partlib和comlib
include(${PROJECT_SOURCE_DIR}/cmake/3partlib.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/comlib.cmake)

## 链接头文件和库
include(${PROJECT_SOURCE_DIR}/cmake/linklib.cmake)

# 依赖StiBel库的内容

#EXECUTABLE_OUTPUT_PATH为生成可执行文件路径，LIBRARY_OUTPUT_PATH为生成库文件路径，BUILD_LIB_DIR生成库的路径
SET(EXECUTABLE_OUTPUT_PATH      ${PROJECT_SOURCE_DIR}/deploy/)
SET(BUILD_LIB_DIR               ${PROJECT_SOURCE_DIR}/deploy/lib)
SET(LIBRARY_OUTPUT_PATH         ${BUILD_LIB_DIR})

include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)
if (NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
    # Do nothing
elseif (HAS_ANY AND HAS_STRING_VIEW AND HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
elseif (HAS_ANY AND HAS_STRING_VIEW)
    set(CMAKE_CXX_STANDARD 17)
else ()
    set(CMAKE_CXX_STANDARD 14)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 头文件目录
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/src/common/include  ${PROJECT_SOURCE_DIR}/src/constants/include ${PROJECT_SOURCE_DIR}/src/controllers/include
${PROJECT_SOURCE_DIR}/src/exception/include ${PROJECT_SOURCE_DIR}/src/filters/include ${PROJECT_SOURCE_DIR}/src/models/include
${PROJECT_SOURCE_DIR}/src/plugins/include ${PROJECT_SOURCE_DIR}/src/services/include )

#代码列表
FILE (GLOB PROJECT_DROGON_FILES ${PROJECT_SOURCE_DIR}/src/common/src/*.*  ${PROJECT_SOURCE_DIR}/src/constants/src/*.* ${PROJECT_SOURCE_DIR}/src/controllers/src/*.*
${PROJECT_SOURCE_DIR}/src/exception/src/*.* ${PROJECT_SOURCE_DIR}/src/filters/src/*.* ${PROJECT_SOURCE_DIR}/src/models/src/*.*
${PROJECT_SOURCE_DIR}/src/plugins/src/*.* ${PROJECT_SOURCE_DIR}/src/services/src/*.* ${PROJECT_SOURCE_DIR}/src/services/src/inner/*.*)

#drogon_create_views(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/views
#                    ${CMAKE_CURRENT_BINARY_DIR} TRUE)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main/main.cc ${PROJECT_DROGON_FILES})                    

# 链接drogon库
find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

# boost 和 C++ 版本
if (CMAKE_CXX_STANDARD LESS 17)
    # With C++14, use boost to support any, string_view and filesystem
    message(STATUS "use c++14")
    find_package(Boost 1.61.0 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)
elseif (CMAKE_CXX_STANDARD LESS 20)
    message(STATUS "use c++17")
else ()
    message(STATUS "use c++20")
endif ()

add_subdirectory(testcase)
