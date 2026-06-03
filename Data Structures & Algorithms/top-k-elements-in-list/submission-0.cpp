class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        while(k!=0){
            int m=0;
            int n=nums[0];
            for(auto its:freq){
                if(its.second>m){
                    m=its.second;
                    n=its.first;
                }
            }
            ans.push_back(n);
            freq[n]=0;
            k--;
        }

        return ans;
    }
};
