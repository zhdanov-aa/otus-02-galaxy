#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Move.h>

class MovingObjectMock: public IMovingObject
{
public:
    MOCK_METHOD(Vector2D, getLocation, ());
    MOCK_METHOD(Vector2D, getVelocity, ());
    MOCK_METHOD(void, setLocation, (Vector2D));
};

TEST(Move, Moving)
{
    std::shared_ptr<MovingObjectMock> mo = std::make_shared<MovingObjectMock>();
    Move m(mo);

    EXPECT_CALL(*mo, getLocation()).WillOnce(testing::Return(Vector2D(12, 5)));
    EXPECT_CALL(*mo, getVelocity()).WillOnce(testing::Return(Vector2D(-7, 3)));
    EXPECT_CALL(*mo, setLocation(Vector2D(5,8)));

    m.Execute();
}

TEST(Move, GetLocationFailException)
{
    std::shared_ptr<MovingObjectMock> mo = std::make_shared<MovingObjectMock>();
    Move m(mo);

    ON_CALL(*mo, getLocation).WillByDefault(testing::Return(Vector2D(12, 5)));
    ON_CALL(*mo, getVelocity).WillByDefault(testing::Return(Vector2D(-7, 3)));

    EXPECT_CALL(*mo, getLocation()).Times(AnyNamber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNamber());.
    EXPECT_CALL(*mo, setLocation(Vector2D(testing::_, testing::_))).Times(AnyNamber());

    EXPECT_ANY_THROW(m.Execute());
}
