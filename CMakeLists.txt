cmake_minimum_required(VERSION 3.13)
project(compiler_course C)

set(CMAKE_C_STANDARD 99)

add_executable(compiler_course main.c lexer/global.h lexer/const.h lexer/helper.c lexer/lexan.c lexer/helper.h lexer/const.c lexer/lexan.h)