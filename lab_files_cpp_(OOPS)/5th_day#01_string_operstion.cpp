/*Write a class STRING that can be used to store string, add string, equate strings, output strings.
 */
#include <iostream>
using namespace std;
class StringClass
{
    int n;
    string line;

public:
    StringClass(string s)
    {
        n = s.size();
        this->line = s;
        int lenghtOfString = line.size();
        this->display();
        cout << "Size of the string is: " << line.size() << endl;
    }
    void add(StringClass &stringToAdd)
    {
        string l1 = this->line, l2 = stringToAdd.line;
        l1 = l1 + l2;
        cout << "The added string is: " + l1 << endl;
    }
    void equate(StringClass &stringToCompare)
    {
        if (this->line.size() != stringToCompare.line.size())
        {
            if (this->line.size() > stringToCompare.line.size())
                cout << "The string S1 is greater than S2." << endl;
            else
                cout << "The string S2 is greater than S1." << endl;
            return;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < line.size(); i++)
            {
                if (this->line[i] == stringToCompare.line[i])
                    flag++;
                else
                    return;
            }
            if (flag == this->line.size())
                cout << "The string is same." << endl;
            else
                cout << "both string are diffrent." << endl;
        }
    }
    void display()
    {
        cout << "The string is:- " + line << endl;
    }
};
int main()
{
    string line1, line2;
    cout << "Enter the string  1st: ";
    cin >> line1;
    StringClass s1(line1);
    cout << "Enter the string 2nd: ";
    cin >> line2;
    StringClass s2(line2);
    s1.add(s2);
    s1.equate(s2);
    return 0;
}