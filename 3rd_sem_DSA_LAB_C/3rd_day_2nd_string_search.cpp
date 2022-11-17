#include <iostream>
using namespace std;
string txt = "", pat = "";
void match()
{
    int a;
    for (int i = 0; i < txt.size(); i++)
    {
        a = 0;
        for (int j = 0; j < pat.size(); j++)
        {
            if (pat[j] == txt[i + j])
                a++;
            else
                break;
        }
        if (a == pat.size())
        {
            cout << "Pattern found at index: " << i << endl;
        }
    }
}
int main()
{
    cout << "Enter the input text: ";
    cin >> txt;
    cout << endl
         << "Enter the search pattern: ";
    cin >> pat;
    match();
    return 0;
}