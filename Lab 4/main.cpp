#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
    //examples on how to use the class Sort:
    
    Sort type1("20,45,105,10,60");
    type1.InsertSort(); //sorted: 105, 60, 45, 20, 10
    type1.Print();

    int v[6]={1,2,3,4,6,8};
    Sort type2(v, 6);
    type2.BubbleSort(true); //sorted: 1, 2, 3, 4, 6, 8
    type2.Print();
    std::cout<<type2.GetElementsCount()<<endl; //number of elements: 6
    std::cout<<type2.GetElementFromIndex(2)<<endl; //element from index 2: 3

    Sort type3({5,20,10,30,60,50,40,70}); 
    type3.QuickSort(); //sorted: 70, 60, 50, 40, 30, 20, 10, 5
    type3.Print(); 

    Sort type4(8, -25, 25); //size=8, min=-25, max=25
    type4.QuickSort(true); //sorted: -18, -17, -12, -12, -11, -5, -3, 20
    type4.Print();
    std::cout<<type4.GetElementsCount()<<endl; //number of elements: 8
    std::cout<<type4.GetElementFromIndex(4)<<endl; //element from index 4:-11
}
