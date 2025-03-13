#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <ICommand.h>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <memory>

class BlockingQueue
{
    std::mutex              d_mutex;
    std::condition_variable d_condition;
    std::deque<ICommandPtr> d_queue;

public:
    BlockingQueue();

    void Push(ICommandPtr value);
    ICommandPtr Pop();
    int getSize();
};

using BlockingQueuePtr = std::shared_ptr<BlockingQueue>;

#endif // BLOCKINGQUEUE_H
