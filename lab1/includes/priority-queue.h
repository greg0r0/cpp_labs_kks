#ifndef _PRIORITY_QUEUE_HPP
#define _PRIORITY_QUEUE_HPP

#include <vector>
#include "binary_heap.h"

namespace lab1
{
    template <typename T, typename container = lab1::binary_heap<T> >
    class priority_queue
    {
    private:
        container data;

    public:
        priority_queue() {}
        priority_queue(container original)
        {
            data = original;
        }

        T pop()
        {
           return this->data.pop();
        }

        void push(T element)
        {
            this->data.push(element);
        }

        const T& get_head() const
        {
            return this->data.get_head();
        }

        unsigned int len() const
        {
            return this->data.get_len();
        }

        bool is_empty()
        {
            return (this->len() == 0);
        }

        void print()
        {
            this->data.print(0,0);
        }

    };
}
#endif