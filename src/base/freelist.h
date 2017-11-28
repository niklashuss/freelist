#pragma once

namespace base
{
    class FreeList
    {
    public:
        FreeList(int count, int size);
        ~FreeList();

        void* retrieve();
        void release(void* pMemory);

    private:
        int count;
        int chunkSize;
        unsigned char* pBase;
        unsigned char* pNextFree;
    };
}
