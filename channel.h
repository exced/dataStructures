//  Go-like style channels C++ implementation.
//
//  channel.cc
//  channel
//
//  Created by shuba.
//  MIT License

#ifndef CHANNEL_H
#define CHANNEL_H

#include <atomic>
#include <chrono>

template <typename T>
class Channel
{
  private:
    T *data_;
    const int64_t capacity_;
    const int64_t data_size_;
    std::atomic<int64_t> countLeft_;
    std::atomic<int64_t> countRight_;

  public:
    Channel(int64_t capacity = 0);
    ~Channel();
    void operator<<(const T &val); // send data to the channel
    void operator>>(T &retVal);    // receive data from the channel
};

template <typename T>
Channel<T>::Channel(int64_t capacity) : capacity_(capacity),
                                        data_size_(capacity + 1),
                                        countLeft_(0),
                                        countRight_(0)
{
    if (data_size_)
        data_ = new T[data_size_];
}

template <typename T>
Channel<T>::~Channel()
{
    delete[] data_;
}

template <typename T>
void Channel<T>::operator<<(const T &val)
{
    int64_t counterRight = countRight_.fetch_add(1);
    while (counterRight - countLeft_.load() >= capacity_)
    {
        std::this_thread::yield();
    }

    data_[counterRight % (data_size_)] = val;
}

template <typename T>
void Channel<T>::operator>>(T &retVal)
{
    int64_t counterLeft = countLeft_.fetch_add(1);
    while (countRight_.load() - counterLeft < 1)
    {
        std::this_thread::yield();
    }

    retVal = data_[counterLeft % (data_size_)];
}

#endif // CHANNEL_H