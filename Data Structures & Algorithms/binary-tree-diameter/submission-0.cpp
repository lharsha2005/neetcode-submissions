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
    int depth(TreeNode *root){
        if(root==NULL)  return 0;
        if(root->left==NULL && root->right==NULL)   return 1;

        int left=depth(root->left);
        int right=depth(root->right);
        return max(left+1,right+1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        int right=depth(root->right);
        int left=depth(root->left);

        int diameter=left+right;
        return max({diameter,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
    }
};
