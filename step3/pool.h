#include"list.h"
class Pool
{
private:
    //对应大小
    //16B*1 16B*2 16B*4 16B*8 16B*16 16B*32 16B*64 16B*128
    List lists[8];

    /*
    实现将 numOfPages页的连续内存 分为chunkSize大小的块，并添加到对应list中。
    void* p：待分裂的连续内存
    numOfPages：p有几页
    chunkSize： 打算分成多大的块
    */
    void splitPages(void* p,int numOfPages,int chunkSize);

    /*
    实现输入块大小，返回对应list下标。
    return lg(size/16)
    */
    int size2slot(int size);


    /*
    获取buddySlot的chunk，进行分裂；剩余空间挂回到对应的list，所需空间返回。
    注意递归，即buddySlot如果同样为空。
    */
    void* buddySplit(int buddySlot);

    /*
    合并chunk。注意检查标志位，逻辑要一致。
    */
    void merge(void* chunk);


public:
    /*
    为每个list从系统申请1个页大小的连续内存，分块并放入list中.
    先用malloc代替从系统申请内存
    伪代码：    
    for i in range(8)
        p=malloc(1 page)
        splitPages(p,1, 16B * i)
    */
    void init()
    {
        
    }

    /*
    void* pChunk=list[size2slot(size)].pop()
    void* userPointer=pChunk+sizeof((void*))*2+sizeof(long long)
    return userPointer;
    */
    void* distributeChunk(int size);
    
    
    /*
    根据chunk中记录的块大小找到对应的lists，并添加。
    伪代码：
    size=(Node*)p->chunkSize
    lists[size2slot(size)].push(p)
    */
    void* retriveChunk(void* p);
};