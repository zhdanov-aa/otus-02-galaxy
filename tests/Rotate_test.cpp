#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <Rotate.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class RotatingObjectMock: public IRotatingObject
{
public:
    MOCK_METHOD(Angle, getAngle, ());
    MOCK_METHOD(Angle, getRotationSpeed, ());
    MOCK_METHOD(void, setAngle, (Angle));
};

TEST(Rotate, Rotating)
{
    std::shared_ptr<RotatingObjectMock> ro = std::make_shared<RotatingObjectMock>();
    Rotate r(ro);

    EXPECT_CALL(*ro, getAngle()).WillOnce(Return(Angle(90)));
    EXPECT_CALL(*ro, getRotationSpeed()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*ro, setAngle(Angle(135)));

    r.Execute();
}

TEST(Rotate, GetAngleFailException)
{
    std::shared_ptr<RotatingObjectMock> ro = std::make_shared<RotatingObjectMock>();
    Rotate r(ro);

    ON_CALL(*ro, getAngle).WillByDefault(Throw(std::runtime_error("getAngle() failed")));
    ON_CALL(*ro, getRotatingSpeed).WillByDefault(Return(Angle(45)));

    EXPECT_CALL(*ro, getAngle()).Times(AnyNumber());
    EXPECT_CALL(*ro, getRotatingSpeed()).Times(AnyNumber());
    EXPECT_CALL(*ro, setAngle(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(r.Execute());
}

TEST(Rotate, GetRotatingSpeedFailException)
{
    std::shared_ptr<RotatingObjectMock> ro = std::make_shared<RotatingObjectMock>();
    Rotate r(ro);

    ON_CALL(*ro, getAngle).WillByDefault(Return(Angle(90)));
    ON_CALL(*ro, getRotatingSpeed).WillByDefault(Throw(std::runtime_error("getRotatingSpeed() failed")));

    EXPECT_CALL(*ro, getAngle()).Times(AnyNumber());
    EXPECT_CALL(*ro, getRotatingSpeed()).Times(AnyNumber());
    EXPECT_CALL(*ro, setAngle(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(r.Execute());
}

TEST(Rotate, SetAngleFailException)
{
    std::shared_ptr<RotatingObjectMock> ro = std::make_shared<RotatingObjectMock>();
    Rotate r(ro);

    ON_CALL(*ro, getAngle).WillByDefault(Return(Angle(90)));
    ON_CALL(*ro, getRotatingSpeed).WillByDefault(Return(Angle(45)));
    ON_CALL(*ro, setAngle).WillByDefault(Throw(std::runtime_error("setAngle() failed")));

    EXPECT_CALL(*ro, getAngle()).Times(AnyNumber());
    EXPECT_CALL(*ro, getRotatingSpeed()).Times(AnyNumber());
    EXPECT_CALL(*ro, setAngle(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(r.Execute());
}