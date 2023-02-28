#include "StudentProperties.h"
#include <cstring>
#include <iostream>

using namespace std;
//metodele care stabiesc proprietatile unui student

void Student::setNume(const char* nume)
{
    if(strlen(nume)<=50) //setam ca numele sa aiba maxim 50 de caractere
        strcpy(this->nume, nume);
    else
        cout<<"Numele este prea lung.";
}
const char* Student::getNume() const {
    return this->nume;
}

void Student::setNotaMate(float nota)
{
    if(nota>= 1 && nota<=10) //nota poate lua valori doar intre 1 si 10
        this->notaMate=nota;
    else
        cout<<"Nota trebuie sa fie intre 1 si 10.";
}
float Student::getNotaMate() const {
    return this->notaMate;
}

void Student::setNotaEngleza(float nota) {
    if (nota>= 1 && nota<= 10) //nota poate lua valori doar intre 1 si 10
        this->notaEngleza=nota;
    else
        cout<<"Nota trebuie sa fie intre 1 si 10.";
}
float Student::getNotaEngleza() const {
    return this->notaEngleza;
}

void Student::setNotaIstorie(float nota) {
    if (nota>= 1 && nota<= 10) //nota poate lua valori doar intre 1 si 10
        this->notaIstorie=nota;
    else
        cout<<"Nota trebuie sa fie intre 1 si 10.";
}
float Student::getNotaIstorie() const {
    return this->notaIstorie;
}

float Student::getNotaFinala() const {
    return (notaMate + notaEngleza + notaIstorie)/3; //se calculeaza media aritmetica a celor trei note, pentru a stabili nota finala a studentului
}
