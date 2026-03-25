
#include <algorithm>

template <typename ForwardIt, typename ValueT>
ForwardIt BinraySearch(ForwardIt first, ForwardIt last, const ValueT& value)
{
    ForwardIt it;
    auto count = std::distance(first, last);

    while (count > 0) {
        it = first;
        auto step = count / 2;
        std::advance(it, step);
        if (*it == value) {
            return it;
        } else if (*it < value) {
            first = std::next(it);
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return last;
}


class Solution {
    int searchStd(vector<int>& nums, int target) 
    {
        namespace ranges = std::ranges;
        auto it = ranges::lower_bound(nums, target);
        // If not found or value is greater than target
        if (it == ranges::end(nums) || *it > target) {
            return -1;
        } else {
            return ranges::distance(nums.cbegin(), it);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        auto it = BinraySearch(nums.begin(), nums.end(), target);
        if (it == nums.end()) {
            return -1;
        } else {
            return std::distance(nums.begin(), it);
        }
    }
};