cmake_minimum_required(VERSION 3.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

project(printg VERSION 0.1 LANGUAGES C)

add_compile_options(-Wall -Wextra -Werror=incompatible-pointer-types -Wswitch -Wimplicit-fallthrough)
add_compile_definitions("-DLOGS") # used for LOG_* and COUT/CERR macros
add_compile_definitions("-D_DEFAULT_SOURCE") # needed for reallocarray
add_compile_definitions("-DPRINTG_VERSION=${CMAKE_PROJECT_VERSION}")
message(STATUS "CMAKE_PROJECT_VERSION: '${CMAKE_PROJECT_VERSION}'")
include_directories(BEFORE "include")

add_executable(
    printg
    "src/main.c"
)

if (CMAKE_BUILD_TYPE MATCHES "Asan")
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined -fsanitize=address")
    add_link_options(-fsanitize=undefined -fsanitize=address)
endif()

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(printg PRIVATE -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function)
endif()

cmake_host_system_information(RESULT OS_NAME QUERY OS_NAME)
message(STATUS "OS_NAME: '${OS_NAME}'")

message(STATUS "CMAKE_BUILD_TYPE: '${CMAKE_BUILD_TYPE}'")
