class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode* t = head;
        ListNode* before = NULL;

        for (int i = 1; i < left; i++) {
                before = t;
                t = t->next;
        }
        
        ListNode* curr = t;
        ListNode* prev = NULL;

        int times = right - left + 1;

        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        t->next = curr;

        if (before)
            before->next = prev;
        else
            head = prev;

        return head;
    }
};