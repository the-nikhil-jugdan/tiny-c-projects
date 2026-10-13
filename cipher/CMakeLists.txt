cmake_minimum_required(VERSION 3.20)

project(cipher
    VERSION 1.0
    LANGUAGES C
)

add_executable(cipher
    src/main.c
)

target_compile_features(cipher PRIVATE c_std_17)
