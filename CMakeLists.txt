cmake_minimum_required(VERSION 3.15)

project(GALAXY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(/usr/include)
include_directories(./include)
include_directories(./include/commands)

set(SOURCE_FILES 
    ./tests/main.cpp 
    ./tests/Vector2D_test.cpp
    ./tests/Move_test.cpp
    ./tests/Angle_test.cpp
    ./tests/Rotate_test.cpp
    ./tests/WriteExceptionToLog_test.cpp
    ./source/commands/Move.cpp
    ./source/commands/Rotate.cpp
    ./source/commands/LogException.cpp
    ./source/Vector2D.cpp
    ./source/Angle.cpp
    ./source/Runner.cpp
    ./source/ExceptionHandler.cpp
    )

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(galaxy_test ${SOURCE_FILES})
target_link_libraries(galaxy_test PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads)