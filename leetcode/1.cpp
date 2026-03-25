class Solution {
public:
    vector<int> getPicked(int index) {
        vector<int> res;    
        int pick = 0;
        for (size_t i = index;i; i >>= 1) {
            if (i & 1) {
                res.push_back(pick);
            }
            pick++;
        }
        return res;
    }

    vector<int> twoSum1(vector<int>& nums, int target)
    {
        vector<int> sum_array(1, 0);
        vector<int> res;
        for (int num : nums) {
            size_t loop_times = sum_array.size();
            for (size_t i = 0; i < loop_times; i++) {
                sum_array.push_back(sum_array[i] + num);
                if (sum_array.back() == target) {
                    auto picked = getPicked(sum_array.size() - 1);
                    if (picked.size() == 2) {
                        res = std::move(picked);
                        goto outer;
                    }
                }
            }
        }

        outer:
        return res;
    }

    vector<int> twoSum2(vector<int>& nums, int target)
    {
        unordered_map<int, size_t> table;
        for (size_t i = 0; i < nums.size(); i++) {
            table.insert({nums[i], i});
        }

        for (size_t i = 0; i < nums.size(); i++) {
            auto itr = table.find(target-nums[i]);
            if (itr != table.end() && itr->second != i) {
                return {(int)itr->second, (int)i};
            }
        }

        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSum1(nums, target);
    }
};