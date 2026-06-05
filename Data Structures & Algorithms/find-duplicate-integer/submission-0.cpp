class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq(nums.size(),0);

        for(int num:nums){
            freq[num-1]+=1;
        }

        for(int i=0;i<freq.size();i++){
            if(freq[i]>1)   return i+1;
        }

        return 0;
    }
};
