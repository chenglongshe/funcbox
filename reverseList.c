#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode* next;
};

// 反转链表函数
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;   // 暂存下一个节点
        current->next = prev;   // 当前节点指向前一个节点
        prev = current;         // 前一个节点移到当前节点
        current = next;         // 当前节点移到下一个节点
    }
    return prev; // 新的头节点
}
