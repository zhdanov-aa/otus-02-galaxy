cmake_minimum_required(VERSION 3.15)

project(GALAXY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(/usr/include)
include_directories(./include)
include_directories(./commands)
include_directories(./exceptions)
include_directories(./primitives)
include_directories(./tests/mock)
include_directories(./exceptions)
include_directories(./IoC)

set(SOURCE_FILES 
    ./primitives/Vector2D.cpp
    ./primitives/Angle.cpp
    ./primitives/FuelLevel.cpp

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
    ./tests/FallbackCommand_test.cpp
    ./tests/IocNewScopeCommand_test.cpp
    ./tests/IocRegisterCommand_test.cpp
    ./tests/IocSetScopeRelativeCommand_test.cpp

    ./commands/Move.cpp
    ./commands/Rotate.cpp
    ./commands/LogException.cpp
    ./commands/LogExceptionHandler.cpp
    ./commands/Repeat.cpp
    ./commands/RepeatHandler.cpp
    ./commands/RepeatTwice.cpp
    ./commands/RepeatTwiceHandler.cpp
    ./commands/CheckFuel.cpp
    ./commands/BurnFuel.cpp
    ./commands/MacroCommand.cpp
    ./commands/ChangeMovementDirection.cpp
    ./commands/FallbackCommand.cpp
    ./commands/IocNewScopeCommand.cpp
    ./commands/IocRegisterCommand.cpp
    ./commands/IocSetScopeAbsoluteCommand.cpp
    ./commands/IocSetScopeRelativeCommand.cpp

    ./exceptions/FailedRepeat.cpp
    ./exceptions/InvalidArgument.cpp
    ./exceptions/NotEnoughFuel.cpp
    ./exceptions/CommandException.cpp
    ./exceptions/UnavailableAction.cpp
    ./exceptions/RuntimeError.cpp

    ./source/Runner.cpp

    ./IoC/IoC.cpp
    ./IoC/ResolverCollection.cpp
    ./IoC/Scope.cpp
    ./IoC/ScopeChangerAdapter.cpp
    ./IoC/ScopeContainer.cpp
)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(galaxy_test ${SOURCE_FILES})
target_link_libraries(galaxy_test PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads)