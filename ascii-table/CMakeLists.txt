cmake_minimum_required(VERSION 3.20)

project(ascii-table
    VERSION 1.0
    LANGUAGES C
)

add_executable(ascii-table
    src/main.c
)

target_compile_features(ascii-table PRIVATE c_std_17)
