cmake_minimum_required(VERSION 3.30)
project(PO_LAB3_BS)

set(CMAKE_CXX_STANDARD 26)

set(SOURCES
        lab2.cpp
        ModelARX.cpp
        PetlaSprzezeniaZwrotnego.cpp
        RegulatorPID.cpp
        SygnalStaly.cpp
        SygnalSinusoidalny.cpp
        SygnalProstokatny.cpp
        SygnalTrojkatny.cpp
)

add_executable(PO_LAB3_BS ${SOURCES})

