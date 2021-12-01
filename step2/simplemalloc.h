#include"pool.h"
/*
实现简单的malloc
*/
class SimpleMalloc
{
private:
    Pool pool;
public:
    /*
    调用 pool.init()
    */
    SimpleMalloc();

    /*
    调用 pool.distributeChunk()
    如果获得null指针，则返回loss
    */
    bool malloc(int size,void*& p);

    /*
    将p指针(指向的是chunk的userspace)得到chunk的首地址，想想该偏移多少
    调用 pool.retriveChunk(chunk首地址)
    */
    void free(void* p);
};