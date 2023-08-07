cmake_minimum_required(VERSION 3.26)
project(SeqListC C)

set(CMAKE_C_STANDARD 11)

add_executable(SeqListC main.c
        SeqList.c
        SeqList.h)
