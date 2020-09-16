/**
 *  create by NLWMODE 09/16/2020
 *  单链表、双链表相关算法题
 */

#include<iostream>
using namespace std;

struct Linked_Node{
    int data;                 // 节点保存的数据
    Linked_Node* next;      // 链表的写一个节点
    Linked_Node(){
        next = nullptr;    // 这样 new 一个节点时，默认next为空
    }
};
/**
 * 翻转链表区域的节点 m->n
 */
Linked_Node* reverseBetween(Linked_Node* pHead , int m , int n)
{
    if(pHead == nullptr)
        return nullptr;
    Linked_Node* cur = pHead;
    Linked_Node* prev = nullptr;
    while(m > 1)
    {
        prev = cur;
        cur = cur->next;
        m--;
        n--;
    }
    Linked_Node* con = prev , *tail = cur;
    Linked_Node* tmp = nullptr;
    while(n > 0)
    {
        tmp = cur->next;    // 先保存下一个,不然待会没办法指向
        cur->next = prev;   // 反向指
        prev = cur;         // prev , cur都继续往后走一步
        cur = tmp;          
        n--;
    }
    return pHead;
}

/**
 * 删除链表的倒数第 N 个节点
 */
Linked_Node* removeNthFromEnd(Linked_Node* pHead, int n) {
    Linked_Node* dummy;         
    dummy->next = pHead;
    Linked_Node* slow = dummy;
    Linked_Node* fast = dummy;

    for(int i = 0 ; i <= n ; ++i )
        fast = fast->next;
    while(fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Linked_Node* node = slow->next;
    slow->next = slow->next->next;
    free(node);                 
    return dummy->next;
}


/**
 * 删除链表中的重复节点值，值保存第一个节点
 * 如果是有序的？如果是无序的？
 */
Linked_Node* deleteDuplicates(Linked_Node* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    Linked_Node* cur = pHead;
    while(cur != nullptr && cur->next != nullptr)
    {
        if(cur->data == cur->next->data)
        {
            Linked_Node* node = cur->next;  
            cur->next = node->next;     // 保留第一个重复值，删除next
            free(node);                // 清楚野指针
        }
        else
            cur = cur->next;
    }
    return pHead;
}

/**
 * 环形链表，以及环形链表的入口
 */
Linked_Node* detectCircle(Linked_Node* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    Linked_Node* fast = pHead;
    Linked_Node* slow = pHead;
    bool is_circle = false;
    // 判断是否环
    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            is_circle = true;
            break;
        }
    }
    // 找环的入口位置
    if(is_circle)
    {
        Linked_Node* cur = pHead;
        while(slow != cur)
        {
            cur = cur->next;
            slow = slow->next;
        }
        return slow;
    }
    return nullptr;
}

/**
 * 奇偶链表
 */
Linked_Node* oddEvenList(Linked_Node* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    Linked_Node* odd = pHead;           // 奇节点
    Linked_Node* even = pHead->next;    // 偶节点
    Linked_Node* evenHead = pHead->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;     // 偶位置节点的下一个为奇节点 赋值给奇结点
        odd = odd->next;            // 奇节点跳到下一个奇节点的位置   
        even->next = odd->next;     // 奇位置节点的下一个为偶节点 赋值给偶节点
        even = even->next;          // 偶节点跳到下一个偶节点的位置
    }
    odd->next = evenHead;
    return pHead;
}