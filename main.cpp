#include <QCoreApplication>
#include <iostream>
#include <stdint.h>
#include "queue.hpp"
#include "queueTest.hpp"

struct Item
{
    int a;
    void* b;
    long c;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QueueTest *test = new QueueTest;
    test->tester();
    Queue<Item, 16> q;
    Item itm1;
    itm1.a = 1;
    q.enqueue(itm1);
    if (q.size() > 0)
        q.dequeue();
    return a.exec();
}
