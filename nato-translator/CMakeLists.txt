cmake_minimum_required(VERSION 3.20)

project(nato-translator
    VERSION 1.0
    LANGUAGES C
)

add_executable(nato-translator
    src/main.c
)

target_compile_features(nato-translator PRIVATE c_std_17)
