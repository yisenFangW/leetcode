反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

题解：
//题目描述依旧简单，难点在怎么一趟完成，思路蛮重要的，主要是如何不繁琐的记录下四个点的位置：
//首先在链表中用ListNode* pre_head = nullptr和head记录下开始点和开始点前一点的位置；
//在链表翻转时，用new_tail记录下head的初始位置为翻转后的链表结尾点，new_head作为翻转链表的开始点，
//head此时的位置为翻转链表后的第一个点，这样的话，就可以将链表组合起来了，
//值得注意的一点是，要主要判断pre_head是否为空；
ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m == n) return head;
    int len = n - m + 1;
    ListNode* result = head;
    ListNode* pre_head = nullptr;
    while(--m){
        pre_head = head;
        head = head->next;
    }
    ListNode* new_head = nullptr, *new_tail = head;
    while(len--){
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    new_tail->next = head;
    if(pre_head) pre_head->next = new_head;
    else result = new_head;
    return result;
}
