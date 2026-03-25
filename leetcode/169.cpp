class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement2(nums);
    }

    int majorityElement1(vector<int>& nums) {
        std::unordered_map<int, int> m;

        int bound = nums.size() / 2;
        int ret = 0;
        for (int num : nums) {
            if (m.count(num) == 0) {
                m[num] = 1;
            } else {
                m[num]++;
            }
        }

        for (const auto& [k,v] : m) {
            if (v > bound) {
                ret = k;
                break;
            }
        }
        return ret;
    }

    int majorityElement2(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += candidate == num? 1 : -1;
        }
        return candidate;
    }
};
