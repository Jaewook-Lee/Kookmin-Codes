/************************************************************************
 * Name : 이재욱
 * Student ID : 20181670
 * Program ID : HW #1-2
 * Description : This program is written for assignmnet.
 *               Main purpose is calculating area.
 * Algorithm :
 *     triangle : base * height / 2
 *     rectangle : side1 * side2
 *     circle : 3.14 * radius * radius
 * Variables :
 *     triangle_area : A function for calculating triangle's area.
 *                     It returns triangle's area.
 *     rectangle_area : A function for calculating rectangle's area.
 *                      It returns rectangle's area.
 *     circle_area : A function for calculating circle's area.
 *                   It returns circle's area.
 *     main : Reading informations from file 'lab2.txt'
 *            and print file's content and area.
 * **********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

double triangle_area(double base, double height);
double rectangle_area(double side1, double side2);
double circle_area(double radius);

int main()
{
    double area;

    ifstream reader;
    reader.open("lab2.txt");
    string shape_name;

    while (!reader.eof())
    {
        reader >> shape_name;
        cout << shape_name << " ";

        if (shape_name.compare("triangle") == 0)
        {
            double base, height;
            reader >> base >> height;
            cout << base << " " << height << " ";
            area = triangle_area(base, height);
        }
        else if (shape_name.compare("rectangle") == 0)
        {
            double sideA, sideB;
            reader >> sideA >> sideB;
            cout << sideA << " " << sideB << " ";
            area = rectangle_area(sideA, sideB);
        }
        else if (shape_name.compare("circle") == 0)
        {
            double radius;
            reader >> radius;
            cout << radius << " ";
            area = circle_area(radius);
        }

        cout << area << " \n";
    }

    reader.close();
}

/***********************************************
 * Function : triangle_area
 * description : Calculating triangle's area.
 *               And return result.
 * Variables :
 *     base : The base of triangle.
 *     height : The height of triangle.
 * *********************************************/
double triangle_area(double base, double height)
{
    return (base * height / 2);
}

/***********************************************
 * Function : rectangle_area
 * description : Calculating rectangle's area.
 *               And return result.
 * Variables :
 *     side1, side2 : The sides of rectangle.
 * *********************************************/
double rectangle_area(double side1, double side2)
{
    return (side1 * side2);
}

/***********************************************
 * Function : circle_area
 * description : Calculating circle's area.
 *               And return result.
 * Variables :
 *     PI : A constant value having 3.14.
 *     radius : The circle's radius.
 * *********************************************/
double circle_area(double radius)
{
    const double PI = 3.14;
    return (PI * radius * radius);
}