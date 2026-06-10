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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *right=NULL;
            int len=q.size();

            for(int i=0;i<len;i++){
                TreeNode *ptr=q.front();
                q.pop();
                if(ptr){
                    right=ptr;
                    q.push(ptr->left);
                    q.push(ptr->right);
                }
            }

            if(right){
                ans.push_back(right->val);
            }
        }

        return ans;
    }
};
