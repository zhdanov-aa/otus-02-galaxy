#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Move.h>

class IMovingObjectMock: public IMovingObject
{
public:
    MOCK_METHOD(Vector2D, getLocation, (void), (override));
    MOCK_METHOD(Vector2D, getVelocity, (void), (override));
    MOCK_METHOD(void, setLocation, (Vector2D newLocation), (override));
};

TEST(Move, execute)
{
    EXPECT_TRUE(true);
}
