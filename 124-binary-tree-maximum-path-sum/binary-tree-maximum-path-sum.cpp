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
    int maxPathSum(TreeNode* root) {
    if(root == NULL)
        return 0;
    int maxi = INT_MIN;
    maxSumHelper(root,maxi);
    return maxi;
    }

    int maxSumHelper(TreeNode* root , int &maxi)
    {
        if(root == NULL)
        return 0;
        
        int ls = max(0,maxSumHelper(root->left,maxi));
        int rs = max(0,maxSumHelper(root->right,maxi));
        maxi = max(maxi,ls+rs+root->val);

        return root->val + max(ls,rs);
    }
};