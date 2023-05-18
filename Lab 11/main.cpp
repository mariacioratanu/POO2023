#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//Partea I:scrierea

//Algoritmul de sortare scris de mine, care conține cele 5 erori
//Selection sort templetizat
//(am adaugat comentariile dupa ce l-am trimis colegei mele)
template<typename T>
void selectionSortCuErori(vector<T>& elements)
{
    int n=elements.size();
    int i, j;
    for(i=0; i<=n-1; i++) //Eroare 1: Am folosit i<=n-1 în loc de i<n-1
    {
        int minIndex=i-1; //Eroare 2: Am folosit i-1 în loc de i
        for(j=i; j<n; j++) //Eroare 3: Am folosit j=i în loc de j=i+1
        {
            if(elements[j]>elements[minIndex]) //Eroare 4: Am folosit elements[j]>elements[minIndex] în loc de elements[j]<elements[minIndex]
            {
                minIndex=j+1; //Eroare 5: Am folosit j+1 în loc de j
            }
        }
        if (minIndex!=i)
            swap(elements[j], elements[i]);
    }
}

//Aceeași funcție de Selection Sort, doar că fără erori
template<typename T>
vector<T> selectionSortCorect(vector<T>& elements)
{
    int n=elements.size();
    int i, j;
    for(i=0; i<n-1; i++)
    {
        int minIndex=i;
        for(j=i+1; j<n; j++)
        {
            if(elements[j]<elements[minIndex])
            {
                minIndex=j;
            }
        }
        if (minIndex!=i)
            swap(elements[i], elements[minIndex]);
    }
}


//Partea a IIa:testarea

//Algoritmul scris de colega mea, cu cele 5 erori incluse:
//InsertionSort
template<typename T>
void insertionSortCuErori(vector<T>& elements)
{
    int n=elements.size(), i, j;
    for(i=1; i<n; i++)
    {
        T key=elements[i];
        j=i+1;
        while(j>=0 && elements[j]<key)
        {
            elements[j]=elements[j-1];
            j=j+1;
        }
        elements[j]=key;
    }
}

//Algoritmul ei corectat de mine, dupa testare:
template<typename T>
void insertionSortCorect(vector<T>& elements)
{
    int n=elements.size(), i, j;
    for(i=1; i<n; i++)
    {
        T key=elements[i];
        j=i-1;
        while(j>=0 && elements[j]>key)
        {
            elements[j+1]=elements[j];
            j=j-1;
        }
        elements[j+1]=key;
    }
}


//Partea de testare a algoritmului si identificarea erorilor:
int main()
{

    // Vectorul de numere pentru testare
    vector<int> numbers={5, 2, 7, 1, 9, 12, 4, 10, 11, 6};
    vector<int> numbersCopy=numbers; // Copie a vectorului inițial

    //Insertion Sort cu erori
    insertionSortCuErori(numbers);
    cout<<"Insertion Sort cu erori: ";
    for (const auto& num : numbers)
        cout<<num<<" ";
    cout<<endl;

    //Insertion Sort corect
    insertionSortCorect(numbersCopy);
    cout<<"Insertion Sort corect: ";
    for(const auto& num : numbersCopy)
        cout<<num<<" ";
    cout<<endl;

    //Verificari & cautare erori
    int n=numbers.size(), i, j;
    //Testam daca vectorul este sortat crescator
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            assert(numbers[i]<=numbers[j] && "nu este crescator");
    cout<<"Vectorul este sortat crescator."<<endl;

    //Testam daca vectorul are elemente distincte
    for(i=0; i<n-1; i++)
        assert(numbers[i]!=numbers[i+1] && "nu sunt distincte");
    cout<<"Vectorul are elemente distincte."<<endl;

    //Verifica daca vectorul este identic cu rezultatul corect
    assert(numbers == vector<int>({1, 2, 4, 5, 6, 7, 9, 10, 11, 12}));

    //Alte erori care pot fi relevante
    assert(numbers[0]<numbers[1]); //Eroarea 1: Verifică dacă primul element este mai mic decât al doilea element
    assert(numbers[0]==numbers[1]); // Eroarea 2: Verifică dacă primul element este egal cu al doilea element
    assert(numbers[0]<numbers[2]); // Eroarea 3: Verifică dacă primul element este mai mic decât al treilea element
    assert(numbers[0]==numbers[3]); // Eroarea 4: Verifică dacă primul element este egal cu al patrulea element
    assert(numbers.size()==10); // Eroarea 5: Verifică dacă dimensiunea vectorului este egală cu 5

    cout<<"Toate testele au fost trecute cu succes!"<<endl;

    return 0;
}
