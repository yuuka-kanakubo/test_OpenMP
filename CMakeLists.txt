cmake_minimum_required(VERSION 3.12)
project(test VERSION 1.0)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
else()
	message(FATAL_ERROR "Could not find OpenMP for CXX")
endif()

add_executable(test main.cpp)
target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)

install(TARGETS test DESTINATION .)
