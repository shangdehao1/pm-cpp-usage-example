cmake_minimum_required(VERSION 3.3)
project(array CXX)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

include(FindThreads)

find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
	pkg_check_modules(PMEMOBJ++ REQUIRED libpmemobj++)
else()
	find_package(PMEMOBJ++ REQUIRED)
endif()


Message("pmemobj++_library_dirs --> " ${PMEMOBJ++_LIBRARY_DIRS})
link_directories(${PMEMOBJ++_LIBRARY_DIRS})

add_executable(array array.cpp)
target_include_directories(array PUBLIC ${PMEMOBJ++_INCLUDE_DIRS} . ..)
target_link_libraries(array ${PMEMOBJ++_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

