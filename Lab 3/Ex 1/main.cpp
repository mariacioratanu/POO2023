#include <iostream>
#include "Math.h"

using namespace std;
int main()
{
    Math op=Math();
    cout<<op.Add(5, 6)<<endl;
    cout<<op.Add(3, 4, 5)<<endl;
    cout<<op.Add(7.5, 8.5)<<endl;
    cout<<op.Add(6.5, 7.5, 8.5)<<endl;
    cout<<op.Mul(1, 2)<<endl;
    cout<<op.Mul(1, 2, 3)<<endl;
    cout<<op.Mul(4.5, 5.5)<<endl;
    cout<<op.Mul(7.5, 8.5, 9.5)<<endl;
    cout<<op.Add(1, 3, 6, 2, 9, 7, 3)<<endl;
    cout<<op.Add("buna", "ziua")<<endl;
    cout<<op.Add(nullptr, nullptr)<<endl;
    cout<<op.Add(nullptr, "ziua")<<endl;
    cout<<op.Add("buna", nullptr)<<endl;
    return 0;
}
