cmake_minimum_required(VERSION 3.15)
project(autoscript C)

set(CMAKE_C_STANDARD 11)

add_executable(autoscript main.c src/type/Real.h src/CharIterator.h src/token.h src/index.h src/tokenizer.h src/number.h src/type/function.h src/type/variable.h src/tokenList.h src/utility.h src/operation.h src/parser.h src/tokenIterator.h src/runner.h)