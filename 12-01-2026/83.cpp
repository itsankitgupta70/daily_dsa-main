// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            // tabhi chanla jab tak current node ka next null na ho q ki agar
            // aisa hai to bas ek hi node hai
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
                // jab equal ho jaye to next ke next wale se connect kar ke
                // pehle wale ko delete kar do aur fir se usi node pe reh ke
                // check karo traverse nahi karne ka
                // q ki value change ho bhi sakti hai aur nahi bhi
            } else {
                curr = curr->next;
                // instant traverse nahi karna jab tak not equal na aye tab tak
            }
        }
        return head;
    }
};