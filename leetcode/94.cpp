
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#if __has_include(<generator>)
#include <generator>
#endif
class Solution {

    static void InorderTraversalImpl(TreeNode* cur, vector<int>& res)
    {
        if (!cur) return;

        InorderTraversalImpl(cur->left, res);
        res.push_back(cur->val);
        InorderTraversalImpl(cur->right, res);
    }

public:
#ifdef __cpp_lib_generator
    static generator<int> YieldInOrder(TreeNode* cur)
    {
        if (!cur) co_return;

        co_yield ranges::elements_of(YieldInOrder(cur->left));
        co_yield cur->val;
        co_yield ranges::elements_of(YieldInOrder(cur->right));
    }

    vector<int> InorderTraversal2(TreeNode* root)
    {
        return YieldInOrder(root) | ranges::to<vector<int>>();
    }
#endif

    vector<int> inorderTraversalIter(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;

        TreeNode* cur = root;

        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(); stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }

    vector<int> inorderTraversalIterUniversal(TreeNode* root)
    {
        vector<int> res;
        stack<pair<TreeNode*, bool>> stk;

        stk.push({root, false});
        while (!stk.empty()) {
            auto [node, visited] = stk.top(); stk.pop();
            if (!node) {
                continue;
            }
            if (visited) {
                res.push_back(node->val);
            } else {
                stk.push({node->right, false});
                stk.push({node, true});
                stk.push({node->left, false});
            }
        }
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        // vector<int> res;
        // InorderTraversalImpl(root, res);
        // return res;

        // return InorderTraversal2(root);

        return inorderTraversalIter(root);

        // return inorderTraversalIterUniversal(root);
    }
};