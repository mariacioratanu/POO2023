#include "NumberList.h"

int main()
{
    NumberList list = NumberList();
    //adaugam numere in vector, afisam de fiecare data vectorul curent si la final sortam vectorul
    list.Init();
    list.Add(12);
    list.Print();
    list.Add(13);
    list.Print();
    list.Add(14);
    list.Print();
    list.Add(15);
    list.Print();
    list.Sort();
    list.Print();

}
