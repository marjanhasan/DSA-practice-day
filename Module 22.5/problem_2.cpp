#include <bits/stdc++.h>
using namespace std;
long long n, s;
long long arr[21];
bool check(long long sum, long index)
{
    if (index == n)
    {
        return sum == s;
    }
    bool route1 = check(sum + arr[index], index + 1);
    bool route2 = check(sum - arr[index], index + 1);
    return route1 || route2;
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (check(arr[0], 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
// 15
// 13
// 11
// 9
// 9
// 7
// 5
// YES
// #include <bits/stdc++.h>
// using namespace std;
// bool solve(long long int n, long long int s, long long int a[], long long int sum)
// {
//     if (n == 0)
//     {
//         cout << sum << endl;
//         return s == sum;
//     }
//     return solve(n - 1, s, a, sum + a[n - 1]) || solve(n - 1, s, a, sum - a[n - 1]);
// }
// int main()
// {
//     long long int n, s;
//     cin >> n >> s;
//     long long int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     (solve(n, s, a, 0)) ? cout << "YES" : cout << "NO";
// }