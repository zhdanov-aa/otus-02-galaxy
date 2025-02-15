#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ChangeMovementDirection.h>
#include <IMovementDirectionObject_mock.h>
#include <InvalidArgument.h>
#include <UnavailableAction.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

TEST(ChangeMovementDirection, NormalExecution)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*object, getInstantChange()).WillOnce(Return(Angle(15)));
    EXPECT_CALL(*object, setDirection(Angle(65)));

    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

// TEST(ChangeMovementDirection, InvalidArgumentThrowing)
// {

// }

// TEST(ChangeMovementDirection, UnavailableActionCatching)
// {

// }

// TEST(ChangeMovementDirection, OtherExceptionsSkipping)
// {

// }