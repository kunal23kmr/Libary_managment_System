// Program to copy one file into the end of another ,adding line number.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifile("file-1.txt");
    ifstream appfile("file-2.txt");
    cout << "\n\nPrinting file-1" << endl;
    string s;
    while (ifile)
    {
        getline(ifile, s);
        cout << s << endl;
    }
    cout << "Printing file-2\n";
    while (appfile)
    {
        getline(appfile, s);
        cout << s << endl;
    }

    ifile.close();
    appfile.close();

    ifstream file1("file-1.txt");
    fstream file2("file-2.txt", ios::app);

    while (file1)
    {
        getline(file1, s);
        file2 << s << endl;
    }
    cout << "\nPrinting appended file-1 with file-2:\n\n";
    file2.close();

    ifstream file("file-2.txt");
    while (file)
    {
        getline(file, s);
        cout << s << endl;
    }
    file.close();
    return 0;
}