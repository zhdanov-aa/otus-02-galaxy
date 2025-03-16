#include "BlockingQueue.h"

BlockingQueue::BlockingQueue() {}

void BlockingQueue::Push(ICommandPtr value)
{
    {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        d_queue.push_front(value);
    }
    this->d_condition.notify_one();
}

ICommandPtr BlockingQueue::Pop()
{
    std::unique_lock<std::mutex> lock(this->d_mutex);
    this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
    ICommandPtr rc(std::move(this->d_queue.back()));
    this->d_queue.pop_back();
    return rc;
}

int BlockingQueue::getSize()
{
    std::unique_lock<std::mutex> lock(this->d_mutex);
    return d_queue.size();
}
