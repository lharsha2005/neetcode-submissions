class Solution {
public:
    int rob2(vector<int> nums){
        vector<int> ans(nums.size(),0);
        ans[0]=nums[0];
        ans[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            ans[i]=max(nums[i]+ans[i-2],ans[i-1]);
        }

        return ans.back();
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);

        return max(rob2(vector<int>(nums.begin(),nums.end()-1)),rob2(vector<int>(nums.begin()+1,nums.end())));
    }
};
