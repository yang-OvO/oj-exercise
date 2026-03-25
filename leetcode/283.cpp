class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // 将nums[p]设置为该数值
                nums[p] = nums[i];
                p++;
            }
        }
        for (; p < nums.size(); p++) {
            nums[p] = 0;
        }
    }
};
