// // #include <bits/stdc++.h>
// // using namespace std;

// // long min(long ans, long a)
// // {
// //     return ans > a ? ans : a;
// // }
// // long findMinSumSubarray(vector<int> &arr)
// // {
// //     map<int, int> lastSeen;
// //     long minSum = LONG_MAX;
// //     bool f = false;

// //     vector<long> pre;
// //     pre.push_back(0);
// //     for (int i = 0; i < arr.size(); i++)
// //     {
// //         pre.push_back(pre[i] + arr[i]);
// //     }

// //     for (int i = 0; i < arr.size(); ++i)
// //     {
// //         if (lastSeen.find(arr[i]) != lastSeen.end())
// //         {
// //             long sum = pre[i+1]-pre[lastSeen[arr[i]]];
// //             if (sum < minSum)
// //             {
// //                 f = true;
// //                 minSum = sum;
// //             }
// //         }
// //         lastSeen[arr[i]] = i;
// //     }
// //     if (f)
// //     {
// //         return minSum;
// //     }
// //     return -1;
// // }
// // // long solve(vector<int> price)
// // // {
// // //     long ans = 0;
// // //     pair<int, int> a = findMinSumSubarray(price);
// // // }
// // long fun(vector<int> price)
// // {
// //     int i = 0;
// //     int j = -1;
// //     set<int> s;
// //     vector<long> pre;
// //     pre.push_back(0);
// //     for (int i = 0; i < price.size(); i++)
// //     {
// //         pre.push_back(pre[i] + price[i]);
// //     }
// //     long ans = pre.back();
// //     for (int i = 0; i < price.size(); i++)
// //     {
// //         s.insert(price[i]);
// //         if (s.size() < (i - j))
// //         {
// //         }
// //     }
// // }
// // int main()
// // {
// //     int t;
// //     cin >> t;
// //     while (t--)
// //     {
// //     }
// //     return 0;
// // }

// // // pair<int, int> findMinSumSubarray(vector<int> &arr)
// // // {
// // //     unordered_map<int, int> lastSeen;
// // //     int minSum = INT_MAX;
// // //     int start = -1, end = -1;

// // //     for (int i = 0; i < arr.size(); ++i)
// // //     {
// // //         if (lastSeen.find(arr[i]) != lastSeen.end())
// // //         {
// // //             int sum = 0;
// // //             for (int j = lastSeen[arr[i]] + 1; j <= i; ++j)
// // //             {
// // //                 sum += arr[j];
// // //             }
// // //             if (sum < minSum)
// // //             {
// // //                 minSum = sum;
// // //                 start = lastSeen[arr[i]] + 1;
// // //                 end = i;
// // //             }
// // //         }
// // //         lastSeen[arr[i]] = i;
// // //     }

// // //     return {start, end};
// // // }

// // string getLongestRegex(string a, string b, string c)
// // {
// //     if (a.size() != b.size() || a.size() != c.size())
// //     {
// //         return "-1";
// //     }
// //     string ans = "";
// //     bool f = false;
// //     for (int i = 0; i < a.size(); i++)
// //     {
// //         if (c[i] != a[i] && c[i] != b[i])
// //         {
// //             if (a[i] == b[i])
// //             {
// //                 ans = ans + "[" + a[i] + "]";
// //             }
// //             else
// //             {
// //                 ans = ans + "[" + a[i] + b[i] + "]";
// //             }
// //             f = true;
// //         }
// //         else
// //         {
// //             if (a[i] == b[i])
// //             {
// //                 ans = ans + "[" + a[i] + "]";
// //             }
// //             else
// //             {
// //                 ans = ans + "[" + a[i] + b[i] + "]";
// //             }
// //         }
// //     }
// //     if (!f)
// //     {
// //         return "-1";
// //     }
// //     return ans;
// // }
// #include <string>
// #include <bits\stdc++.h>
// using namespace std;

// string getLongestRegex(string a, string b, string c)
// {
//     if (a.size() != b.size() || a.size() != c.size())
//     {
//         return "-1";
//     }
//     string rx = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     string ans = "";
//     string cp = "";
//     bool f = false;
//     for (int i = a.size() - 1; i >= 0; i--)
//     {
//         cp = rx;
//         if (c[i] != a[i] && c[i] != b[i] && f == false)
//         {
//             int pos = c[i] - 'A';
//             cp.erase(pos, 1);
//             f = true;
//         }
//         ans = "[" + cp + "]" + ans;
//     }
//     if (!f)
//     {
//         return "-1";
//     }
//     return ans;
// }
// int main()
// {
//     cout<<getLongestRegex("AERB","ATRC","AGCB")<<endl;
//     return 0;
// }

// // int solve(vector<int> nums, int k)
// // {
// //     int count = 0;
// //     int i = 0;
// //     while (i < nums.size())
// //     {
// //     }
// // }

// vector<int> countElements(std::vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int count = 0;
//     vector<int> ans;
//     for (int i = k; i < n - k; i++)
//     {
//         int start = i - k;
//         int end = i + k;

//         bool nonIncreasing = true;
//         bool nonDecreasing = true;

//         // Check prior 'k' elements for non-increasing order
//         for (int j = i; j > start; j--)
//         {
//             if (nums[j] > nums[j - 1])
//             {
//                 nonIncreasing = false;
//                 break;
//             }
//         }

//         // Check next 'k' elements for non-decreasing order
//         for (int j = i; j < end; j++)
//         {
//             if (nums[j] > nums[j + 1])
//             {
//                 nonDecreasing = false;
//                 break;
//             }
//         }

//         if (nonIncreasing && nonDecreasing)
//         {
//             ans.push_back(i + 1);
//         }
//     }

//     return ans;
// }
#include <iostream>
#include <string>

using namespace std;

bool isConstant(const string &word)
{
    for (char ch : word)
    {
        if (!isupper(ch))
        {
            return false;
        }
    }
    return true;
}

string snakeToCamel(const string &input)
{
    string result;
    bool capitalizeNext = false;
    bool withinBackticks = false;
    string currentWord;
    for (char ch : input)
    {
        if (ch == '`')
        {
            if (withinBackticks)
            {
                if (isConstant(currentWord))
                {
                    result += "`" + currentWord + "`";
                }
                else
                {
                    bool firstWord = true;
                    for (char wordChar : currentWord)
                    {
                        if (wordChar == '_')
                        {
                            capitalizeNext = true;
                        }
                        else if (capitalizeNext)
                        {
                            result += toupper(wordChar);
                            capitalizeNext = false;
                        }
                        else
                        {
                            if (firstWord)
                            {
                                result += tolower(wordChar);
                                firstWord = false;
                            }
                            else
                            {
                                result += wordChar;
                            }
                        }
                    }
                }

                currentWord.clear();
            }
            withinBackticks = !withinBackticks;
            result += ch;
        }
        else if (withinBackticks)
        {
            currentWord += ch;
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

int main()
{
    string inputDocstring = "This is a `function_name OKKK_hai_na CONSTANT` and `VARIABLE_NAME` example.";
    string convertedDocstring = snakeToCamel(inputDocstring);

    cout << convertedDocstring << endl;

    return 0;
}


