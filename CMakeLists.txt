cmake_minimum_required(VERSION 3.15)

project(GALAXY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(/usr/include)
include_directories(./include)
include_directories(./include/commands)
include_directories(./include/exceptions)
include_directories(./include/primitives)
include_directories(./tests/include)
include_directories(./exceptions)
include_directories(./IoC)

set(SOURCE_FILES 
    ./source/primitives/Vector2D.cpp
    ./source/primitives/Angle.cpp
    ./source/primitives/FuelLevel.cpp

    ./tests/main.cpp 
    ./tests/Vector2D_test.cpp
    ./tests/Move_test.cpp
    ./tests/Angle_test.cpp
    ./tests/Rotate_test.cpp
    ./tests/LogException_test.cpp
    ./tests/LogExceptionHandler_test.cpp
    ./tests/Repeat_test.cpp
    ./tests/RepeatHandler_test.cpp
    ./tests/Runner_test.cpp
    ./tests/CheckFuel_test.cpp
    ./tests/BurnFuel_test.cpp
    ./tests/MacroCommand_test.cpp
    ./tests/ChangeMovementDirection_test.cpp
    ./tests/Scenarios_test.cpp

    ./source/commands/Move.cpp
    ./source/commands/Rotate.cpp
    ./source/commands/LogException.cpp
    ./source/commands/LogExceptionHandler.cpp
    ./source/commands/Repeat.cpp
    ./source/commands/RepeatHandler.cpp
    ./source/commands/RepeatTwice.cpp
    ./source/commands/RepeatTwiceHandler.cpp
    ./source/commands/CheckFuel.cpp
    ./source/commands/BurnFuel.cpp
    ./source/commands/MacroCommand.cpp
    ./source/commands/ChangeMovementDirection.cpp

    ./source/exceptions/FailedRepeat.cpp
    ./source/exceptions/InvalidArgument.cpp
    ./source/exceptions/NotEnoughFuel.cpp
    ./source/exceptions/CommandException.cpp
    ./source/exceptions/UnavailableAction.cpp

    ./source/Runner.cpp
)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(galaxy_test ${SOURCE_FILES})
target_link_libraries(galaxy_test PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads)