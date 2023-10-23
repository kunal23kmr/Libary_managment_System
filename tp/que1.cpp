// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// vector<string> fun(vector<string> log)
// {
//     map<string, int> m;
//     int i = 0;
//     for (auto &a : log)
//     {
//         m[a] = i;
//         i++;
//     }
//     vector<pair<int, string>> v;
//     for (auto &it : m)
//     {
//         v.push_back(make_pair(it.second, it.first));
//     }
//     sort(v.begin(), v.end());
//     reverse(v.begin(), v.end());
//     vector<string> ans;
//     for (auto &a : v)
//     {
//         ans.push_back(a.second);
//     }return ans;
// }

// int main()
// {

//     return 0;
// }

// lakshya

int solution(vector<int> &A, int X, int Y)
{
    int n = A.size();
    int mincost = INT_MAX;
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = A[i];
    }
    for (int i = n - Y - 1; i >= 0; i--)
    {
        dp[i] += dp[i + Y];
    }
    int range = n - ((X - 1) * (Y));
    for (int i = 0; i < range; i++)
    {
        if (mincost > dp[i])
        {
            mincost = dp[i];
        }
    }
    return mincost;
}
int main()
{
    vector<int> v = {4, 2, 5, 4, 3, 5, 1, 4, 2, 7};
    cout << solution(v, 3, 2);
}

int fun(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < s2.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            return s1[i];
        }
    }
    return s1.back();
}

return (n * (2 * init + (n - 1) * r)) / 2;
