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
    int dfs(TreeNode *root,int maxNo){
        if(!root)   return 0;

        int left=dfs(root->left,max(maxNo,root->val));
        int right=dfs(root->right,max(maxNo,root->val));

        if(root->val>=maxNo){
            return (left+right+1);
        }else{
            return (left+right);
        }
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
