#ifndef __BINARY_HEAP_HPP__
#define __BINARY_HEAP_HPP__

#include <vector>
#include <iostream>
#include <string>
namespace lab1
{
    // template <typename TData>
    // class binary_heap_node
    // {
    // private:
    //     TData data;

    //     binary_heap_node<TData> left, right;

    // public:
    //     binary_heap_node() {}
    //     binary_heap_node(TData d) : data(d) {}
    //     binary_heap_node(TData d, binary_heap_node<TData> _left, binary_heap_node<TData> _right) : data(d), left(_left), right(_right) {}

    //     TData get_data() { return this->data; }
    //     binary_heap_node<TData> get_left()  { return this->left;  }
    //     binary_heap_node<TData> get_right() { return this->right; }

    //     void set_data(TData _data) { this->data = _data; }
    //     void set_left_node(binary_heap_node<TData> _node)  { this->left = _node;  }
    //     void set_right_node(binary_heap_node<TData> _node) { this->right = _node; }
    // };

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

        void push(TData data) // add element
        {
            this->heap.push_back(data);
            this->heap_size+=1;
            int curr_index = this->heap_size-1;
            int parent = (curr_index-1)/2;

            while (parent >= 0 && curr_index >0)
            {

                if (this->heap[curr_index] > this->heap[parent])
                {
                    TData t = this->heap[curr_index];
                    this->heap[curr_index] = this->heap[parent];
                    this->heap[parent] = t;
                }
                curr_index = parent;
                parent = (curr_index-1)/2;
            }
        }

        TData pop() // get element from head
        {
            TData top = this->heap[0];
            this->heap[0] = this->heap[ this->heap_size - 1 ];
            this->heap_size--;
            this->heapify(0);
            return top;
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

        unsigned int get_len()
        {
            return this->heap_size;
        }

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