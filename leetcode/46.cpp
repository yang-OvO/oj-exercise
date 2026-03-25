#include <algorithm>

class Solution {
    vector<vector<int>> permuteStd(vector<int>& nums)
    {
        std::ranges::sort(nums);
        vector<vector<int>> res;
        do
        {
            res.push_back(nums);
        } while (std::ranges::next_permutation(nums).found);
        return res;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteStd(nums);
    }
};