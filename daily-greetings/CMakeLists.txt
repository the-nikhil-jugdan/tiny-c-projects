cmake_minimum_required(VERSION 3.20)

project(daily-greetings
    VERSION 1.0
    LANGUAGES C
)

add_executable(daily-greetings
    src/main.c
)

target_compile_features(daily-greetings PRIVATE c_std_17)
