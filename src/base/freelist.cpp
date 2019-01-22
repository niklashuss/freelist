#include "freelist.h"

namespace base
{
    FreeList::FreeList(int count, int chunkSize) :
        count(count),
        chunkSize(chunkSize)
    {
        int totalSize = count * chunkSize;
        pBase = new unsigned char[totalSize];
        for (int i = 0; i < totalSize; i++)
        {
            pBase[i] = 0;
        }
        pNextFree = pBase;
        unsigned char* tmp = pBase;
        unsigned int intAddress = reinterpret_cast<unsigned int>(pBase);
        for (int i = 1; i < count; i++)
        {
            int offset = i * chunkSize;
            int* t = reinterpret_cast<int*>(tmp);
            *t = (intAddress + offset);
            tmp += chunkSize;
        }
    }

    FreeList::~FreeList()
    {
        delete[] pBase;
        pBase = nullptr;
        pNextFree = nullptr;
        count = 0;
        chunkSize = 0;
    }

    void* FreeList::retrieve()
    {
        void* pPointer = reinterpret_cast<void*>(pNextFree);
        if (pPointer == nullptr)
        {
            return nullptr;
        }
        unsigned int* pIntPointer = reinterpret_cast<unsigned int*>(pNextFree);
        pNextFree = reinterpret_cast<unsigned char*>(*pIntPointer);
        return pPointer;
    }

    void FreeList::release(void* pMemory)
    {
        unsigned int* pIntPointer = reinterpret_cast<unsigned int*>(pMemory);
        *pIntPointer = reinterpret_cast<unsigned int>(pNextFree);
        pNextFree = reinterpret_cast<unsigned char*>(pMemory);
    }
}
