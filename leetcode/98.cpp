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
class Solution
{
    bool isValidBSTImpl1(TreeNode* root)
    {
        if (!root) {
            return true;
        }
        bool res = true;
        if (root->left) {
            res &= isValidBST(root->left);
            res &= root->val > getMaxNumInBST(root->left);
        }
        if (root->right) {
            res &= isValidBST(root->right);
            res &= root->val < getMinNumInBST(root->right);
        }
        return res;
    }

    bool validate(TreeNode* root, TreeNode* min_node, TreeNode* max_node)
    {
        if (!root) {
            return true;
        }
        if (min_node && root->val <= min_node->val) {
            return false;
        }
        if (max_node && root->val >= max_node->val) {
            return false;
        }
        return validate(root->left, min_node, root) &&
                validate(root->right, root, max_node);
    }

    bool isValidBSTImpl2(TreeNode* root)
    {
        return validate(root, nullptr, nullptr);
    }
public:
    int getMinNumInBST(TreeNode* root)
    {
        TreeNode* cur = root;
        while (cur->left) {
            cur = cur->left;
        }
        return cur->val;
    }

    int getMaxNumInBST(TreeNode* root)
    {
        TreeNode* cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        return cur->val;
    }

    bool isValidBST(TreeNode* root)
    {
        return isValidBSTImpl2(root);
    }
};