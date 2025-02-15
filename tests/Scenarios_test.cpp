#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <MacroCommand.h>
#include <ICommandQueue_mock.h>
#include <CheckFuel.h>
#include <Move.h>
#include <BurnFuel.h>
#include <ChangeMovementDirection.h>
#include <Rotate.h>
#include <IFuelObject_mock.h>
#include <IMovingObject_mock.h>
#include <IMovementDirectionObject_mock.h>
#include <IRotatingObject_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::_;
using ::testing::AnyNumber;

TEST(Scenarios, CheckFuel_Move_BurnFuel)
{
    shared_ptr<IMovingObjectMock> movingObject = make_shared<IMovingObjectMock>();
    shared_ptr<IFuelObjectMock> fuelObject = make_shared<IFuelObjectMock>();

    CheckFuelPtr checkFuelCmd = make_shared<CheckFuel>(fuelObject);
    shared_ptr<Move> moveCmd = make_shared<Move>(movingObject);
    BurnFuelPtr burnFuelCmd = make_shared<BurnFuel>(fuelObject);

    shared_ptr<ICommandQueueMock> commands = make_shared<ICommandQueueMock>();

    MacroCommand cmd(commands);

    EXPECT_CALL(*commands, GetCommand())
        .WillOnce(Return(checkFuelCmd))
        .WillOnce(Return(moveCmd))
        .WillOnce(Return(burnFuelCmd))
        .WillOnce(Return(nullptr));

    EXPECT_CALL(*fuelObject, getLevel()).Times(2).WillRepeatedly(Return(FuelLevel(100)));
    EXPECT_CALL(*fuelObject, getConsumption()).Times(2).WillRepeatedly(Return(FuelLevel(10)));
    EXPECT_CALL(*movingObject, getLocation()).WillOnce(Return(Vector2D(100,100)));
    EXPECT_CALL(*movingObject, getVelocity()).WillOnce(Return(Vector2D(2,4)));
    EXPECT_CALL(*movingObject, setLocation(Vector2D(102,104)));
    EXPECT_CALL(*fuelObject, setLevel(FuelLevel(90)));

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(Scenarios, Rotate_ChangeMovementDirection)
{
    IRotatingObjectMockPtr rotatingObject = make_shared<IRotatingObjectMock>();
    EXPECT_CALL(*rotatingObject, getAngle()).WillOnce(Return(Angle(90)));
    EXPECT_CALL(*rotatingObject, getRotationSpeed()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*rotatingObject, setAngle(Angle(135)));

    IMovementDirectionObjectMockPtr changeDirectionObject = make_shared<IMovementDirectionObjectMock>();
    EXPECT_CALL(*changeDirectionObject, getDirection()).WillOnce(Return(Angle(90)));
    EXPECT_CALL(*changeDirectionObject, getInstantChange()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*changeDirectionObject, setDirection(Angle(135)));

    shared_ptr<ICommandQueueMock> commands = make_shared<ICommandQueueMock>();
    EXPECT_CALL(*commands, GetCommand())
        .WillOnce(Return(make_shared<Rotate>(rotatingObject)))
        .WillOnce(Return(make_shared<ChangeMovementDirection>(changeDirectionObject)))
        .WillOnce(Return(nullptr));

    MacroCommand cmd(commands);

    EXPECT_NO_THROW(cmd.Execute());
}