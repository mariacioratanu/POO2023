#include <iostream>
#include "Canvas.h"

using namespace std;
int main()
{
    //exemplu de utilizare a clasei Canvas
    Canvas myspace=Canvas(60, 60);

    myspace.DrawCircle(15, 15, 10, '$');
    myspace.FillCircle(15, 15, 10, '$');
    myspace.DrawRect(45, 10, 55, 30, '$');
    myspace.FillRect(45, 10, 55, 30, '$');
    myspace.SetPoint(3, 4, '@');
    myspace.DrawLine(25, 28, 30, 34, '.');
    myspace.Print();
    myspace.Clear();
}
