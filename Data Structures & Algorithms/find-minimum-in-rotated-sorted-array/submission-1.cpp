class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int mid;
        int ans=INT_MAX;

        while(l<=r){
            mid=(l+r)/2;
            printf("%d ",nums[mid]);
            ans=min(ans,nums[mid]);
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return ans;
    }
};
