#include <iostream>
#include <cstring>
using namespace std;

int stringToNumber(char number[])
{
    int suma = 0, i, n;
    n=strlen(number);
    for (i = 0; i < n; i++)
        suma = suma * 10 + number[i] - '0';
    return suma;
}

void newline(char sir[])
{
    int i, n;
    n=strlen(sir);
    for (int i = 0; i < n; i++)
        if (sir[i] == '\n')
        {
            sir[i] = '\0';
            return;
        }
    return;
}

int main() {
    FILE* fptr;
    char data[100];
    int suma = 0;

    if ((fptr = fopen("in.txt", "r")) == NULL)
    {
        printf("Eroare la deschiderea fisierului.");
        exit(1);
    }

    while (fgets(data, 100, fptr) != NULL)
    {
        newline(data);
        suma=suma+stringToNumber(data);
    }
    printf("%d", suma);
    fclose(fptr);
}
