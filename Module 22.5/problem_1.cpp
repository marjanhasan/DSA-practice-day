#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int solve(int n, int m, int w[], int v[])
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
        return dp[n][m];
    if (w[n - 1] <= m)
    {
        return dp[n][m] = max(solve(n - 1, m - w[n - 1], w, v) + v[n - 1], solve(n - 1, m, w, v));
    }
    else
        return dp[n][m] = solve(n - 1, m, w, v);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int w[n], v[n];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << solve(n, m, w, v);
    return 0;
}
