class Solution {
public:

    // Precondition: 1 <= n <= 12; 1 <= k <= n!
    string getPermutation(int n, int k)
    {
        // 计算阶乘数
        constexpr size_t MAX_N = 12;
        constexpr auto factorial = [](int n) {
            int result = 1;
            for (int i = 2; i <= n; ++i) {
                result *= i;
            }
            return result;
        };
        constexpr auto factorial_table = [&]{
            std::array<int, MAX_N> arr{};
            for (size_t i = 0; i < MAX_N; ++i) {
                arr[i] = factorial(i);
            }
            return arr;
        }();

        string res;
        res.reserve(n);
        bool used[MAX_N+1] = {false};
        // 分解k-1
        k = k-1;
        for (int i = n-1; i >= 0; i--) {
            int ai = k / factorial_table[i] + 1;
            k %= factorial_table[i];
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