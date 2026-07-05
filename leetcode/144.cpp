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

    void PreOrderTraversal(TreeNode* root, vector<int>& res)
    {
        if (!root) return;

        res.push_back(root->val);
        PreOrderTraversal(root->left, res);
        PreOrderTraversal(root->right, res);
    }

#ifdef __cpp_lib_generator
    static generator<int> PreOrderTraversal2Impl(TreeNode* root)
    {
        if (!root) co_return;

        co_yield root->val;
        co_yield ranges::elements_of(PreOrderTraversal2Impl(root->left));
        co_yield ranges::elements_of(PreOrderTraversal2Impl(root->right));
    }

    vector<int> PreOrderTraversal2(TreeNode* root)
    {
        return PreOrderTraversal2Impl(root) | ranges::to<vector<int>>();
    }
#endif
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        PreOrderTraversal(root, res);
        return res;

        // return PreOrderTraversal2(root);
    }
};