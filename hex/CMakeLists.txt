cmake_minimum_required(VERSION 3.20)

project(hex
    VERSION 1.0
    LANGUAGES C
)

add_executable(hex
    src/main.c
)

target_compile_features(hex PRIVATE c_std_17)
