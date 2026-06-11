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
    int kth;
    int num;

    void dfs(TreeNode *root){
        if(!root)   return;
        dfs(root->left);
        if(kth==1)    num=root->val;
        kth--;
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        kth=k;
        dfs(root);
        return num;
    }
};
