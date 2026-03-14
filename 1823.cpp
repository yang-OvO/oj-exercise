#include <vector>
using namespace std;

class Solution {
public:
    template <bool clockwise>
    int FindFirstNotOut(int start, vector<int>& out)
    {
        int search_index = 0;
        for (int i = 1; i < out.size(); i++) {
            if constexpr (clockwise) {
                search_index = start + i;
                if (search_index >= out.size()) {
                    search_index -= out.size();
                }
            } else {
                search_index = start - i;
                if (search_index < 0) {
                    search_index += out.size();
                }
            }
            if (out[search_index] == 0) {
                return search_index;
            }
        }

        // 满足前置条件（存在未淘汰的人），则不可能到达这儿
        return -1;
    }

    int FindTheWinnerImpl(int n, int k, 
        int start, int t, vector<int>& out)
    {
        if (t == n) {
            for (int i = 0; i < out.size(); i++) {
                if (out[i] == 0) {
                    // 返回i+1因为小伙伴编号从1开始
                    return i + 1;
                }
            }
        }

        int target_person_index = start;
        for (int i = 0; i < k - 1; i++) {
            target_person_index = FindFirstNotOut<true>(target_person_index, out);
        }
        out[target_person_index] = 1;

        return FindTheWinnerImpl(n, k, 
            FindFirstNotOut<true>(target_person_index, out), t+1, out);
    }

    int findTheWinner(int n, int k) {
        vector<int> out(n, 0);
        return FindTheWinnerImpl(n, k, 0, 1, out);
    }
};