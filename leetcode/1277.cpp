class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                res += dp[i][j];
            }
        }

        return res;
    }
};