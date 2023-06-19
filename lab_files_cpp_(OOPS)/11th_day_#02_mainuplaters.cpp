
#include <iostream>
#include <iomanip>
using namespace std;
void manipulators()
{
    cout << setw(10) << "Hello" << endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout << setw(15) << setprecision(2) << 2.5555 << endl;
    cout << setiosflags(ios::showpos);
    cout << 123 << "\n";
    cout << hex << 100 << endl;
    cout << setfill('*') << setw(10) << 2343.0;
}
int main()
{
    manipulators();
    return 0;
}
