#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <MacroCommand.h>
#include <ICommandQueue_mock.h>
#include <CheckFuel.h>
#include <Move.h>
#include <BurnFuel.h>
#include <IFuelObject_mock.h>
#include <IMovingObject_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::_;
using ::testing::AnyNumber;

TEST(StraightLineMovement, MoveAndBurn)
{
    CheckFuelPtr checkFuel = male_shared<CheckFuel>()

    shared_ptr<ICommandQueueMock> commands = make_shared<ICommandQueueMock>();

    MacroCommand cmd(commands);

    EXPECT_NO_THROW(cmd.Execute);
}