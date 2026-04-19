class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        deque<char> q;
        for (auto c : s) {
            auto itr = find(q.begin(), q.end(), c);
            if (itr != q.end()) {
                q.erase(q.begin(), next(itr));
            }
            q.push_back(c);
            res = q.size() > res ? q.size() : res;
        }
        return res;
    }
};
