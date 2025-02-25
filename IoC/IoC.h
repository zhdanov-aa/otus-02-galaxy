#ifndef __IOC_H_INCLUDED__
#define __IOC_H_INCLUDED__

#include <ScopeHolder.h>
#include <Resolver.h>
#include <RuntimeError.h>
#include <memory>
#include <functional>

class IoC
{
    thread_local static ScopeHolder Scopes;

    IoC() {}

public:

    template<typename ResultType, typename... Args>
    static ResultType Resolve(std::string dependecy, Args... args)
    {
        using ResolverPrototype = Resolver<std::function<ResultType(Args...)>>;

        std::shared_ptr<ResolverPrototype> resolver =
            std::dynamic_pointer_cast<ResolverPrototype>(IoC::Scopes.getResolver(dependecy));

        if (resolver == nullptr)
            throw new RuntimeError("IoC: resolver not found");

        return resolver->get()(args...);
    }

    template<typename ResultType>
    static ResultType Resolve(std::string dependecy)
    {
        using ResolverPrototype = Resolver<std::function<ResultType()>>;

        std::shared_ptr<ResolverPrototype> resolver =
            std::dynamic_pointer_cast<ResolverPrototype>(IoC::Scopes.getResolver(dependecy));

        if (resolver == nullptr)
            throw new RuntimeError("IoC: resolver not found");

        return resolver->get()();
    }
};

#endif
