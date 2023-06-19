// Write a program to modify name in a student file for a
// particular roll number.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("student_record.txt");
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    int roll;
    string name;
    cout << "Enter roll number and name: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> roll >> name;
        fout << roll << "        " << name << endl;
    }
    fout.close();

    ifstream fin("student_record.txt");
    ofstream newFout("new_list.txt");

    int checkroll;
    cout << "Enter the roll number to modify: ";
    cin >> checkroll;
    fin >> roll >> name;

    while (fin)
    {
        if (roll == checkroll)
        {
            cout << "Enter the new name: ";
            cin >> name;
            cout << "Updated Successfully...\n";
        }
        newFout << roll << "        " << name << endl;
        fin >> roll >> name;
    }
    fin.close();
    newFout.close();

    remove("student_record.txt");
    rename("new_list.txt", "student_record.txt");
    fstream printfile("student_record.txt");

    cout << "Printing the new list\n";
    printfile >> roll >> name;
    while (printfile)
    {
        cout << roll << "       " << name << endl;
        printfile >> roll >> name;
    }
    printfile.close();

    return 0;
}