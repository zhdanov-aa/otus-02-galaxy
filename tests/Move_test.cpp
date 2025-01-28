#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Move.h>

class MovingObjectMock: public IMovingObject
{
public:
    MOCK_METHOD0(getLocation, Vector2D());
    MOCK_METHOD0(getVelocity, Vector2D());
    MOCK_METHOD1(setLocation, void(Vector2D));
};

TEST(Move, execute)
{
    std::shared_ptr<MovingObjectMock> mo = std::make_shared<MovingObjectMock>();
    Move m(mo);

    EXPECT_CALL(*mo, getLocation()).WillOnce(Return(Vector2D(12,5)));

    m.Execute();
}
