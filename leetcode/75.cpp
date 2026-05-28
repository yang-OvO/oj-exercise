class Solution {
public:
    void DutchFlagsAlgs(vector<int>& nums)
    {
        if (nums.size() <= 0) {
            return;
        }
        int pivot = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot) {
                swap(nums[i], nums[0]);
                break;
            }
        }
        size_t lt = 0, i = lt + 1, gt = nums.size()-1;
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[lt]);
                i++;
                lt++;
            } else if (nums[i] == pivot) {
                i++;
            } else {
                swap(nums[i], nums[gt]);
                gt--;
            }
        }
    }

    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        DutchFlagsAlgs(nums);
    }
};