cmake_minimum_required(VERSION 3.28)
project(AddConstLLVMPass)

set(LLVM_DIR "/opt/homebrew/Cellar/llvm/18.1.8/lib/cmake/llvm" CACHE PATH "LLVM installation directory")

list(APPEND CMAKE_PREFIX_PATH
        "/opt/homebrew/Cellar/llvm/18.1.8/")

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS})

set(CMAKE_CXX_STANDARD 20 CACHE STRING "")

if (NOT LLVM_ENABLE_RTTI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif ()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(lib)
