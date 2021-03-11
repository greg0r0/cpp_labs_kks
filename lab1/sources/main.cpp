#include <queue>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../includes/binary_heap.h"
#include "../includes/priority-queue.h"
int main()
{
    srand(time(0));
    lab1::priority_queue<int> kek2;
    
    for (int i = 0; i < 100; i++)
        kek2.push(rand()%100);

    for (int i=0; i < 10; i++) 
        std::cout << kek2.pop() << std::endl;
    
}

/*
template<class ...> class container
template<class TData, template<class ...> class container> class lab1::binary_heap

*/