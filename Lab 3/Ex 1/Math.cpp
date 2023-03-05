#include "Math.h"
#include <iostream>
#include <cstring>
//codul sursa pentru clasa Math
int Math::Add(int a, int b)
{
    return a+b;
}

int Math::Add(int a, int b, int c)
{
    return a+b+c;
}

int Math::Add(double a, double b)
{
    return a+b;
}

int Math::Add(double a, double b, double c)
{
    return a+b+c;
}

int Math::Mul(int a, int b)
{
    return a*b;
}

int Math::Mul(int a, int b, int c)
{
    return a*b*c;
}

int Math::Mul(double a, double b)
{
    return a*b;
}

int Math::Mul(double a, double b, double c)
{
    return a*b*c;
}

int Math::Add(int count, ...)
{
    //count=numărul de numere întregi din lista de variabile
    //...=lista de pointeri intregi
    int suma=0, i, *p=&count;
    for(i=0;i<count;i++)
    {
        p++;
        suma=suma+*p;
    }
    return suma;
    //Functia initializează un pointer p la adresa parametrului de numarare
    //si adauga fiecare numar intreg indicat de pointer la variabila suma
}

char* Math::Add(const char* a, const char* b)
{
    int ok=1, n1, n2;
    if(a==nullptr)
    {
        a="";
        ok=0;
    }
    if(b==nullptr)
    {
        b="";
        ok=0;
    }
    n1=strlen(a);
    n2=strlen(b);
    char* c=new char[n1+n2+1]; //aloca memorie care poate aduna cele doua siruri existente
    strcpy(c, "");
    strcat(c, a);
    strcat(c, b); //concateneaza sirurile a si b

    c[n1+n2+1]='\0';
    if(ok==0) return nullptr; //daca unul dintre siruri este nullptr, se va returna nullptr
    else return c;
}
