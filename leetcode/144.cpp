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

    vector<int> preorderTraversalIter(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;

        if (root) {
            stk.push(root);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            res.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }

    vector<int> preorderTraversalIterUniversal(TreeNode* root)
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
                stk.push({node->left, false});
                stk.push({node, true});
            }
        }
        return res;
    }

public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        // vector<int> res;
        // PreOrderTraversal(root, res);
        // return res;

        // return PreOrderTraversal2(root);

        return preorderTraversalIter(root);

        // return preorderTraversalIterUniversal(root);
    }
};