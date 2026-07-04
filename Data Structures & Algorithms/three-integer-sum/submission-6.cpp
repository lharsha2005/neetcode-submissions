class Solution {
public:
    bool check(vector<vector<int>> &ans, vector<int> &v) {
        for (auto &x : ans) {
            if (x == v)
                return true;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int i = 0;

        while (i < nums.size() - 2) {
            int target = -nums[i];

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int curr = nums[l] + nums[r];

                if (curr > target) {
                    r--;
                }
                else if (curr < target) {
                    l++;
                }
                else {
                    vector<int> v = {nums[i], nums[l], nums[r]};

                    if (!check(ans, v))
                        ans.push_back(v);

                    l++;
                    r--;
                }
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
            i++;
        }

        return ans;
    }
};