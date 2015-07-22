#pragma once
#include <stdint.h>

typedef uint16_t BufSize;
template<typename TItem, BufSize TSize>
class Queue
{
    public:
        //! добавляет pItem в очередь. возвращает длину очереди или <=0, если не удалось добавить
        bool enqueue(const TItem& pItem)
        {
            if (length >= TSize)
                return false;
            mData[tailIndex] = pItem;
            tailIndex += 1;
            length += 1;
            if (TSize <= tailIndex)
                tailIndex = 0;
            return true;
        }
        //! вынимает первый элемент из очереди, возвращает длину очереди, или <0 если не удалось вынуть
        bool dequeue()
        {
            if (length == 0)
                return false;
            headIndex += 1;
            length -= 1;
            if (headIndex >= TSize)
                headIndex = 0;
            return true;
        }
        void clear()
        {
            headIndex = 0;
            tailIndex = 0;
            length = 0;
        }
        //! первый элемент очереди
        TItem& head()
        {
            return mData[headIndex];
        }
        const TItem& head() const
        {
            return mData[headIndex];
        }
        //! длина очереди
        BufSize size() const
        {
            return length;
        }
        #ifndef QUEUETEST
            friend class QueueTest;
        #endif //QUEUETEST
    private:
        TItem mData[TSize];
        BufSize headIndex = 0;
        BufSize tailIndex = 0;
        BufSize length = 0;
};
