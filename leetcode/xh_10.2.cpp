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
    
    void JosephCircleImpl(vector<int>& people, int k, 
        int start, int t, vector<int>& out, vector<int>& result)
    {
        int current_people_number = people.size() - t + 1;
        if (current_people_number == 1) {
            for (int i = 0; i < out.size(); i++) {
                if (out[i] == 0) {
                    result.emplace_back(people[i]);
                }
            }
            return;
        }

        // 寻找下一个目标人
        int target_person_index = start;
        for (int i = 0; i < k-1; i++) {
            target_person_index = FindFirstNotOut<true>(target_person_index, out);
        }
        out[target_person_index] = 1;
        result.emplace_back(people[target_person_index]);

        JosephCircleImpl(people, k, 
            FindFirstNotOut<true>(target_person_index, out), t+1, out, result);
    }

    vector<int> Joseph_circle(vector<int>& people, int k) {
        vector<int> out(people.size(), 0);
        vector<int> result;
        JosephCircleImpl(people, k, 0, 1, out, result);
        return result;
    }
};