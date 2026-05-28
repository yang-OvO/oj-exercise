iclass Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        // 找反向递增的序列 [inc_lower_boun, r]
        size_t inc_lower_bound = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                inc_lower_bound = (size_t)i+1;
                break;
            }
        }
        if (inc_lower_bound == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // 那么一定存在比nums[inc_lower_bound-1]要大的元素
            size_t first_bigger_idx = 0;
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > nums[inc_lower_bound-1]) {
                    first_bigger_idx = (size_t)i;
                    break;
                }
            }
            swap(nums[inc_lower_bound-1], nums[first_bigger_idx]);
            reverse(nums.begin()+inc_lower_bound, nums.end());
        }
    }
};
