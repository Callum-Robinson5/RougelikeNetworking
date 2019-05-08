#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
#include <SFML/Network.hpp>
#include <mutex>
#include <condition_variable>

template <typename T>
class Queue
{
    public:

        T pop() //Blocking Pop
        {
            std::unique_lock<std::mutex> mlock(mutex_);
            cond_.wait(mlock, [this]{return !queue_.empty();});
            auto val = queue_.front();
            queue_.pop();
            return val;
        }

        void pop(T& item) //Pop Will Not Wait With An Empty Queue
        {
            std::unique_lock<std::mutex> mlock(mutex_);
            if(queue_.empty())
            {
                return;
            }
            item = queue_.front();
            queue_.pop();
        }

        void push(const T& item)
        {
            std::unique_lock<std::mutex> mlock(mutex_);
            queue_.push(item);
            cond_.notify_one();
        }

        Queue() = default;
        Queue(const Queue&) = delete; //disable copying
        Queue& operator = (const Queue&) = delete; //disable assignment






    protected:

    private:

    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cond_;

};

#endif // QUEUE_H
