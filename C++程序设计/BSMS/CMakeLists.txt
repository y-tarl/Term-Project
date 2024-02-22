cmake_minimum_required(VERSION 3.26)
project(BSMS)

set(CMAKE_CXX_STANDARD 14)

include_directories(source)

add_executable(BSMS
        basis.cpp
        basis.h
        bread.cpp
        bread.h
        breadvector.cpp
        breadvector.h
        main.cpp
        manager.cpp
        manager.h
        managervector.cpp
        managervector.h
        menu.cpp
        menu.h
        other.cpp
        other.h
        sale.cpp
        sale.h
        salevector.cpp
        salevector.h
        vector.hpp)
