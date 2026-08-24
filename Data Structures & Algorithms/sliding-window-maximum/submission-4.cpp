class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        int l=0,r=0;
        while(r<nums.size()){
            while(!q.empty() && nums[r]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[r]);

            if(r>=(k-1)){
                ans.push_back(q.front());
                if(q.front()==nums[l]){
                    q.pop_front();
                }
                l++;
            }

            r++;
        }

        return ans;
    }
};
