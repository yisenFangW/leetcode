在 O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

题解：
//这题题目看着很简单，就是链表的常规排序而已，但是想要在O(nlogn)和常数空间复杂度的情况下完成，就需要一些骚操作了；
//O(nlogn)时间复杂度，首先想到的是二分法，但是这题是无序的，就是要让你排序，二分不知道怎么实现，放弃...
//然后再想，排序问题，经典的集中解法中，有没有能用上的，最后用上了分治法，分治法的思想就是将大的变成小的，再继续排序；
//如何实现将大的链表拆分成两半呢，快慢指针这个时候派上用场了.
//最后再实现一个链表的排序方法，即可在题目要求下实现功能；
ListNode *sort(ListNode *l, ListNode *r) {
    ListNode *head = new ListNode(0);
    ListNode *node = head;
    while (l != nullptr && r != nullptr) {
        if(l->val > r->val){
            node->next = r;
            r = r->next;
        }
        else{
            node->next = l;
            l = l->next;
        }
        node = node->next;
    }
    if(l) node->next = l;
    if(r) node->next = r;
    return head->next;
}

ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        if (fast != nullptr)
            slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = nullptr;
    ListNode *l = sortList(head);
    ListNode *r = sortList(tmp);
    return sort(l, r);
}
