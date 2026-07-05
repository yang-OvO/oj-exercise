
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

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        InorderTraversalImpl(root, res);
        return res;
        // return InorderTraversal2(root);
    }
};