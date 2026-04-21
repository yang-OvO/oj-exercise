class Solution {

    int minArraySumImplDP(const vector<int>& nums, int k, int op1, int op2)
    {
        const size_t dim_op1 = op1+1;
        const size_t dim_op2 = op2+1;
        vector<int> dp(dim_op1*dim_op2, 0);
        auto calc_key = [=] (int op1_index, int op2_index) {
            return op1_index * dim_op2 + op2_index;
        };

        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            for (int op1_index = op1; op1_index >= 0; op1_index--) {
                for (int op2_index = op2; op2_index >= 0; op2_index--) {
                    int best = dp[calc_key(op1_index, op2_index)];
                    if (op1_index > 0) {
                        int saving = 0;
                        if (nums[i] >= 0) {
                            saving = nums[i] / 2;
                        } else {
                            saving = (nums[i] - 1) / 2;
                        }
                        best = max(best, saving + dp[calc_key(op1_index-1, op2_index)]);
                    }
                    if (op2_index > 0 && nums[i] >= k) {
                        int saving = k;
                        best = max(best, saving + dp[calc_key(op1_index, op2_index-1)]);
                    }
                    if (op1_index > 0 && op2_index > 0) {
                        if ((nums[i] + 1) / 2 >= k) {
                            int saving = nums[i] - ((nums[i] + 1) / 2 - k);
                            best = max(best, saving + dp[calc_key(op1_index-1, op2_index-1)]);
                        }
                        if (nums[i] >= k) {
                            int saving = nums[i] - ((nums[i] - k + 1) / 2);
                            best = max(best, saving + dp[calc_key(op1_index-1, op2_index-1)]);
                        }
                    }
                    dp[calc_key(op1_index, op2_index)] = best;
                }
            }
        }

        return dp[calc_key(op1, op2)];
    }

    class CachedResult
    {
        const int dim_nums_;
        const int dim_op1_;
        const int dim_op2_;
        vector<int> cache_;
    public:
        static constexpr int SENTINEL = numeric_limits<int>::min() / 4;
        CachedResult(int nums_size, int op1, int op2) :
            dim_nums_(nums_size), dim_op1_(op1+1), dim_op2_(op2+1),
            cache_(dim_nums_*dim_op1_*dim_op2_, SENTINEL)
        {
        }

        int Retrive(int cur, int a, int b) const
        {
            if (cur >= dim_nums_ || (a == 0 && b == 0)) {
                return 0;
            }
            size_t key = cur * dim_op1_ * dim_op2_ + a * dim_op2_ + b;
            return cache_[key];
        }

        void Store(int cur, int a, int b, int result)
        {
            size_t key = cur * dim_op1_ * dim_op2_ + a * dim_op2_ + b;
            cache_[key] = result;
        }
    };

    int minArraySumMemorizedSearchImpl(int cur, int a, int b,
        const vector<int>& nums, int k, CachedResult& memo)
    {
        int cached_result = memo.Retrive(cur, a, b);
        if (cached_result != CachedResult::SENTINEL) {
            return cached_result;
        }

        // 不做操作
        int res = memo.Retrive(cur+1, a, b);
        if (res == CachedResult::SENTINEL) {
            res = minArraySumMemorizedSearchImpl(cur+1, a, b, nums, k, memo);
        }
        // 做op1一次
        if (a > 0) {
            int saving = 0;
            if (nums[cur] >= 0) {
                saving = nums[cur] / 2;
            } else {
                saving = (nums[cur] - 1) / 2;
            }
            int sub_res = saving;
            int shortcut = memo.Retrive(cur+1, a-1, b);
            if (shortcut != CachedResult::SENTINEL) {
                sub_res += shortcut;
            } else {
                sub_res += minArraySumMemorizedSearchImpl(cur+1, a-1, b, nums, k, memo);
            }
            res = max(res, sub_res);
        }
        // 做op2一次
        if (b > 0 && nums[cur] >= k) {
            int saving = k;
            int sub_res = saving;
            int shortcut = memo.Retrive(cur+1, a, b-1);
            if (shortcut != CachedResult::SENTINEL) {
                sub_res += shortcut;
            } else {
                sub_res += minArraySumMemorizedSearchImpl(cur+1, a, b-1, nums, k, memo);
            }
            res = max(res, sub_res);
        }
        if (a > 0 && b > 0) {
            if ((nums[cur] + 1) / 2 >= k) {
                int saving = nums[cur] - ((nums[cur] + 1) / 2 - k);
                int sub_res = saving;
                int shortcut = memo.Retrive(cur+1, a-1, b-1);
                if (shortcut != CachedResult::SENTINEL) {
                    sub_res += shortcut;
                } else {
                    sub_res += minArraySumMemorizedSearchImpl(cur+1, a-1, b-1, nums, k, memo);
                }
                res = max(res, sub_res);
            }
            if (nums[cur] >= k) {
                int saving = nums[cur] - ((nums[cur] - k + 1) / 2);
                int sub_res = saving;
                int shortcut = memo.Retrive(cur+1, a-1, b-1);
                if (shortcut != CachedResult::SENTINEL) {
                    sub_res += shortcut;
                } else {
                    sub_res += minArraySumMemorizedSearchImpl(cur+1, a-1, b-1, nums, k, memo);
                }
                res = max(res, sub_res);
            }
        }
        memo.Store(cur, a, b, res);
        return res;
    }

    int minArraySumMemorizedSearch(const vector<int>& nums, int k, int op1, int op2)
    {
        CachedResult memo(nums.size(), op1, op2);
        return accumulate(nums.begin(), nums.end(), 0) - minArraySumMemorizedSearchImpl(0, op1, op2, nums, k, memo);
    }

public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) 
    {
        // return accumulate(nums.begin(), nums.end(), 0) - minArraySumImplDP(nums, k, op1, op2);
        return minArraySumMemorizedSearch(nums, k, op1, op2);
    }
};
