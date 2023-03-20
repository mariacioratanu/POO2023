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

    std::cout<<"Note istorie: "<<endl;
    std::cout<<student1.getName()<<" are nota: "<<student1.getNotaIstorie()<<endl;
    std::cout<<student2.getName()<<" are nota: "<<student2.getNotaIstorie()<<endl<<endl;
    std::cout<<"Note engleza: "<<endl;
    std::cout<<student1.getNume()<<" are nota: "<<student1.getNotaEngleza()<<endl;
    std::cout<<student2.getName()<<" are nota: "<<student2.getNotaEngleza()<<endl<<endl;
    std::cout<"Notele la matematica: "<<endl;
    std::cout<<student1.getNume()<<" are nota:"<<student1.getNotaMate()<<endl;
    std::cout<<student2.getNume()<< " are nota: "<<student2.getNotaMate()<<endl<<endl;
    std::cout<<"Nota finala: "<<endl;
    std::cout<<student1.getNume()<<" are nota: "<<student1.getNotaFinala()<<endl;
    std::cout<<student2.getNume()<<" are nota: "<<student2.getNotaFinala()<<endl<<endl;
    std::cout<<"Compara numele: "<<comparaNume(student1, student2)<<endl<<endl;
    std::cout<<"Compara rezultate mate: "<<comparaNotaMate(student1, student2)<<endl<<endl;
    std::cout<<"Compara rezultate engleza: "<<comparaNotaEngleza(student1, student2)<<endl<<endl;
    std::cout<<"Compara rezultate istorie: "<<comparaNotaIstorie(student1, student2)<<endl<<endl;
    std::cout<<"Compara rezultate finale: "<<comparaNotaFinala(student1, student2)<<endl<<endl;

    return 0;
}
