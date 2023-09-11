//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int dp[1005][1005];
int solve(int n, int s, int v[], int w[])
{
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        return dp[n][s] = max(solve(n, s - w[n - 1], v, w) + v[n - 1], solve(n - 1, s, v, w));
    }
    else
    {
        return dp[n][s] = solve(n - 1, s, v, w);
    }
}
class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                dp[i][j] = -1;
            }
        }
        return solve(N, W, val, wt);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends