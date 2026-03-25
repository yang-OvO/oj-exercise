/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) 
    {
        std::vector<ListNode*> la;
        std::vector<ListNode*> lb;
        
        for (auto ptr = headA; ptr != nullptr; ptr = ptr->next) {
            la.push_back(ptr);
        }
        for (auto ptr = headB; ptr != nullptr; ptr = ptr->next) {
            lb.push_back(ptr);
        }

        std::reverse(la.begin(), la.end());
        std::reverse(lb.begin(), lb.end());

        size_t i = 0;
        for (; i < la.size() && i < lb.size(); i++) {
            if (la[i] != lb[i]) {
                if (i == 0) {
                    return nullptr;
                } else {
                    return la[i-1];
                }
            }
        }

        if (i == la.size()) {
            return la.back();
        } else {
            return lb.back();
        }
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) 
    {
        std::unordered_set<ListNode*> set_a;
        for (auto ptr = headA; ptr != nullptr; ptr = ptr->next) {
            set_a.insert(ptr);
        }

        for (auto ptr = headB; ptr != nullptr; ptr = ptr->next) {
            if (set_a.find(ptr) != set_a.end()) {
                return ptr;
            }
        }
        return nullptr;
    }

    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) 
    {
        ListNode* ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = ptrA == nullptr? headB: ptrA->next;
            ptrB = ptrB == nullptr? headA: ptrB->next;
        }
        return ptrA;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    }
};