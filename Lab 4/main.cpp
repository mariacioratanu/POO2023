#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
    Sort type1("20,45,105,10,60");
    type1.InsertSort();
    type1.Print();

    int v[6]={1,2,3,4,6,8};
    Sort type2(v, 6);
    type2.BubbleSort(true);
    type2.Print();
    cout<<type2.GetElementsCount()<<endl;
    cout<<type2.GetElementFromIndex(2)<<endl;

    Sort type3({5,20,10,30,60,50,40,70});
    type3.QuickSort();
    type3.Print();

    Sort type4(8, -25, 25); //size=8, min=-25, max=25
    type4.QuickSort(true);
    type4.Print();
    cout<<type4.GetElementsCount()<<endl;
    cout<<type4.GetElementFromIndex(4)<<endl;
}
