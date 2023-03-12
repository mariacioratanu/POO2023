#include "Sort.h"
#include <cstring>
#include <iostream>
#include <cstdarg> //for va_end, va_start
using namespace std;

int Sort::partition(int low, int high, bool ascending)
{
    int pivot=low+rand()%(high-low);
    swap(v[low], v[pivot]);
    int i=low+1,j=high;
    while(i<=j)
    {
        if(ascending!=0 && v[i]<=v[low] || ascending==0 && v[i]>=v[low])
            i++;
        if(ascending!=0 && v[j]>=v[low] || ascending==0 && v[j]<=v[low])
            j--;
        if(i<j && (ascending!=0 && v[i]>v[low] && v[j]<v[low] || ascending==0 && v[i]<v[low] && v[j]>v[low]))
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    swap(v[i-1], v[low]);
    return i-1;
}

Sort::Sort(int size, int min, int max) : size(size)
{
    int i;
    this->v=new int[size];
    for(i=0;i<size;i++)
        this->v[i]=min+1+rand()%(max-min-1);
}

Sort::Sort(std::initializer_list<int> list)
{
    int i;
    this->size=list.size();
    this->v=new int[list.size()];
    initializer_list<int>::iterator it=list.begin();
    for(i=0;i<list.size();i++)
    {
        this->v[i]=*it;
        it++;
    }
}

Sort::Sort(const int* v, int size):size(size)
{
    int i;
    this->v=new int[size];
    for(i=0;i<size;i++)
        this->v[i]=v[i];
}

Sort::Sort(int size, ...):size(size)
{
    int i;
    this->v=new int[size];
    va_list args;
    va_start(args, size);
    for(i=0;i<size;i++)
        this->v[i]=va_arg(args, int);
    va_end(args);
}

Sort::Sort(const char* string) : size(0)
{
    int i, n=strlen(string);
    for(i=0;i<n;i++)
        if(string[i]==',')
            this->size++;
    if(n>0)
        this->size++;
    this->v=new int[this->size];
    char* buffer=new char[n+1];
    strcpy(buffer, string);
    int index=0;
    const char* number=strtok(buffer, ",");
    while(number!=nullptr)
    {
        this->v[index++]=atoi(number);
        number=strtok(nullptr, ",");
    }
    delete[] buffer;
}

void Sort::InsertSort(bool ascendent)
{
    int i;
    for(i=1;i<this->size;i++)
    {
        int j=i-1;
        int temp=v[i];
        while(ascendent!=0 && j>=0 && v[j]>temp)
        {
            v[j+1]=v[j];
            j--;
        }
        while(ascendent==0 && j>=0 && v[j]<temp)
        {
            v[j+1]=v[j];
            j--;
        }
        if(temp!=v[j+1])
            v[j+1]=temp;
    }
}

void Sort::quickSort(int low, int high, bool ascending)
{
    if(low<high)
    {
        int k=this->partition(low, high, ascending);
        this->quick_sort(low, k-1, ascending);
        this->quick_sort(k+1, high, ascending);
    }
}

void Sort::QuickSort(bool ascendent)
{
    this->quickSort(0, this->size-1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int i, last=this->size-1;
    while(last>0)
    {
        int n=last;
        last=0;
        for(i=0; i<n; i++)
        {
            if(ascendent!=0 && v[i]>v[i+1] || ascendent==0 && v[i]<v[i+1])
            {
                swap(v[i], v[i+1]);
                last=i;
            }
        }
    }
}

void Sort::Print()
{
    int i;
    for(i=0;i<this->size;i++)
        cout<<(this->v[i])<<' ';
    cout<<endl;
}

int Sort::GetElementsCount()
{
    return this->size;
}

int Sort::GetElementFromIndex(int index)
{
    if(index>=0 && index<this->size)
        return this->v[index];
}
