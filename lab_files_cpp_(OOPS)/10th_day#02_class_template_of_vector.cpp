#include <iostream>
#include <vector>
using namespace std;

template <typename t>
class Nakli_vector
{
    vector<t> v;
    t temp;

public:
    Nakli_vector(int number_of_elements)
    {
        cout << "Enter the elements: ";
        for (int i = 0; i < number_of_elements; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
    }
    t modify_karunga(int index)
    {
        if (index < v.size())
        {
            cout << "Enetr the new value: ";
            cin >> temp;
            v[index] = temp;
        }
    }
    t multiply_karun_ga(int x)
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i] = x * v[i];
        }
    }
    void display_kar_dunga()
    {
        cout << "(" << v[0];
        for (int i = 1; i < v.size(); i++)
        {
            cout << "," << v[i];
        }
        cout << ")" << endl;
    }
};

int main()
{
    // a
    cout << "Dis is a:" << endl;
    Nakli_vector<int> a(3);
    a.modify_karunga(2);
    cout << "printing modified value:";
    a.display_kar_dunga();
    a.multiply_karun_ga(10);
    cout << "printing multiplied value:";
    a.display_kar_dunga();

    // b
    cout << "\nThis is b: " << endl;
    Nakli_vector<float> b(3);
    b.modify_karunga(1);
    cout << "printing modified value:";
    b.display_kar_dunga();
    b.multiply_karun_ga(3);
    cout << "printing multiplied value:";
    b.display_kar_dunga();

    
    return 0;
}