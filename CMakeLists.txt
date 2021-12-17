cmake_minimum_required(VERSION 3.10)

project(emptyfolderfinder VERSION 0.0.1)

set(EFF_SOURCES
  src/directory.cpp
  src/directory.hpp
  src/helper.cpp
  src/helper.hpp
  src/main.cpp
)

add_executable(${PROJECT_NAME} ${EFF_SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
