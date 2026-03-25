/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool hasCycleImpl1(ListNode *head) 
    {
        int itr_times = 0;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next) {
            if (itr_times > 1e4) {
                return true;
            }
            itr_times++;
        }
        // Reach end. No cycle
        return false;
    }

    bool hasCycleImpl2(ListNode *head)
    {
        unordered_set<ListNode*> s;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next) {
            if (s.find(ptr) != s.end()) {
                // Current node is in the set
                return true;
            }
            s.insert(ptr);
        }
        // Reach end. No cycle
        return false;
    }

    bool hasCycleImpl3(ListNode* head)
    {
        if (!head) {
            return false;
        }
        ListNode *slow_ptr = head, *fast_ptr = head;
        while (1) {
            if (slow_ptr->next) {
                slow_ptr = slow_ptr->next;
            }
            for (int i = 0; i < 2; i++) {
                if (fast_ptr->next) {
                    fast_ptr = fast_ptr->next;
                } else {
                    // Reach end. No cycle
                    return false;
                }
            }

            if (slow_ptr == fast_ptr)
                break;
        }
        // Slow ptr meet fast ptr. There is a cycle
        return true;
    }

public:
    bool hasCycle(ListNode *head) {
        
    }
};