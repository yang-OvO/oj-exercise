class Solution {
public:
    int findKOr(vector<int>& nums, int k)
    {
        unsigned res = 0;

        for (size_t i = 0; i < 32; i++) {
            int cnt = 0;
            for (unsigned num : nums) {
                if (num & (1u << i)) {
                    cnt++;
                }
            }
            if (cnt >= k) {
                res |= (1u << i);
            }
        }

        return res;
    }
};
