/*设计链表的实现。您可以选择使用单链表或双链表。
单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。
如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

示例：
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
提示：
0 <= index, val <= 1000
请不要使用内置的 LinkedList 库。
get, addAtHead, addAtTail, addAtIndex 和 deleteAtIndex 的操作次数不超过 2000。
 */

#include<iostream>
using namespace std;


class MyLinkedList {
   
    public:
    struct ListNode
    {
       int val;
       ListNode* next;
       ListNode(int val):val(val), next(nullptr){}
    };
    private:
    int size;
    ListNode *head;

    public:
    MyLinkedList() {
        this->size=0;
        this->head=new ListNode(0);
    }
    
    ListNode* getNode(int index)
    {
        if(index>=0&&index<this->size)
        {
            int i=0;
            ListNode *current=head;
            while(i!=index)
            {
                current=current->next;
                i++;
            }
            return current;
        }
        return nullptr;
    }

    int get(int index) {
        ListNode * node=getNode(index);
        return node==nullptr?-1:node->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
         addAtIndex(this->size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
        {
            return;
        }
        if(index<0)
        {
            index=0;
        }
        ListNode* newNode=new ListNode(val);
        if(index>=0||index<size)
        {
            ListNode* perNode=getNode(index-1);
            ListNode* curNode=getNode(index);
            if(perNode!=nullptr)
            {
               perNode->next=newNode;
            }
            newNode->next=curNode;
            if(index==0) //设置head
            {
                head=newNode;
            }
        }
        this->size++;
    }
    
    void deleteAtIndex(int index) {
        if(index==0)
        {
            auto cur=getNode(index);
            head=cur->next;
            size--;       
        }
        else if(index>0&&index<this->size-1)
        {
            auto pre=getNode(index-1);
            auto next=getNode(index+1);
            pre->next=next;
            size--;
        }
        else if(index==this->size-1)
        {
             auto pre=getNode(index-1);
             pre->next=nullptr;
             size--;
        }
    }
};




int main()
{
    MyLinkedList *linkedList = new MyLinkedList;
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList->get(1);            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    linkedList->get(1);            //返回3
    return 0;
}