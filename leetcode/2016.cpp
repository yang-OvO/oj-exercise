class Solution {
public:
    int maximumDifferenceImpl1(const vector<int>& nums)
    {
        int res = -1;

        const size_t n = nums.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i; j < n; j++) {
                int diff = nums[j] - nums[i];
                if (diff > 0 && res < diff) {
                    res = diff;
                }
            }
        }

        return res;
    }

    int maximumDifferenceImpl2(const vector<int>& nums)
    {
        const size_t n = nums.size();
        int res = -1, premin = nums[0];

        for (size_t i = 1; i < n; i++) {
            if (nums[i] > premin) {
                res = max(res, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }

        return res;
    }

    int maximumDifference(vector<int>& nums)
    {
        return maximumDifferenceImpl2(nums);
    }
};