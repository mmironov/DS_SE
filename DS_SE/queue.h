//
//  queue.h
//  DS_SE
//
//  Created by Miroslav Mironov on 7/5/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#ifndef __DS_SE__queue__
#define __DS_SE__queue__

#include <stdio.h>

#endif /* defined(__DS_SE__queue__) */

template <typename T>
class Queue {
public:
    virtual void enqueue(const T& elem) = 0;
    virtual void dequeue() = 0;
    virtual T front() const = 0;
};

template <typename T>
class Buffer : public Queue<T> {
private:
    static const int CAPACITY = 10;
    
    T buffer[CAPACITY];
    
    int _front;
    int _rear;
    int _size;
public:
    Buffer();
    
    void enqueue(const T& elem);
    void dequeue();
    T front() const;
    
    int size() const;
    bool isEmpty() const;
};

template<typename T>
Buffer<T>::Buffer()
{
    _front = 0;
    _rear = 0;
    _size = 0;
}

template <typename T>
void Buffer<T>::enqueue(const T& elem)
{
    if (_size == CAPACITY)
    {
        return;
    }
    
    buffer[_rear] = elem;
    _rear = (_rear + 1) % CAPACITY;
    ++_size;
}

template <typename T>
void Buffer<T>::dequeue()
{
    if (_size == 0)
    {
        return;
    }
    
    _front = (_front + 1) % CAPACITY;
    --_size;
}

template <typename T>
T Buffer<T>::front() const
{
    return buffer[_front];
}

template <typename T>
int Buffer<T>::size() const
{
    return _size;
}

template <typename T>
bool Buffer<T>::isEmpty() const
{
    return _size == 0;
}