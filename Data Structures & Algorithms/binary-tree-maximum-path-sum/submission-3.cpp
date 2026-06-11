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
    vector<int> maxSum;
    int dfs(TreeNode* root){
        if(!root)   return INT_MIN;

        int left=dfs(root->left);
        int right=dfs(root->right);
        
        int cr=(right!=INT_MIN)?root->val+right:root->val;
        int cl=(left!=INT_MIN)?root->val+left:root->val;;
        int clr=(right!=INT_MIN && left!=INT_MIN)?root->val+right+left:root->val;;

        maxSum.push_back(max({root->val,cl,cr,clr}));

        return max({root->val,cl,cr});
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        int m=INT_MIN;
        for(int n:maxSum){
            printf("%d ",n);
            m=max(m,n);
        }

        return m;
    }
};
