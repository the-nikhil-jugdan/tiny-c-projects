cmake_minimum_required(VERSION 3.20)

project(hex-filter
    VERSION 1.0
    LANGUAGES C
)

add_executable(hex-filter
    src/main.c
)

target_compile_features(hex-filter PRIVATE c_std_17)
