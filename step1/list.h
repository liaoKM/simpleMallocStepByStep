struct Node
{
    Node* next;
    Node* prev;
};
class List
{
private:
    Node head;
public:
    //将Node* p插入到链表头部
    void push(Node* p);

    //从链表中断开Node* p
    void split(Node* p);


    //断开链表的第一节点(head.next)，并返回；
    //链表为空则return false
    bool pop(Node*& p);
};