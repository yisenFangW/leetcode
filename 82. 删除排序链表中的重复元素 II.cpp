给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

//题解：
//这题讲道理还是有一些难度的，首先想到的是用一个辅助空间的方法来写，用map记录list的值出现的次数，大于1的话，就不放进去了
//然后创建一个新链表，依次往后遍历
ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *res = head;
    map<int, int> m;
    while (head != nullptr) {
        ++m[head->val];
        head = head->next;
    }
    head = res;
    ListNode *node = new ListNode(0), *_node = node;
    while (head != nullptr) {
        if (m[head->val] == 1) {
            node->next = new ListNode(head->val);
            node = node->next;
        }
        head = head->next;
    }
    return _node->next;
}
