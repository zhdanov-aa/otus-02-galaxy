#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <Move.h>
#include <IMovingObject_mock.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

TEST(Move, Moving)
{
    std::shared_ptr<IMovingObjectMock> mo = std::make_shared<IMovingObjectMock>();
    Move m(mo);

    EXPECT_CALL(*mo, getLocation()).WillOnce(Return(Vector2D(12, 5)));
    EXPECT_CALL(*mo, getVelocity()).WillOnce(Return(Vector2D(-7, 3)));
    EXPECT_CALL(*mo, setLocation(Vector2D(5,8)));

    m.Execute();
}

TEST(Move, GetLocationFailException)
{
    std::shared_ptr<IMovingObjectMock> mo = std::make_shared<IMovingObjectMock>();
    Move m(mo);

    ON_CALL(*mo, getLocation).WillByDefault(Throw(std::runtime_error("getLocation() failed")));
    ON_CALL(*mo, getVelocity).WillByDefault(Return(Vector2D(-7, 3)));

    EXPECT_CALL(*mo, getLocation()).Times(AnyNumber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNumber());
    EXPECT_CALL(*mo, setLocation(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(m.Execute());
}

TEST(Move, GetVelocityFailException)
{
    std::shared_ptr<IMovingObjectMock> mo = std::make_shared<IMovingObjectMock>();
    Move m(mo);

    ON_CALL(*mo, getLocation).WillByDefault(Return(Vector2D(12, 5)));
    ON_CALL(*mo, getVelocity).WillByDefault(Throw(std::runtime_error("getVelocity() failed")));

    EXPECT_CALL(*mo, getLocation()).Times(AnyNumber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNumber());
    EXPECT_CALL(*mo, setLocation(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(m.Execute());
}

TEST(Move, SetLocationFailException)
{
    std::shared_ptr<IMovingObjectMock> mo = std::make_shared<IMovingObjectMock>();
    Move m(mo);

    ON_CALL(*mo, getLocation).WillByDefault(Return(Vector2D(12, 5)));
    ON_CALL(*mo, getVelocity).WillByDefault(Return(Vector2D(-7, 3)));
    ON_CALL(*mo, setLocation).WillByDefault(Throw(std::runtime_error("setLocation() failed")));

    EXPECT_CALL(*mo, getLocation()).Times(AnyNumber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNumber());
    EXPECT_CALL(*mo, setLocation(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(m.Execute());
}