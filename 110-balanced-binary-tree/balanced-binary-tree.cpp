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
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // Base case: Null node
        int left = maxDepth(root->left);  // Calculate left subtree depth
        int right = maxDepth(root->right); // Calculate right subtree depth
        return max(left, right) + 1; // Return the maximum depth + 1 for current node
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true; // Base case: Null node
        int left = maxDepth(root->left);  // Calculate left subtree depth
        int right = maxDepth(root->right); // Calculate right subtree depth
        if (abs(left - right) > 1) return false; // Unbalanced if depth difference > 1
        bool l = isBalanced(root->left);  // Check left subtree balance
        bool r = isBalanced(root->right); // Check right subtree balance
        return l && r; // Return true if both subtrees are balanced
    }
};