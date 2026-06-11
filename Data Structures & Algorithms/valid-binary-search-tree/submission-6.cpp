class Solution {
public:
    unordered_set<int> nums;

    bool dfs(TreeNode *root){
        if(!root) return false;

        bool duplicate = false;

        if(nums.find(root->val) != nums.end())
            duplicate = true;

        nums.insert(root->val);

        return duplicate ||
               dfs(root->left) ||
               dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(dfs(root))
            return false;

        vector<int> values(nums.begin(), nums.end());

        for(int num : values){
            TreeNode *ptr = root;

            while(ptr){
                if(ptr->val == num)
                    break;

                if(ptr->val < num)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }

            if(ptr == nullptr)
                return false;
        }

        return true;
    }
};