class Solution
{
public:
    int dp[1000 + 5][1000 + 5];
    int solve(string a, int n, string b, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (a[n - 1] == b[m - 1])
        {
            return dp[n][m] = solve(a, n - 1, b, m - 1) + 1;
        }
        else
        {
            return dp[n][m] = max(solve(a, n - 1, b, m), solve(a, n, b, m - 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = -1;
            }
        }
        return solve(text1, n, text2, m);
    }
};