cmake_minimum_required(VERSION 3.15)

# This is a CUDA Project
# Please set the CUDACXX environment variable to the path of nvcc processor
project(
  BLINKPlus
  VERSION 0.1
  DESCRIPTION "Blink for Idle Links"
  LANGUAGES CXX CUDA)

add_subdirectory(src)

add_subdirectory(tests)

