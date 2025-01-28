#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Vector2D.h>

TEST(Vector2D, plus)
{
    Vector2D v1(12, 5);
    Vector2D v2(-7, 3);

    EXPECT_EQ(v1 + v2, Vector2D(5, 8));
}
