/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Contains(TreeNode* cur, TreeNode* to_find)
    {
        if (!cur) {
            return false;
        }
        if (cur == to_find) {
            return true;
        }
        return Contains(cur->left, to_find) || Contains(cur->right, to_find);
    }

    void TreeTraversal(TreeNode* cur, TreeNode* p, TreeNode* q, TreeNode*& result)
    {
        if (!cur) {
            return;
        }
        if (result) {
            return;
        }
        if ((Contains(cur->left, p) && Contains(cur->right, q)) ||
            (Contains(cur->left, q) && Contains(cur->right, p))) {
            result = cur;
            return;
        }
        TreeTraversal(cur->left, p, q, result);
        TreeTraversal(cur->right, p, q, result);
    }


    TreeNode* lowestCommonAncestorMyImpl(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (Contains(p->left, q) || Contains(p->right, q)) {
            return p;
        }
        if (Contains(q->left, p) || Contains(q->right, p)) {
            return q;
        }
        TreeNode* result = nullptr;
        TreeTraversal(root, p, q, result);
        return result;
    }

    // 若p和q均在root树上，则返回lca
    // 若p和q有一个在root树上，则不存在lca，但是返回在的那个
    // 若p和q均不在root树上，则返回nullptr
    // （非常tricky，语义复杂，捋了半天才捋清楚QAQ）
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // Base case包含三种情况
        // 空树，返回nullptr
        // root为p或q，另一个在树上，则root为lca
        // root为p或q，另一个不在树上，则不存在lca，但是返回在的那个（即root）
        if (!root || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 若p和q在root的子树上并且位于异侧，则root为lca
        if (left && right) {
            return root;
        }

        // 这里包含三种情况
        // 若p和q位于root的子树上并且在同侧，则返回lca（非空的那个）
        // 若p和q有一个在root的子树上，另一个不在，则返回在的那个（非空的那个）
        // 若p和q不在root的任一子树上，则left和right均为空，返回nullptr
        return left ? left : right;
    }

};