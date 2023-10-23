#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    string rollnum;
    string cgpa;
};

int main()
{
    bool flag = true;
     ofstream fout;
     fout.open("records.txt", ios::app);

    do  {
        Student s;

        cout << "\nEnter name: ";
        cin >> s.name;
        cout << "Enter Roll Number: ";
        cin >> s.rollnum;
        cout << "Enter CGPA: ";
        cin >> s.cgpa;
        fout << s.name << " " << s.rollnum << " " << s.cgpa << endl;
        cout << "Enter '1' to quit or enter any other number to continue: ";
        int choice;
        cin >> choice;
        if (choice == 1)
            flag = false;
    }
    while (flag);
    fout.close();
    ifstream fin("records.txt");
    string rname;
    cout << "\nEnter name to find:";
    cin >> rname;
    bool found = false;
    while (!fin.eof())
    {
        Student s;
        fin >> s.name >> s.rollnum >> s.cgpa;
        if (s.name == rname)
        {
            cout << s.name << " " << s.rollnum << " " << s.cgpa << endl;
            found = true;
            break;
        }
    }
    fin.close();
    if (found)
    {
        cout << "\nfound!"<<endl;
    }
    else
    {
        cout << "\nNo record";
    }
    fin.open("records.txt");
    vector<Student> students;
    while (!fin.eof())
    {
        Student s;
        fin >> s.name >> s.rollnum >> s.cgpa;
        students.push_back(s);
    }
    int num = students.size();
    int i, j;
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
            if (students.at(j).name > students.at(j + 1).name)
                swap(students.at(j), students.at(j + 1));
    }
    cout<<"Printing the Sorted table: "<<endl;
    fin.close();
    for (auto s : students)
    {
        cout << s.name << " " << s.rollnum << " " << s.cgpa << endl;
    }
    return 0;
}