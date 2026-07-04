class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=1;

        while(l<numbers.size()&&(numbers[l]+numbers[r])!=target){
            while(r<numbers.size() && (numbers[l]+numbers[r])<=target){
                if(numbers[l]+numbers[r]==target)   return {l+1,r+1};

                r++;
            }
            l++;
            r=l+1;
        }

        return {l+1,r+1};
    }
};
