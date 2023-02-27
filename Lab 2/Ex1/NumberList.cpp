#include <iostream>
#include "NumberList.h"
using namespace std;
void NumberList::Init()
{
    count=0;
}

bool NumberList::Add(int x)
{
    if (count>=10) return false;
    v[count++]=x; //adauga valoarea lui x si creste count-ul
    return true;
}

void NumberList::Sort()
{
    int i, j;
    for(i=0;i<count-1;i++)
        for(j=i+1;j<count;j++)
        {
            if(v[i]>v[j])
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
}

void NumberList::Print()
{
    int i;
    for(i=0;i<count;i++)
        cout<<v[i]<<" ";

    cout<<endl;
}
