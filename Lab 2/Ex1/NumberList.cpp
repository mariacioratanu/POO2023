#include <iostream>
#include "NumberList.h"
using namespace std;
void NumberList::Init()
{
    count=0;
}

bool NumberList::Add(int x)
{
    if (count>=10) return false; //daca countul este mai mare sau egal cu 10, se va returna false
    v[count++]=x; //adauga valoarea lui x si creste count-ul
    return true;
}

void NumberList::Sort() //sortarea a doi vectori
{
    int i, j;
    for(i=0;i<count-1;i++)
        for(j=i+1;j<count;j++)
        {
            if(v[i]>v[j])
            {
                int aux=v[i]; //utilizarea unei variabile auxiliare pentru sortare
                v[i]=v[j];
                v[j]=aux;
            }
        }
}

void NumberList::Print() //afisarea vectorului curent
{
    int i;
    for(i=0;i<count;i++)
        cout<<v[i]<<" ";

    cout<<endl;
}
