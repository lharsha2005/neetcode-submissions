class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=(l+r)/2;
            printf("%d ",nums[mid]);
            if(nums[mid]==target)   return mid;

            if(nums[l]<nums[r]){
                if(target<nums[mid]){
                    r=mid-1;
                }
                else if(target>nums[mid]){
                    l=mid+1;
                }
                continue;
            }

            if(nums[mid]>nums[r]){
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(nums[mid]<target && target<=nums[r]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }

        return -1;
    }
};
