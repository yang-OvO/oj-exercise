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
#include <generator>
class Solution {
public:
    #ifdef __cpp_lib_generator
    std::generator<ListNode*> getReverseNodes(ListNode* cur)
    {
        if (cur->next) {
            co_yield std::ranges::elements_of(getReverseNodes(cur->next));
        }
        co_yield cur;
    }

    bool isPalindrome1(ListNode* head) 
    {
        // 原理和递归解法一样但是比递归解法好理解
        // 这里用到了generator来产生逆序的节点
        auto gen = getReverseNodes(head);
        auto ptr = head;
        for (ListNode* tail : gen) {
            if (ptr->val != tail->val)
                return false;
            ptr = ptr->next;
        }
        return true;
    }
    #endif

    void isPalindrome2Impl(ListNode* cur, ListNode *& front, bool &short_cuts)
    {
        if (!cur)
            return;
        isPalindrome2Impl(cur->next, front, short_cuts);
        if (short_cuts)
            return;
        if (cur->val != front->val) {
            short_cuts = true;
            return;
        }
        front = front->next;
    }

    bool isPalindrome2(ListNode* head) 
    {
        // 递归解法(有两个状态量，不好理解)
        ListNode* front = head;
        bool short_cuts = false;
        isPalindrome2Impl(head, front, short_cuts);
        return front == nullptr;
    }

    bool isPalindrome3(ListNode* head)
    {
        // list转vector
        std::vector<int> st;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next) {
            st.push_back(ptr->val);
        }
        return std::equal(st.cbegin(), st.cbegin() + st.size() / 2, st.crbegin());
    }

    bool isPalindrome(ListNode* head) {
    }
};