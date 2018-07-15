#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "../stl/cstdint.h"
#include "../stl/type_traits.h"
#include "../stl/utility.h"

namespace vAVR {
    namespace RTOS {

        template<typename T, stl::uint8_t N>
        class Queue {

            using size_type = size_t;

            T data[N];

            stl::int8_t front = -1;
            stl::int8_t rear = -1;

        public:
            // standard constructor
            Queue();

            // construct from an element
            explicit Queue(const T& val);
            explicit Queue(T&& val);

            // default destructor
            ~Queue() = default;

            // delete move and copy constructors
            Queue(const Queue&) = delete;
            Queue(Queue&&) = delete;
            // delete move and copy assignments
            Queue& operator=(const Queue&) = delete;
            Queue& operator=(Queue&&) = delete;

            // basic operations of Queue
            inline bool isEmpty() const;
            inline bool isFull() const;
            inline size_type size() const;

            // push a new element
            void push_back(const T& value);
            void push_back(T&& value);

            // pop and get an element
            T& pop_front();
        };


        template<typename T, stl::uint8_t N>
        Queue<T, N>::Queue() {}

        template<typename T, stl::uint8_t N>
        Queue<T, N>::Queue(const T& val)
        {
            data[0] = val;
        }

        template<typename T, stl::uint8_t N>
        Queue<T, N>::Queue(T&& val)
        {
            data[0] = stl::move(val);
        }

        template<typename T, stl::uint8_t N>
        bool Queue<T, N>::isEmpty() const
        {
            return (front == -1);
        }

        template<typename T, stl::uint8_t N>
        bool Queue<T, N>::isFull() const
        {
            return (rear == front - 1) || (rear == N - 1 && front == 0);
        }

        template<typename T, stl::uint8_t N>
        typename Queue<T, N>::size_type Queue<T, N>::size() const
        {
            return N;
        }

        //NOTE: is it possible to get rid of this duplicacy?
        template<typename T, stl::uint8_t N>
        void Queue<T, N>::push_back(const T& value)
        {
            if (isFull()) return; //TODO: I don't want to ignore these. Implement some waiting once kernel

            if (rear == N - 1 && front != 0)
            {
                rear = 0;
            }
            data[rear] = value;
            ++rear;
        }

        template<typename T, stl::uint8_t N>
        void Queue<T, N>::push_back(T&& value)
        {
            if (isFull()) return; //TODO: I don't want to ignore these. Implement some waiting once kernel

            if (rear == N - 1 && front != 0)
            {
                rear = 0;
            }
            data[rear] = stl::move(value);
            ++rear;
        }

        template<typename T, stl::uint8_t N>
        T& Queue<T, N>::pop_front()
        {
            if (isEmpty()) return; //TODO: I don't want to ignore these. Implement some waiting once kernel

            T val = data[front];

            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (front == N - 1)
            {
                front = 0;
            }
            else
            {
                ++front;
            }

            return val;
        }
    }
} /* end of namespace vAVR::RTOS */

#endif //_QUEUE_H_
