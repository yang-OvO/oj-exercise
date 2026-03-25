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
class Solution {
public:
    TreeNode* invertTreeImpl1(TreeNode *root)
    {
        if (!root) {
            return nullptr;
        }
        TreeNode *flipped_left, *flipped_right;
        flipped_left = root->right ? invertTreeImpl1(root->right) : nullptr;
        flipped_right = root->left ? invertTreeImpl1(root->left) : nullptr;
        root->left = flipped_left;
        root->right = flipped_right;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invertTreeImpl1(root);
    }
};