#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include<algorithm>
using namespace std;

int fun(int arr[], int n, int m, int i, vector<vector<int>> &dp)
{ // i->index, m= remaing number of box
    if (m <= 0)
    {
        return 0;
    }
    if (i == n)
    {
        return 99999;
    }
    if(dp[i][m]!= -1){
        return dp[i][m];
    }
    int include = arr[i] + fun(arr, n, m - pow(2, i), i , dp);
    int exclude = fun(arr, n, m, i + 1, dp);

    // cout << i << " " << m << " " << include << " " <<exclude<< endl;

    return  dp[i][m] = min(include,exclude);
    // return min(include, exclude);
}

int birthdayPresent(int arr[], int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return fun(arr, n, m, 0, dp);
}
int main()
{
    vector<int>v;
    v={1,2,3,34,7};
    cout<<(*max_element(v.begin(),v.end()));
}