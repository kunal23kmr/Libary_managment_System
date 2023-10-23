#include<iostream>
#include<vector>
using namespace std;

vector<int> fun(int num)
{
    vector<int> factors;
    for (int i = 1; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            factors.push_back(i);
            if (i != num / i)
                factors.push_back(num / i);
        }
    }
    return factors;
}
bool check(int k, vector<int> &v, vector<int> &pre)
{
    int a = (v.size() / k);
    for (int i = 0; i < a; i++)
        for (int j = 1; j < k; j++)
            if ((v[(i * a) + j] - v[(i * a) + j - 1]) != pre[j - 1])
                return false;
    return true;
}
int solve(vector<int> &v)
{
    vector<int> factor;
    factor = fun(v.size());
    vector<int> pre;
    for (int i = 1; i < v.size(); i++)
        pre.push_back(v[i] - v[i - 1]);
    for (int i = factor.size() - 1; i >= 0; i--)
        if (check(factor[i], v, pre))
            return factor[i];
    return -1;
}
int maxRhythmlength(int N, int A[])
{
    vector<int> v(A, A + N);
    int ans = solve(v);
    if (ans == 1 || ans==N)
    {
        return -1;
    }
    return ans;
}
// vector<int>v(A,A+N);
// int ans = solve(v);
// if(ans==1){
//     return -1;
// }
// return ans;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (auto &x : a)
//     {
//         cin >> x;
//     }
//     cout << solve(a);

//     return 0;
// }