#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Move.h>

class IMovingObjectMock: public IMovingObject
{
public:
    MOCK_METHOD0(getLocation, Vector2D());
    MOCK_METHOD0(getVelocity, Vector2D());
    MOCK_METHOD1(setLocation, void(Vector2D));
};

TEST(Move, execute)
{
    EXPECT_TRUE(true);
}
