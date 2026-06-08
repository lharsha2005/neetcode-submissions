class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int left=0;
        int right;
        int n=temperatures.size();
        vector<int> ans(n);

        while(left<n-1){
            right=left+1;
            int count=1;
            for(int i=right;i<n;i++){
                if(temperatures[i]>temperatures[left]){
                    printf("%d",count);
                    ans[left]=count;
                    break;
                }
                count++;
            }
            left++;
        }

        return ans;
    }
};
