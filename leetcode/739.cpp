class Solution {
public:
    vector<int> dailyTemperaturesImpl1(const vector<int>& temperatures) 
    {
        vector<int> res(temperatures.size());
        
        for (size_t i = 0; i < temperatures.size(); i++) {
            if (i != 0 && temperatures[i] == temperatures[i-1]) {
                res[i] = res[i-1] == 0 ? 0 : res[i-1]-1;
                continue;
            }
            size_t j = i + 1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                j++;
            }
            if (j == temperatures.size()) {
                res[i] = 0;
            } else {
                res[i] = j - i;
            }
        }

        return res;
    }

    vector<int> dailyTemperaturesImpl2(const vector<int>& temperatures) 
    {
        vector<int> res(temperatures.size());
        stack<size_t> st; // 单调递减栈

        for (size_t i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                size_t idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        return dailyTemperaturesImpl2(temperatures);
    }
};