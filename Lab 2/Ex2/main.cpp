#include "StudentProperties.h"
#include "FunctiiGlobale.h"
#include <iostream>
using namespace std;

int main()
{
    Student student1 = Student();
    Student student2 = Student();

    //setam notele si numele pentru fiecare dintre cei doi studenti
    student1.setNume("Maria");
    student1.setNotaMate(10);
    student1.setNotaEngleza(8);
    student1.setNotaIstorie(6);

    student2.setNume("Ioana");
    student2.setNotaMate(9);
    student2.setNotaEngleza(7);
    student2.setNotaIstorie(5);

    cout<<"Note istorie: "<<endl;
    cout<<student1.getName()<<" : "<<student1.getNotaIstorie()<<endl;
    cout<<student2.getName()<<" : "<<student2.getNotaIstorie()<<endl<<endl;
    cout<<"Note engleza: "<<endl;
    cout<<student1.getNume()<<" : "<<student1.getNotaEngleza()<<endl;
    cout<<student2.getName()<<" : "<<student2.getNotaEngleza()<<endl<<endl;
    cout<"Notele la matematica: "<<endl;
    cout<<student1.getNume()<<" "<<student1.getNotaMate()<<endl;
    cout<<student2.getNume()<< " : "<<student2.getNotaMate()<<endl<<endl;
    cout<<"Nota finala: "<<endl;
    cout<<student1.getNume()<<" : "<<student1.getNotaFinala()<<endl;
    cout<<student2.getNume()<<" : "<<student2.getNotaFinala()<<endl<<endl;
    cout<<"Compara numele: "<<comparaNume(student1, student2)<<endl<<endl;
    cout<<"Compara rezultate mate: "<<comparaNotaMate(student1, student2)<<endl<<endl;
    cout<<"Compara rezultate engleza: "<<comparaNotaEngleza(student1, student2)<<endl<<endl;
    cout<<"Compara rezultate istorie: "<<comparaNotaIstorie(student1, student2)<<endl<<endl;
    cout<<"Compara rezultate finale: "<<comparaNotaFinala(student1, student2)<<endl<<endl;

    return 0;
}
