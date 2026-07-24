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
    bool rec(TreeNode* root, int min, int max) {
        if (root == NULL)
            return true;
        
        return rec(root->left, min, root->val) 
            && min < root->val && root->val < max
            && rec(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return rec(root, INT_MIN, INT_MAX);
    }
};
