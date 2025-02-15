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
    EXPECT_CALL(*object, setDirection(Angle(60)));

    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, InvalidArgumentThrowing)
{
    ChangeMovementDirection cmd(nullptr);

    try
    {
        cmd.Execute();
        FAIL();
    }
    catch (InvalidArgument *pException)
    {
        delete pException;
        SUCCEED();
    }
}

TEST(ChangeMovementDirection, UnavailableActionCatching_getDirection)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Throw(new UnavailableAction("getDirection")));
    EXPECT_CALL(*object, getInstantChange()).Times(AnyNumber()).WillOnce(Return(Angle(15)));
    
    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, UnavailableActionCatching_getInstantChange)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).Times(AnyNumber()).WillOnce(Return(Angle(15)));
    EXPECT_CALL(*object, getInstantChange()).WillOnce(Throw(new UnavailableAction("getInstantChange")));
    
    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, UnavailableActionCatching_setDirection)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*object, getInstantChange()).WillOnce(Return(Angle(15)));
    EXPECT_CALL(*object, setDirection(_)).WillOnce(Throw(new UnavailableAction("setDirection")));
    
    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, OtherExceptionsSkipping_getDirection)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Throw(1));
    EXPECT_CALL(*object, getInstantChange()).Times(AnyNumber()).WillOnce(Return(Angle(15)));
    
    ChangeMovementDirection cmd(object);

    EXPECT_ANY_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, OtherExceptionsSkipping_getInstantChange)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).Times(AnyNumber()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*object, getInstantChange()).WillOnce(Throw(2));
    
    ChangeMovementDirection cmd(object);

    EXPECT_ANY_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, OtherExceptionsSkipping_setDirection)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*object, getInstantChange()).WillOnce(Return(Angle(15)));
    EXPECT_CALL(*object, setDirection(_)).WillOnce(Throw(3));
    
    ChangeMovementDirection cmd(object);

    EXPECT_ANY_THROW(cmd.Execute());
}