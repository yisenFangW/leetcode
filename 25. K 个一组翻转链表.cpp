给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5
说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//题解：讲道理这题是挺难的，看题解半天才明白，现在的解答，完全是看题解抄的，先记录一下，便于以后看
//感觉这题很经典啊
//pre是要翻转区间的前一个，next是要翻转的区间的后一个
ListNode *reverse(ListNode *pre, ListNode *next) {
    ListNode *last = pre->next, *cur = last->next;
    //注意这个链表翻转的实现
    while (cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    //返回pre的值，进行记录
    return last;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || k == 1)
        return head;
    ListNode* dummy = new ListNode(-1), *pre = dummy, *cur = head;
    dummy->next = head;
    for(int i=1;cur;++i){
        //pre记录前一个，然后如果是k的倍数，才进行翻转
        if(i%k == 0){
            pre = reverse(pre, cur->next);
            cur = pre->next;
        }
        //不是k的倍数，继续前进，pre的值不变，保证一直是要翻转的前一个
        else{
            cur = cur->next;
        }
    }
    return dummy->next;
}
