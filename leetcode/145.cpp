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
    void PostorderTraversal(TreeNode* root, vector<int>& res)
    {
        if (!root) return;

        PostorderTraversal(root->left, res);
        PostorderTraversal(root->right, res);
        res.push_back(root->val);
    }

#ifdef __cpp_lib_generator
    static generator<int> PostorderTraversal2Impl(TreeNode* root)
    {
        if (!root) co_return;

        co_yield ranges::elements_of(PostorderTraversal2Impl(root->left));
        co_yield ranges::elements_of(PostorderTraversal2Impl(root->right));
        co_yield root->val;
    }

    vector<int> PostorderTraversal2(TreeNode* root)
    {
        return PostorderTraversal2Impl(root) | ranges::to<vector<int>>();
    }
#endif
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        PostorderTraversal(root, res);
        return res;

        // return PostorderTraversal2(root);
    }
};