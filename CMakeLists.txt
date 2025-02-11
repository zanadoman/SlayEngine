# CMake
cmake_minimum_required(VERSION 3.25.1)
if(NOT ${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR}/build)
  message(FATAL_ERROR "Incorrect build directory, CMake will exit.")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY clang-tidy;-p;${CMAKE_BINARY_DIR})

# Project
project(wizard_engine LANGUAGES CXX)

# Target
if(NOT ${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME} MATCHES
  x86_64-Linux|aarch64-Linux|AMD64-Windows)
  message(FATAL_ERROR "Unsupported target, CMake will exit.")
endif()

# Compiler
if(NOT ${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
  message(FATAL_ERROR "Unsupported compiler, CMake will exit.")
endif()
if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 18.0.3)
  message(FATAL_ERROR "Outdated compiler, CMake will exit.")
endif()

# Flags
file(READ ${CMAKE_SOURCE_DIR}/compile_flags.txt CMAKE_CXX_FLAGS)
string(REPLACE \n \  CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

# Sources
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_NAME} ${SOURCES})

# Libraries
target_link_libraries(${PROJECT_NAME} SDL3 # SDL3_image SDL3_mixer SDL3_net SDL3_ttf
)

# Tests
file(GLOB_RECURSE TESTS ${CMAKE_SOURCE_DIR}/tests/*.cpp)
add_executable(test ${TESTS})
target_link_libraries(test ${PROJECT_NAME} gtest gtest_main)

# Examples
file(GLOB_RECURSE EXAMPLES ${CMAKE_SOURCE_DIR}/examples/*.cpp)
foreach(SOURCE ${EXAMPLES})
  get_filename_component(NAME ${SOURCE} NAME_WLE)
  add_executable(${NAME} ${SOURCE})
  target_link_libraries(${NAME} ${PROJECT_NAME})
endforeach()

# Assets
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/assets/)
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/)
