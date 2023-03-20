#include <iostream>
#include "Math.h"

using namespace std;
int main()
{
    Math op=Math();
    std::cout<<op.Add(5, 6)<<endl;
    std::cout<<op.Add(3, 4, 5)<<endl;
    std::cout<<op.Add(7.5, 8.5)<<endl;
    std::cout<<op.Add(6.5, 7.5, 8.5)<<endl;
    std::cout<<op.Mul(1, 2)<<endl;
    std::cout<<op.Mul(1, 2, 3)<<endl;
    std::cout<<op.Mul(4.5, 5.5)<<endl;
    std::cout<<op.Mul(7.5, 8.5, 9.5)<<endl;
    std::cout<<op.Add(4, 1, 2, 3, 4)<<endl;
    std::cout<<op.Add("buna", "ziua")<<endl;
    std::cout<<op.Add(nullptr, nullptr)<<endl;
    std::cout<<op.Add(nullptr, "ziua")<<endl;
    std::cout<<op.Add("buna", nullptr)<<endl;
    return 0;
}
