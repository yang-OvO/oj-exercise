class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        const int n = nums.size();
        for (int num : nums) {
            int original = (num - 1) % n + 1;  // 获取原始值
            if (nums[original-1] >= 1 && nums[original-1] <= n) {
                nums[original-1] += n;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                res.emplace_back(i+1);
            }
        }

        return res;
    }
};