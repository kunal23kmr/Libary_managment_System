#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class item
{
    char name[40];
    int code;
    float cost;
public:
    void get_data(char *n, int c, float co)
    {
        strcpy(name, n);
        code = c;
        cost = co;
    }
    void display();
};
void item::display()
{
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(40) << name << setw(20) << code;
    cout.unsetf(ios::left);
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    cout.width(15);
    cout << cost << endl;
}

int main()
{
    item a[5];
    a[0].get_data("Tarbo C++", 1001, 250.95);
    a[1].get_data("C primer", 905, 95.7);
    a[2].get_data("algorithm", 1111, 120.5);
    a[3].get_data("principle of electronics", 2220, 150.85);
    a[4].get_data("solution of balagurusamy", 6666, 145.00);
    cout << setw(0) << "Name" << setw(40) << "Code" << setw(30) << "Cost" << endl;
    for (int i = 0; i < 78; i++) cout << "-";
    cout << endl;
    for (int i = 0; i < 5; i++) a[i].display();
    for (int i = 0; i < 78; i++)cout << "-";
    cout << endl<<endl;
    return 0;
}