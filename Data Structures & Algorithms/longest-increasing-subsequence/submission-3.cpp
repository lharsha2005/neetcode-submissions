class Solution {
public:
    vector<int> dp;

    int dfs(int i, vector<int>& nums) {
        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = 1;  // nums[i] itself

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                ans = max(ans, 1 + dfs(j, nums));
            }
        }

        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, nums));
        }

        return ans;
    }
};