cmake_minimum_required(VERSION 3.1)
project(AVLTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(AVLTree ${SOURCE_FILES} Node.h AVLTree.h Person.h Comparator.h Utility.h CPFValidator.h NAMEValidator.h App.h DATEValidator.h)