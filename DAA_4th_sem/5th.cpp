#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll> &a, int s, int e, vector<vector<ll>> &dp)
{
    if (s == e)
    {
        return 0;
    }
    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }
    ll mini = LLONG_MAX;
    for (int k = s; k < e; k++)
    {
        mini = min(mini, solve(a, s, k, dp) + solve(a, k + 1, e, dp) + a[s - 1] * a[k] * a[e]);
    }
    return dp[s][e] = mini;
}
int main()
{
    int t;
    cout << "No of test case : ";
    cin >> t;
    while (t--)
    {
        ll n;
        cout << "No of matrix u want to enter : ";
        cin >> n;
        vector<ll> a(n);
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
        cout << "Sizes of each matrix are : " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "The minimum number of multiplications are obtained : ";
        cout << solve(a, 1, n - 1, dp) << endl;
    }
    return 0;
}
