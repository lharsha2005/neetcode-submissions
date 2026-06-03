class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int num: nums){
            hash[num]++;
        }

        for(auto its: hash){
            if(its.second>1) return true;
        }

        return false;
    }
};