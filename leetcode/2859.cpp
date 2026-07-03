class Solution {
public:
    // Precondition: nums.length >= 1, k >= 0
    int sumIndicesWithKSetBits(vector<int>& nums, int k)
    {
        if (k == 0) {
            return nums[0];
        }
        int res = 0;
        vector<int> dp(nums.size(), 0);

        for (size_t i = 1; i < nums.size(); i++) {
            dp[i] = dp[i&(i-1)] + 1;
            if (dp[i] == k) {
                res += nums[i];
            }
        }

        return res;
    }
};
