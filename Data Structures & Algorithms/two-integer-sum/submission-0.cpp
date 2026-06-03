class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(hash.contains(diff) && hash[diff]!=i) return {i,hash[diff]};
        }
        return {0,0};
    }
};
