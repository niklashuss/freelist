#include <stdio.h>
#include "base/freeList.h"

int main(int argumentCount, char* arguments)
{
    using namespace base;
    FreeList freeList(8, 1024);
    void* mem1 = freeList.retrieve();
    void* mem2 = freeList.retrieve();
    void* mem3 = freeList.retrieve();
    void* mem4 = freeList.retrieve();
    freeList.release(mem2);
    void* mem5 = freeList.retrieve(); // mem5 gets the old memory mem2 had.
    return 0;
}