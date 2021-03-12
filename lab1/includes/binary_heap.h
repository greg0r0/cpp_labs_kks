#ifndef __BINARY_HEAP_HPP__
#define __BINARY_HEAP_HPP__

#include <vector>
#include <iostream>
#include <string>
namespace lab1
{
/*
    container must realize functionality of dynamic array with methods
    - push_back
    - pop_back

    Example: std::vector, std::deque etc.
*/

    template <typename TData, template <class...> class container = std::vector>
    class binary_heap
    {
    private:
        container<TData> heap;
        unsigned int heap_size;

    public:
        binary_heap()
        {
            this->heap = container<TData>();
            this->heap_size = 0;
        }
        binary_heap(TData data)
        {
            this->heap = container<TData>();
            this->heap.push_back();
            this->heap_size = 1;
        }


        void push(TData data)
        {
            this->heap_size++;
            int curr_index = this->heap_size-1;
            this->heap.push_back(data);
            int parent_id = (curr_index-1)/2;

            while (curr_index > 0 && this->heap[parent_id] < this->heap[curr_index])
            {
                TData tmp = this->heap[curr_index];
                this->heap[curr_index] = this->heap[parent_id];
                this->heap[parent_id]=tmp;

                curr_index = parent_id;
                parent_id = (curr_index-1)/2;
            }

        }

        TData pop() // get element from head
        {
            TData top = this->heap[0];
            this->heap[0] = this->heap[ this->heap_size - 1 ];
            this->heap.pop_back();
            this->heap_size--;
            this->heapify(0);
            return top;
        }

        const TData& get_head() const
        {
            return this->heap[0];
        }

        void heapify(unsigned int index) // sort heap (for pop)
        {
            unsigned int left = 2*index + 1;
            unsigned int right = 2*index + 2;

            if (left < this->heap_size)
            {
                if (this->heap[index] < this->heap[left])
                {
                    TData t = this->heap[index];
                    this->heap[index] = this->heap[left];
                    this->heap[left] = t;
                    this->heapify(left); 
                }
            }

            if (right < this->heap_size)
            {
                if (this->heap[index] < this->heap[right])
                {
                    TData t = this->heap[index];
                    this->heap[index] = this->heap[right];
                    this->heap[right] = t;
                    this->heapify(right); 
                }
            }
            

        }

        unsigned int get_len() const
        {
            return this->heap_size;
        }

        //print "pretify" view
        void print(unsigned int index, unsigned int pos)
        {
            unsigned int left = 2*index + 1;
            unsigned int right = 2*index + 2;
            

            if ( left < this->heap_size )
            {
                this->print(right, pos+1);
            }

            std::cout << std::string(pos, '-') << "(" << this->heap[index] << ")"<<std::endl;
            
            if ( left < this->heap_size )
            {
                this->print(left, pos+1);
            }

        }

        //print in linear mode
        void print()
        {
            for (int i = 0; i < this->heap_size ; i++)
            {
                std::cout << this->heap[i] << " ";
            }
            std::cout << std::endl;
        }
    };
}
#endif