#include <gtest/gtest.h>
#include "../includes/binary_heap.h"
#include "../includes/priority-queue.h"
#include <iostream>
TEST (_PRIORITY_QUEUE_Test, __get_head_test)
{
    lab1::priority_queue<int> test;
    test.push(-1);
    test.push(-2);
    test.push(-3);
    test.push(5);
    test.push(4);
    EXPECT_EQ(test.get_head(), 5);
}


TEST (_PRIORITY_QUEUE_Test, __pop_Test)
{
    lab1::priority_queue<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(5);
    test.push(4);
    EXPECT_EQ(test.pop(), 5);
}

TEST (_PRIORITY_QUEUE_Test, __len_test)
{
    lab1::priority_queue<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(5);
    test.push(4);
    EXPECT_EQ(test.len(), 5);
}

TEST (_PRIORITY_QUEUE_Test, __is_empty_test)
{
    lab1::priority_queue<int> test;
    ASSERT_TRUE(test.is_empty());
}

TEST (_PRIORITY_QUEUE_Test, __little_test)
{
    lab1::priority_queue<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(5);
    test.push(4);
    EXPECT_EQ(test.get_head(), 5);
    EXPECT_EQ(test.pop(), 5);
    EXPECT_EQ(test.pop(), 4);
}


TEST (_PRIORITY_QUEUE_Test, __big_test)
{
    lab1::priority_queue<int> test;
   
    for (int i = 0 ; i < 100; i++)
        test.push(i);

    for (int i = 500; i < 1000; i++)
        test.push(i);

    for (int i = 100; i < 500; i++)
        test.push(i);

    int k = 1000;

    for (int i = 0; i < 1000; i++)
    {
        auto data = test.pop();
        ASSERT_GE(k, data);
        k=data;
    }
}

TEST (_PRIORITY_QUEUE_Test, __mix_test)
{
    lab1::priority_queue<int> test;
   
    test.push(1);
    test.push(5);
    test.push(2);
    test.push(4);
    test.push(3);
    ASSERT_EQ(test.pop(), 5);
    test.push(100);
    ASSERT_EQ(test.get_head(),100);
}

