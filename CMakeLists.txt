cmake_minimum_required(VERSION 3.14)
project(SQLParser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binaries in bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include and source directories
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/include/*.hpp)

# ========== Boost ==========
find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# ========== Main Program ==========
add_executable(sql_parser_demo
    ${SRC_FILES}
    ${HEADER_FILES}
    ${PROJECT_SOURCE_DIR}/main.cpp
)

target_include_directories(sql_parser_demo PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

# ========== GoogleTest ==========
# Option A: Find installed GoogleTest
find_package(GTest REQUIRED)

add_executable(sql_parser_tests
    ${SRC_FILES}
    ${PROJECT_SOURCE_DIR}/test/SQLParser_Test.cpp
)

target_include_directories(sql_parser_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(sql_parser_tests
    GTest::GTest
    GTest::Main
    pthread
)

enable_testing()
add_test(NAME SQLParserTest COMMAND sql_parser_tests)
