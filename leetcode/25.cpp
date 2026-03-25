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

    // Pre-condition: head not null
    ListNode* ReverseRange(ListNode* head, ListNode* sentinel)
    {
        if (head->next == sentinel) {
            return head;
        }
        ListNode* head_reversed = ReverseRange(head->next, sentinel);
        head->next->next = head;
        head->next = nullptr;
        return head_reversed;
    }

    // Pre-condition: head not null
    ListNode* reverseKGroup1(ListNode* head, int k)
    {
        ListNode* ret = nullptr;

        ListNode* range_begin = head;
        ListNode* range_end = head;
        ListNode* last_range_tail = nullptr;
        while (true) {
            int i = 0;
            // Find the range.
            for (; i < k && range_end; i++) range_end = range_end->next;
            // If range is insufficient.
            if (i < k) {
                if (last_range_tail) last_range_tail->next = range_begin;
                break;
            }
            // Range is sufficient. Reverse it.
            ListNode* head_reversed = ReverseRange(range_begin, range_end);
            // If it's first range.
            if (ret == nullptr) {
                ret = head_reversed;
            } else {
                last_range_tail->next = head_reversed;
            }

            last_range_tail = range_begin;
            range_begin = range_end;
        }

        return ret;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKGroup1(head, k);
    }
};