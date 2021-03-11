#include <queue>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../includes/binary_heap.h"
#include "../includes/priority-queue.h"
#include "string"


int main()
{
    srand(time(0));
    lab1::priority_queue<int> kek2;
    
    for (int i = 0; i < 100; i++)
        kek2.push(rand()%100);

    int l = kek2.get_head();
    l = 5;
    std::cout << kek2.get_head() << " " << l << std::endl;

}
