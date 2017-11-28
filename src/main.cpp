#include <stdio.h>
#include "base/freeList.h"

int main(int argumentCount, char* arguments)
{
    using namespace base;
    FreeList* pFreeList = new FreeList(8, 1024);
    void* mem1 = pFreeList->retrieve();
    void* mem2 = pFreeList->retrieve();
    void* mem3 = pFreeList->retrieve();
    void* mem4 = pFreeList->retrieve();
    pFreeList->release(mem2);
    void* mem5 = pFreeList->retrieve(); // mem5 gets the old memory mem2 had.
    delete pFreeList;
    return 0;
}