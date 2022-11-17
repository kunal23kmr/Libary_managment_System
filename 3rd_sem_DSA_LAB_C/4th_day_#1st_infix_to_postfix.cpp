#include <iostream>
#include <vector>
using namespace std;
vector<char> v;
string s1, s2 = "";
int prefrence(char a)
{
    if (a == '^')                           return 3;
    else if (a == '*' || a == '/')          return 2;
    else if (a == '+' || a == '-')          return 1;
    return 0;
}
void out(char a)
{
    if (a == ')' || a == '}' || a == ']')
    {
        while (1)
        {
            if (v.back() == '(' || v.back() == '{' || v.back() == '[')
            {
                v.pop_back();
                return;
            }
            else
            {
                s2 += v.back();
                v.pop_back();
            }
        }
    }
    else
    {
        while (1)
        {
            if ((prefrence(v.back()) >= prefrence(a)))
            {
                s2 += v.back();
                v.pop_back();
            }
            else if ((prefrence(v.back()) < prefrence(a)))
            {
                v.push_back(a);
                return;
            }
            else
                return;
        }
    }
}
void input(char a)
{
    if (v.empty())
    {
        v.push_back(a);
    }
    else if (prefrence(a) > v.back())
    {
        v.push_back(a);
    }
    else
        out(a);
    return;
}
int main()
{
    int a = 0;
    cout << "Input the expression: ";
    cin >> s1;
    for (int i = 0; i < s1.size(); i++)
    {
        if ((s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= 'a' && s1[i] <= 'z'))            s2 += s1[i]; 
        else
        {
            if (s1[i] == '(' || s1[i] == '{' || s1[i] == '[')             v.push_back(s1[i]);
            else if (s1[i] == '^' || s1[i] == '*' || s1[i] == '/' || s1[i] == '+' || s1[i] == '-')   input(s1[i]);          
            else if (s1[i] == ')' || s1[i] == '}' || s1[i] == ']')                out(s1[i]);            
            else                cout << "Invalid" << endl;
        }
        while ((i == s1.size() - 1) && !v.empty())
        {
            s2 += v.back();
            v.pop_back();
        }
    }
    cout << "The postfix expression is: " << s2;
    return 0;
}