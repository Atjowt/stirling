cmake_minimum_required(VERSION 3.0.0)
project(sterling VERSION 0.1.0 LANGUAGES C)

add_executable(sterling src/main.c)
target_include_directories(sterling PRIVATE include)