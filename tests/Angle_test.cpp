#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Angle.h>

TEST(Angle, eq)
{
    EXPECT_EQ( Angle(270), Angle(-90));
    EXPECT_EQ( Angle(270 + 360), Angle(-90));
    EXPECT_EQ( Angle(180), Angle(-180));
    EXPECT_EQ( Angle(360), Angle(0));
}

TEST(Angle, plus)
{
    EXPECT_EQ( Angle(270) + Angle(10), Angle(280));
}
