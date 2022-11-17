/*
Create two classes DM and DB. DM stores the distance in meters and centemeter and,
DB stores distance in feets and inches.
Write a program to add object of DM with Object of DB class.
*/
#include <iostream>
using namespace std;
class DB;
class DM
{
    int m, c;
public:
    void input()
    {
        cout << "Enter the meassure: " << endl;
        cout << "Meter: ";
        cin >> m;
        cout << "Centemeter: ";
        cin >> c;
    }
    friend void add(DM &d1, DB &d2);
};
class DB
{
    int ft, in;
public:
    void input()
    {
        cout << "Enter the meassure: " << endl;
        cout << "Feet: ";
        cin >> ft;
        cout << "Inche: ";
        cin >> in;
    }
    friend void add(DM &d1, DB &d2);
};
void add(DM &d1, DB &d2)
{
    // in meter
    float meter = 0, centemeter = 0;
    centemeter = ((12 * (d2.ft)) + d2.in) * (2.54);
    meter = (d1.m) + (((int)centemeter) / 100);
    centemeter = (int)centemeter % 100;
    centemeter += d1.c;
    if (centemeter >= 100)
    {
        meter++;
        centemeter -= 100;
    }
    // in feet
    float feet = 0, inche = 0;
    inche = (12 * d2.ft) + d2.in + (d1.c / 2.54) + (d1.m * 100) / 2.54;
    feet = (int)inche / 12;
    inche = inche - 12 * feet;
    cout << endl
         << "Totaol messure:" << endl;
    cout << "Meter: " << meter << "\n Centeemeter: " << centemeter << endl;
    cout << "Feet: " << feet << "\n Inche: " << inche << endl;
}
int main()
{
    DM d1;
    DB d2;
    d1.input();
    d2.input();
    add(d1, d2);
    return 0;
}