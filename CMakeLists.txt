cmake_minimum_required(VERSION 3.15)

project(online_shop)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(online_shop
    main.cpp
    DS/products.cpp
    DS/deliveryqueue.cpp
    DS/customerAcc.cpp
    DS/cartSystem.cpp
    DS/orderHistory.cpp
)

