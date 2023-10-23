// #include <iostream>
// #include <string>
// #include <map>

// using namespace std;

// void solve(int n, int m, int *b[m], Result &result) // Pass result by reference
// {
//     map<pair<int, int>, int> mp;
//     pair<int, int> p;
    
//     for (int i = 0; i < m; i++)
//     {
//         int a = b[i][0];
//         for (int j = 1; j <= n; j++)
//         {
//             p.first = a;
//             p.second = j;
            
//             if (p.first > p.second)
//             {
//                 swap(p.first, p.second);
//                 mp[p] -= b[i][j];
//             }
//             else
//             {
//                 mp[p] += b[i][j];
//             }
//         }
//     }
    
//     int i = 0;
//     for (auto it : mp)
//     {
//         string str = "";
//         if (it.second > 0)
//         {
//             str = to_string(it.first.second) + "->" + to_string(it.first.first) + "=" + to_string(it.second);
//         }
//         else if (it.second < 0)
//         {
//             str = to_string(it.first.first) + "->" + to_string(it.first.second) + "=" + to_string(abs(it.second));
//         }
//         result.output1[i] = str;
//         i++;
//     }
// }
// struct Result
// {
//     string output1[100]; // Changed to a fixed-size array to avoid dynamic allocation
// };


// struct Result minTransactions(int N, int M, int **b)
// {
//     Result a;
//     solve(N, M, b, a); // Pass a by reference to populate it
//     return a;
// }

// int main()
// {
//     int b[5][4] = {
//         {1, 0, 10, 20},
//         {2, 10, 0, 5},
//         {2, 5, 0, 5},
//         {3, 20, 10, 0},
//         {2, 10, 0, 10}
//     };
//     Result a = minTransactions(3, 3, b);

//     // Print the results
//     for (int i = 0; !a.output1[i].empty(); i++)
//     {
//         cout << a.output1[i] << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <map>

using namespace std;

string *solve(int n, int m, int **b)
{
    map<pair<int, int>, int> mp;
    pair<int, int> p;
    for (int i = 0; i < m; i++)
    {
        int a = b[i][0];
        for (int j = 1; j <= n; j++)
        {
            p.first = a;
            p.second = j;
            if (p.first > p.second)
            {
                swap(p.first, p.second);
                mp[p] -= b[i][j];
            }
            else
            {
                mp[p] += b[i][j];
            }
        }
    }
    string *word = new string[100];
    int i = 0;
    for (auto it : mp)
    {
        string str = "";
        if (it.second > 0)
        {
            str = to_string(it.first.second) + "->" + to_string(it.first.first) + "=" + to_string(it.second);
        }
        else if (it.second < 0)
        {
            str = to_string(it.first.first) + "->" + to_string(it.first.second) + "=" + to_string(abs(it.second));
        }
        word[i] = str;
        i++;
    }
    return word;
}

struct Result
{
    string *output1 = new string[100];
};

struct Result minTransactions(int N, int M, int **b)
{
    Result a;
    a.output1 = solve(N, M, b);
    return a;
}
int main()
{
    Result a;
    int b[5][4] = {
        {1,0,10,20},
        {2,10,0,5},
        {2,5,0,5},
        {3,20,10,0},
        {2,10,0,10}
    };
    a = minTransactions(3, 3, b);

    return 0;
}
