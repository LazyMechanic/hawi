cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(hygge)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

# Make x64
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SYSTEM_BIT_POSTFIX x64)
# Make x86
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(SYSTEM_BIT_POSTFIX x86)
endif()

set(PROJECT_INC_DIR ${PROJECT_DIR}/include)
set(PROJECT_SRC_DIR ${PROJECT_DIR}/src)

add_subdirectory(src/hygge)
add_subdirectory(test/hygge)