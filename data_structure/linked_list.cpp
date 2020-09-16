/**
 *  create by NLWMODE 09/16/2020
 *  单链表
 *  双链表
 *  相关操作
 */

#include<iostream>
#include<assert.h>
using namespace std;

/*******************       单链表         ***********************/
template <typename T>
struct Linked_Node{
    T data;                 // 节点保存的数据
    Linked_Node* next;      // 链表的写一个节点
    Linked_Node(){
        next = nullptr;    // 这样 new 一个节点时，默认next为空
    }
};

/**
 * 在节点 poseNode 后插入一个值为 val 的节点
 */
void insert_at(Linked_Node<int>* poseNode , int val){
    assert(!poseNode);
    Linked_Node<int>* node = new Linked_Node<int>();
    // new 成功会返回对象，不成功会剖出异常 ， 不能使用 == NULL 来进行判断
    try{
        node->data = val;
        node->next = poseNode->next;
        poseNode->next = node;
    } catch(const std::bad_alloc& e){
        std::cerr << e.what() << '\n';
    }
}
/**
 * 直接删除节点 pose
 */
void erase_at_direct(Linked_Node<int>* pHead , Linked_Node<int>* poseNode){
    assert(!pHead);
    if(pHead == nullptr || poseNode == nullptr)
        return;
    if(poseNode == pHead){
        pHead = poseNode->next;
        delete poseNode;
    }
    else{
        Linked_Node<int>* cur = pHead;
        while(cur->next && cur->next != poseNode)
            cur = cur->next;
        cur = poseNode->next;
        delete poseNode;
    }
}
/**
 * 通过将后一个节点的值赋值给当前节点，删除后一个节点
 */
void erase_at_indirect( Linked_Node<int>* poseNode)
{
    if(poseNode->next){
        Linked_Node<int>* node = poseNode->next;
        poseNode->data = node->data;
        poseNode->next = node->next;
        delete node;
    }
    else
        delete poseNode;
}


/*******************       双链表         ***********************/

struct DLinked_Node
{
    int data;
    DLinked_Node* pre;
    DLinked_Node* next;
    DLinked_Node(){
        pre = nullptr;
        next = nullptr;
    }
};

/**
 * 在poseNode 后插入节点
 * 涉及到 1.头结点插入 2.尾节点插入 3.中间节点插入的
 */
void insert_at(DLinked_Node* pHead ,DLinked_Node* pTail, DLinked_Node* poseNode , int val)
{
    assert(!poseNode);
    DLinked_Node* pre = poseNode->pre;
    DLinked_Node* next = poseNode->next;
    DLinked_Node* node;
    node->data = val;
    if(!pre){
        // 头插入
        node->next = pHead;
        pHead = node;
    }
    else if(!next){
        // 尾插入
        pTail->next = node; // 插在尾节点后面
        node->pre = pTail;
        pTail = node;       // 尾节点后移
    }
    else{
        
        // 断开尾部，链接节点 node
        node->next = poseNode->next;    
        poseNode->next->pre = node;
        // 断开头部，链接节点 node
        node->pre = poseNode;           
        poseNode->next = node;
    }
}
/**
 * 删除 poseNode节点，
 * 涉及到 头删除 、 尾删除 、 中间节点删除
 */
void insert_at(DLinked_Node* pHead ,DLinked_Node* pTail, DLinked_Node* poseNode , int val)
{
    assert(!poseNode);
    DLinked_Node* pre = poseNode->pre;
    DLinked_Node* next = poseNode->next;
    if(!pre){
        // 头删除
        DLinked_Node* node = pHead;
        pHead = pHead->next;
        delete node;
    }
    else if(!next){
        // 尾删除
        DLinked_Node* node = pTail;
        pTail->pre->next = NULL;
        delete node;
    }
    else{
        // 中间节点删除
        poseNode->next->pre = pre;  // 图片里的 step 2
        pre->next = poseNode->next; // 图片里的 step 1
        delete poseNode;
    }
}