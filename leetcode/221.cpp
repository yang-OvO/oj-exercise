class Solution {
public:
    bool IsSquareAllOne(const vector<vector<char>>& matrix, size_t start_r, size_t start_c, size_t edge_len)
    {
        for (size_t i = start_r; i < start_r+edge_len; i++) {
            for (size_t j = start_c; j < start_c+edge_len; j++) {
                if (matrix[i][j] == '0') {
                    return false;
                }
            }
        }
        return true;
    }

    int maximalSquareImpl1(const vector<vector<char>>& matrix)
    {
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        size_t edge_len = min(m, n);

        while (edge_len > 0) {
            for (size_t i = 0; i <= m - edge_len; i++) {
                for (size_t j = 0; j <= n - edge_len; j++) {
                    if (IsSquareAllOne(matrix, i, j, edge_len)) {
                        return static_cast<int>(edge_len*edge_len);
                    }
                }
            }
            edge_len--;
        }
        return 0;
    }

    int maximalSquareImpl2(const vector<vector<char>>& matrix)
    {
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                res = dp[i][j] > res ? dp[i][j] : res;
            }
        }

        return res*res;
    }

    int maximalSquare(vector<vector<char>>& matrix)
    {
        return maximalSquareImpl2(matrix);
    }
};