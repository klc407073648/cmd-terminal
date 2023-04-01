cmake_minimum_required(VERSION 3.5)
project(cmdterminal CXX)

# 依赖StiBel库的内容 封装成StiBel.cmake文件
set(CMAKE_PREFIX_PATH   "${CMAKE_CURRENT_SOURCE_DIR}/lib/3partlib/lib64/cmake")
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SpecialDeal.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/stibel.cmake)
# 依赖StiBel库的内容

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

add_executable(${PROJECT_NAME} main.cc)

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon 
# add_subdirectory(drogon) 
# target_link_libraries(${PROJECT_NAME} PRIVATE drogon)
#
# and comment out the following lines
find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

# ##############################################################################

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

aux_source_directory(controllers CTL_SRC)
aux_source_directory(common COMMON_SRC)
aux_source_directory(constants CONSTANT_SRC)
aux_source_directory(exception EXCEPTION_SRC)
aux_source_directory(filters FILTER_SRC)
#aux_source_directory(plugins PLUGIN_SRC)
aux_source_directory(models MODEL_SRC)
aux_source_directory(services SERVICE_SRC)
aux_source_directory(services/inner SERVICE_INNER_SRC)

drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/views
                    ${CMAKE_CURRENT_BINARY_DIR} TRUE)

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
               ${CTL_SRC}
               ${COMMON_SRC}
               ${CONSTANT_SRC}
               ${EXCEPTION_SRC}
               ${FILTER_SRC}
               ${MODEL_SRC}
               ${SERVICE_SRC}
               ${SERVICE_INNER_SRC})
               #${PLUGIN_SRC}
               #${MODEL_SRC})
# ##############################################################################
# uncomment the following line for dynamically loading views 
# set_property(TARGET ${PROJECT_NAME} PROPERTY ENABLE_EXPORTS ON)

# ##############################################################################

add_subdirectory(test)
add_subdirectory(testcase)
