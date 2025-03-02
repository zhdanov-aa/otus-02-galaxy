#include <IoC.h>
#include <ICommand.h>
#include <ResolverContainer.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <string>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;

TEST(IoC, RegisterDependecy)
{
    IoC::Resolve<ICommandPtr>(
        "IoC.Register",
        "ScopeName",
        make_container(std::function<string()>( [](){ return string("root"); } ))
        )->Execute();

    EXPECT_EQ(
        string("root"),
        IoC::Resolve<string>("ScopeName")
    );
}