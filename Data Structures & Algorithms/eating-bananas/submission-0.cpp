class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=INT_MAX;
        int l=1;
        int r=0;
       
        for(int n:piles){
            r=max(r,n);
        }

        while(l<=r){
            int k=(l+r)/2;

            int time=0;
            
            for(int n:piles){
                time+=ceil((double)n/k);
            }

            if(time<=h){
                r=k-1;
                ans=min(ans,k);
            }
            else if(time>h){
                l=k+1;
            }
        }

        return ans;
    }
};