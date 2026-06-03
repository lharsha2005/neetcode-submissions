class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prodf(nums.size());
        vector<int> prodr(nums.size());
        vector<int> ans(nums.size());

        prodf[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prodf[i]=prodf[i-1]*nums[i];
        }

        prodr[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            prodr[i]=nums[i]*prodr[i+1];
        }

        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans[i]=prodr[i+1];
            }
            else if(i==nums.size()-1){
                ans[i]=prodf[i-1];
            }
            else{
                ans[i]=prodf[i-1]*prodr[i+1];
            }
        }

        return ans;
    }
};
