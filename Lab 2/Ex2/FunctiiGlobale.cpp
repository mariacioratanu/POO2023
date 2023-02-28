#include "FuntiiGlobale.h"
#include "StudentProperties.h"
#include <cstring>

//compara cei doi studenti(numele, notele la fiecare materie si media finala)
//daca studentii sunt egali se returneaza 0, daca primul este mai mare se returneaza 1, iar in caz contrar, -1

int comparaNume(const Student& student1, const Student& student2) //compar numele studentilor folosind functia strcmp
{
    int rezultat = strcmp(student1.getNume(), student2.getNume());
    if (rezultat==0)
        return 0;
    else if (rezultat<0)
        return -1;
    return 1;
}

int comparaNotaMate(const Student& student1, const Student& student2)
{
    if (student1.getNotaMate() == student2.getNotaMate())
        return 0;
    else if (student1.getNotaMate() > student2.getNotaMate())
        return 1;
    else
        return -1;
}

int comparaNotaEngleza(const Student& student1, const Student& student2) 
{
    if (student1.getNotaEngleza() == student2.getNotaEngleza())
        return 0;
    else if (student1.getNotaEngleza() > student2.getNotaEngleza())
        return 1;
    else
        return -1;
}

int comparaNotaIstorie(const Student& student1, const Student& student2) 
{
    if (student1.getNotaIstorie() == student2.getNotaIstorie())
        return 0;
    else if (student1.getNotaIstorie() > student2.getNotaIstorie())
        return 1;
    else
        return -1;
}

int compareNotaFinala(const Student& student1, const Student& student2) 
{
    if (student1.getNotaFinala() == student2.getNotaFinala())
        return 0;
    else if (student1.getNotaFinala() > student2.getNotaFinala())
        return 1;
    else
        return -1;
}
