class Solution {
public:
    // Precondition: 1 <= k <= n!
    string getPermutation(int n, int k)
    {
        constexpr size_t MAX_N = 9;
        // 1至MAX_N-1的阶乘
        const int factorial[MAX_N] = {
            1, 1, 2, 6, 24, 120,
            720, 5040, 40320};

        string res;
        res.reserve(n);
        bool used[MAX_N+1] = {false};
        // 分解k-1
        k = k-1;
        for (int i = n-1; i >= 0; i--) {
            int ai = k / factorial[i] + 1;
            k %= factorial[i];
            size_t fill_num = 0;
            while (fill_num <= MAX_N && ai) {
                fill_num++;
                if (!used[fill_num]) {
                    ai--;
                }
            }
            used[fill_num] = true;
            res += '0' + fill_num;
        }

        return res;
    }
};