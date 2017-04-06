cmake_minimum_required(VERSION 3.6)
project(LQueue_student_files)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        LQueue.C
        LQueue.h
        LQueue_driver.C)

add_executable(LQueue_student_files ${SOURCE_FILES})