//program to read the name and roll number of students, from 
//keyboard and write them into a file then display it.

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("lab-12-01.txt");
    fout << "Name     Roll Number" << endl;
    fout << "====================" << endl;
    int n = 0, roll;
    string name;
    cout << "Enter number of students:";
    cin >> n;
    cout << "Enter name and roll numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> name >> roll;
        fout << name << "       " << roll << endl;
    }
    fout.close();
    cout << "Displaying list..\n\n";
    ifstream fin("lab-12-01.txt");
    string s;
    while (fin)
    {
        getline(fin, s);
        cout << s << endl;
    }
    return 0;
}