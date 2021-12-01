struct Node
{
    Node* next;
    Node* prev;
    //为了内存分配而添加的内容
    int chunkSize;
};
class List
{
private:
    Node head;
public:
    //将Node* p插入到链表头部
    void push(Node* p);


    //断开链表的第一节点(head.next)，并返回；
    //链表为空则return false
    bool pop(Node*& p);
};