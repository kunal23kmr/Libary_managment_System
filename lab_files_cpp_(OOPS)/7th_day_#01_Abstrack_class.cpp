/*
Write a program to create an abstract class named SHAPE that contains an empty method named number_of_sides().
Provide three classes named trapezoid,triangle and hexagon such that each one of the class inherits the class shape. Each one of the class
contain only method number of sides() that shows no of sides in given geomertical figure.
*/
#include <iostream>
using namespace std;
class SHAPE
{
public:
    virtual void number_of_sides() = 0;
    virtual void area(float side1, float side2 = 0, float height = 0) = 0;
};
class Trapezoid : public SHAPE
{
public:
    void number_of_sides()
    {
        cout << "This is trapezoid: number of side-04" << endl;
    }
    void area(float side1, float side2, float height)
    {
        cout << "Area of trapezoid is: " << (height * (side1 + side2)) / 2 << endl;
    }
};
class Triangle : public SHAPE
{
public:
    void number_of_sides()
    {
        cout << "This is Triangle: number of side-03" << endl;
    }
    void area(float side1, float side2 = 0, float height = 0)
    {
        cout << "Area of Triangle is: " << (height * side1) / 2 << endl;
    }
};
class Hexagon : public SHAPE
{
public:
    void number_of_sides()
    {
        cout << "This is Hexagon: number of side-06" << endl;
    }
    void area(float side1, float side2 = 0, float height = 0)
    {
        cout << "Area of Hexagon is: " << (side1 * side1) / 2.59807621 << endl;
    }
};
int main()
{
    Trapezoid s1;
    Triangle s2;
    Hexagon s3;
    s1.number_of_sides();
    s1.area(4, 4, 4);
    s2.number_of_sides();
    s2.area(4, 0, 4);
    s3.number_of_sides();
    s3.area(4);
    return 0;
}