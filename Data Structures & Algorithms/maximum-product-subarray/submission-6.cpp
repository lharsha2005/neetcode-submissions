class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int curMax = nums[0];
        int curMin = nums[0];

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            int newMax = max({
                x,
                x * curMax,
                x * curMin
            });

            int newMin = min({
                x,
                x * curMax,
                x * curMin
            });

            curMax = newMax;
            curMin = newMin;

            ans = max(ans, curMax);
        }

        return ans;
    }
};