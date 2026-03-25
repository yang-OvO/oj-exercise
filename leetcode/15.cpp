class Solution {
public:
    vector<vector<int>> threeSumImpl1(const vector<int>& nums)
    {
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        auto v = vector<int>{nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end());
                        s.emplace(move(v));
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (const auto & v: s) {
            res.emplace_back(v);
        }
        return res;
    }

    int MoveUntilDifferent(const vector<int>& nums, int start, bool increment_order)
    {
        int tmp = start;
        if (increment_order) {
            tmp = start + 1;
            for (; tmp < nums.size() && nums[tmp] == nums[start]; tmp++);
        } else {
            tmp = start - 1;
            for (; tmp >= 0 && nums[tmp] == nums[start]; tmp--);
        }
        return tmp;
    }

    vector<vector<int>> threeSumImpl2(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // 跳过重复元素
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumImpl2(nums);
    }
};
