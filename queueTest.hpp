#pragma once
#include <iostream>
#include <stdint.h>
#include "queue.hpp"

struct ItemTest
{
    int a;
    void* b;
    long c;
};

class QueueTest
{
    private:
        void enqueueTest(int beginOfRange, int endOfRange)
        {
            int counterEnqueue = 0;
            int length = endOfRange - beginOfRange;
            int data[size];
            for (int i = 0; i < length; ++i, ++beginOfRange) {
                ItemTest itemTest;
                itemTest.a = beginOfRange;
                if (q.enqueue(itemTest)) {
                    data[counterEnqueue] = itemTest.a;
                    counterEnqueue += 1;
                }
            }
            std::cout << "Enqueue " << length << " item(s); ";
            if (counterEnqueue == length)
                std::cout << "result: true; ";
            else
                std::cout << "result: "
                          << counterEnqueue << " true, "
                          << (length - counterEnqueue) << " false; ";
            std::cout << "size: " << q.size() << "; "
                      << "head: " << q.headIndex << "; "
                      << "tail: " << q.tailIndex << "; ";
            std::cout << "data: [ ";
            for (int i = 0; i < (counterEnqueue - 1); ++i)
                std::cout << data[i] << ", ";
            if (counterEnqueue > 0)
                std::cout << data[counterEnqueue - 1] << " ]" << std::endl;
            else
                std::cout << "]" << std::endl;
        }
        void dequeueTest(int amountElement)
        {
            int counterDequeue = 0;
            int data[size];
            for (int i = 0; i < amountElement; ++i) {
                data[counterDequeue] = q.head().a;
                if (q.dequeue())
                    counterDequeue += 1;
                else
                    data[counterDequeue] = 0;
            }
            std::cout << "Dequeue " << amountElement << " item(s); ";
            if (counterDequeue == amountElement)
                std::cout << "result: true;";
            else
                std::cout << "result: " << counterDequeue << " true, "
                            << (amountElement - counterDequeue) << " false;";
            std::cout << " size: " << q.size() << ";"
                      << " head: " << q.headIndex << ";"
                      << " tail: " << q.tailIndex << ";"
                      << " data: [ ";
            for (int i = 0; i < (counterDequeue - 1); ++i)
                std::cout << data[i] << ", ";
            if (counterDequeue > 0)
                std::cout << data[counterDequeue - 1] << " ]" << std::endl;
            else
                std::cout << "]" << std::endl;
        }
        void clearTest()
        {
            q.clear();
            std::cout << "Clear queue; "
                        << "size: " << q.size() << "; "
                        << "head: " << q.headIndex << "; "
                        << "tail: " << q.tailIndex << ";" << std::endl;
        }
        void correctOfTakingOutData()
        {
            for (int i = 0; i < 5; ++i) {
                ItemTest item;
                item.a = i;
                q.enqueue(item);
            }
            for (int i = 0; i < 5; ++i) {
                if (q.head().a == i)
                    std::cout << "removes correct data! "
                                << "removes - " << q.head().a
                                << "; should be - " << i << std::endl;
                else
                    std::cout << "removes invalid data! "
                                << "removes - " << q.head().a
                                << "; should be - " << i << std::endl;
                q.dequeue();
            }
            clearTest();
        }
    public:
        void tester()
        {
            correctOfTakingOutData();
            enqueueTest(0,7);
            clearTest();
            enqueueTest(7,15);
            dequeueTest(4);
            enqueueTest(15,26);
            dequeueTest(5);
            enqueueTest(26,33);
            dequeueTest(16);
            dequeueTest(1);
        }
    private:
        const int size = 16;
        Queue<ItemTest, 16> q;
};

