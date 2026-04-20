class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	// 每次处理完字符s[i]后，
	// 队列中保存的恰好是以s[i]结尾的最长无重复子串。
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
