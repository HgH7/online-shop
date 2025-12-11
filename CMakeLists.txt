cmake_minimum_required(VERSION 4.0)
project(online_shop)

set(CMAKE_CXX_STANDARD 20)

add_executable(online_shop main.cpp
        DS/Trees.cpp
        DS/deliveryqueue.h
        DS/deliveryqueue.cpp
        DS/SLL.cpp
        DS/cartStack.cpp
        DS/linkedList.h
)
