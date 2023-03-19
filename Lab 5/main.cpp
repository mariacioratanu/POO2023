#include <iostream>
#include "Number.h"
using namespace std;

int main()
{
    Number a("10110010", 2); //a is in base 2
    Number b("734", 8); //b is in base 8
    Number c("FF", 16); //c is in base 16
    Number d=12345; //d is in base 10

    cout<<"a has "<<a.GetDigitsCount()<<" digits and it is written in base "<<a.GetBase()<<endl;
    int i;
    for(i=0; i<a.GetDigitsCount(); i++)
            cout<<"a["<<i<<"]="<<a[i]<<endl; //printing each digit and its index
    a.Print(); //10110010
    b.Print(); //734
    a=(b+c-a)+a; //after this a will be in base 16 (a=2DB)
    b.SwitchBase(2); //b=111011100
    a.Print();
    b.Print();
    if(a>b)
        cout<<"a is bigger than b"<<endl;
    else
        cout<<"b is bigger than a"<<endl;

    a=255; //a will be 11111111 (value 255 from base 10 in base 2)
    d=d+a;
    d.Print(); //12600
    d="13579"; //d mentains its base (10) and will be 13579
    d.Print();
    --d; //the first digit from d will be removed ==> d becomes 3579
    d.Print(); //3579
    d--; //the last digit from d will be removed ==> d becomes 357
    d.Print(); //357

    return 0;
}
