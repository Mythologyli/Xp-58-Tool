cmake_minimum_required(VERSION 3.0)
project(Xp_58_Tool)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        main.cpp
        xp58.cpp
        )

add_executable(Xp_58_Tool ${SOURCES})

set_target_properties(Xp_58_Tool PROPERTIES OUTPUT_NAME "xp58tool")
