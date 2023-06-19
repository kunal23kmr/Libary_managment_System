#include <iostream>
using namespace std;

class triangle
{
    int side1, side2, side3;

public:
    void makeTriangle(int a, int b, int c)
    {
        side1 = a;
        side2 = b;
        side3 = c;
    }

    void display()
    {
        cout << "Sides of triangle is: " << side1 << " " << side2 << " " << side3 << endl;
    }

    void isEquilatral()
    {
        if (side1 == side2 && side1 == side3)
        {
            cout << "It is a equilatral triangle." << endl;
        }
    }

    void isIsosceles()
    {
        if (side1 == side2 || side1 == side3 || side2 == side3)
        {
            cout << "It is a isosceles triangle." << endl;
        }
    }

    void isRightangle()
    {
        if (side1 == max(side1, max(side2, side3)))
        {

            if ((side1 * side1) == (side2 * side2 + side3 * side3))
            {
                cout << "Is a rightangle." << endl;
            }
        }
        else if (side2 == max(side1, max(side2, side3)))
        {

            if ((side2 * side2) == (side1 * side1 + side3 * side3))
            {
                cout << "Is a rightangle." << endl;
            }
        }

        else if (side3 == max(side1, max(side2, side3)))
        {

            if ((side3 * side3) == (side2 * side2 + side1 * side1))
            {
                cout << "Is a rightangle." << endl;
            }
        }
    }
};

int main()
{
    triangle T;
    T.makeTriangle(5, 4, 3);
    T.display();
    T.isRightangle();

    return 0;
}