cmake_minimum_required(VERSION 3.15)

project(GAMESERVER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game-svr
    main.cpp
    ../IoC/IoC.cpp ../IoC/IoC.h
    ../IoC/IocNewScopeCommand.cpp ../IoC/IocNewScopeCommand.h
    ../IoC/IocRegisterCommand.cpp ../IoC/IocRegisterCommand.h
    ../IoC/IocSetScopeAbsoluteCommand.cpp ../IoC/IocSetScopeAbsoluteCommand.h
    ../IoC/IocSetScopeRelativeCommand.cpp ../IoC/IocSetScopeRelativeCommand.h
    ../IoC/IResolverCollection.h
    ../IoC/IResolverContainer.h
    ../IoC/IScope.h
    ../IoC/IScopeChanger.h
    ../IoC/ResolverCollection.cpp ../IoC/ResolverCollection.h
    ../IoC/ResolverContainer.h
    ../IoC/Scope.cpp ../IoC/Scope.h
    ../IoC/ScopeChangerAdapter.cpp ../IoC/ScopeChangerAdapter.h
    ../IoC/ScopeContainer.cpp ../IoC/ScopeContainer.h
    ../exceptions/InvalidArgument.cpp ../exceptions/InvalidArgument.h
    ../exceptions/RuntimeError.cpp ../exceptions/RuntimeError.h
    ../commands/FallbackCommand.cpp ../commands/FallbackCommand.h
    ../commands/ICommand.h
    ../exceptions/IException.h)
