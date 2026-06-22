class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        // 找反向递增的序列 [inc_lower_bound, r]
        size_t inc_lower_bound = nums.size()-1;
        while (inc_lower_bound > 0 &&
                nums[inc_lower_bound-1] >= nums[inc_lower_bound]) {
            inc_lower_bound--;
        }
        if (inc_lower_bound == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // 那么一定存在比nums[inc_lower_bound-1]要大的元素
            size_t first_bigger_idx = nums.size()-1;
            while (nums[first_bigger_idx] <= nums[inc_lower_bound-1]) {
                first_bigger_idx--;
            }
            swap(nums[inc_lower_bound-1], nums[first_bigger_idx]);
            reverse(nums.begin()+inc_lower_bound, nums.end());
        }
    }
};
