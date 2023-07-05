#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    vector<vector<int>> input;
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Interval" << i + 1 << endl;
        int a, b;
        cin >> a >> b;
        input.push_back({a, b});
    }

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (input[i][0] < low)
        {
            low = input[i][0];
        }
        if (input[i][1] > high)
        {
            high = input[i][1];
        }
    }
    vector<int> v(high, -1);
    for (int i = 0; i < n; i++)
    {
        int s = input[i][0];
        int e = input[i][1];

        while (s <= e)
        {
            v[s - 1] = s;
            s++;
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < v.size(); i++)
    {
        while (i < v.size() && v[i] == -1)
        {
            i++;
        }
        if (i < v.size())
        {
            int a = v[i];
            int b;
            while (i < v.size() && v[i] != -1)
            {
                i++;
            }
            if (i < v.size())
            {
                i--;
                b = v[i];
                ans.push_back({a, b});
            }
            else if (i == v.size())
            {
                i--;
                b = v[i];
                ans.push_back({a, b});
            }
        }
    }
    cout << "Ans is:" << endl;
    for (auto a : ans)
    {
        cout << a[0] << "," << a[1] << endl;
    }

    return 0;
}