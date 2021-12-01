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
    //Node* p 插入到this->head
    void push(Node* p);

    //断开链表的第一节点(head.next)，并返回；
    //链表为空则return false
    bool pop(Node*& p);
};