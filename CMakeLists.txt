cmake_minimum_required(VERSION 4.0)
project(online_shop)

set(CMAKE_CXX_STANDARD 20)

add_executable(online_shop main.cpp
        DS/products.cpp
        DS/deliveryqueue.h
        DS/deliveryqueue.cpp
        DS/customerAcc.cpp
        DS/cartSystem.cpp
        DS/customerAcc.h
        Algo/Search.h
        Algo/Sort.h
        DS/orderHistory.h
        DS/orderHistory.cpp
)
