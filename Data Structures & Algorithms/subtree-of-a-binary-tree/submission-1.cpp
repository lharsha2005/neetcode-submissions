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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q)    return true;
        if(!p || !q)    return false;

        bool same=(p->val==q->val)?true:false;

        return (same && isSame(p->left,q->left) && isSame(q->right,p->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)   return false;
        bool same;
        if(root->val==subRoot->val){
            same=isSame(root,subRoot);
        }
        return (same || isSubtree(root->left,subRoot)|| isSubtree(root->right,subRoot));
    }
};
