class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size(), dp[n + 1][n + 1];
        string t = s;
        reverse(t.begin(), t.end());
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[n][n];
    }
};