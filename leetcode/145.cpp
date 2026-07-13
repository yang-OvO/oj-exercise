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
    vector<int> postorderTraversalIter(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;

        if (root) {
            stk.push(root);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            res.push_back(node->val);
            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> postorderTraversalIterUniversal(TreeNode* root)
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
                stk.push({node, true});
                stk.push({node->right, false});
                stk.push({node->left, false});
            }
        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        // vector<int> res;
        // PostorderTraversal(root, res);
        // return res;

        // return PostorderTraversal2(root);

        return postorderTraversalIter(root);

        // return postorderTraversalIterUniversal(root);
    }
};