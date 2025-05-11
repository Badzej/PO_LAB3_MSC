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
        SygnalSzumBialy.cpp
        SygnalKomponent.cpp
        SumaSygnalow.cpp
        SygnalZNasyceniem.cpp
        SygnalZNasyceniem.h
        SygnalFabryka.cpp
        SygnalFabryka.h
        SygnalIO.cpp
        SygnalIO.h
)

add_executable(PO_LAB3_BS ${SOURCES})

target_include_directories (PO_LAB3_BS PUBLIC include_ext_lib)
target_include_directories (PO_LAB3_BS PUBLIC cmake-build-debug)